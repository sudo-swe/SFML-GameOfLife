
#include "models/Board.hpp"
#include "models/Cell.hpp"
#include "DEFINITIONS.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

namespace GameOfLife {
    Board::Board(int rows, int columns)
        : rows(rows) , columns(columns)
    {
        this->grid.resize(this->rows);
        for(int i=0; i<this->rows; i++) this->grid[i].resize(this->columns);

    }

    int Board::GetRows(){
        return this->rows;
    }

    int Board::GetColumns(){
        return this->columns;
    }

    long Board::GetGenerations(){
        return this->generations;
    }

    Cell &Board::GetCellAt(int row, int column){
        return this->grid[row][column];
    }

    void Board::Update(){
        for(int i=0; i<this->rows; i++){
            for(int j=0; j<this->columns; j++){
                this->GetCellAt(i, j).Update();
            }
        }
    }

    int Board::GetNumOfLiveNeighbors(int row, int column) {
        std::vector<std::pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, 
            {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };

        int count = 0;
        for (auto& dir : directions) {
            int newX = row + dir.first;
            int newY = column + dir.second;

            if (newX >= 0 && newX < this->rows && newY >= 0 && newY < this->columns) {
                if (this->GetCellAt(newX, newY).IsAlive()) {
                    count++;
                }
            }
        }
        return count;
    }

    void Board::ProcessGeneration(){
        for(int i=0; i<this->rows; i++){
            for(int j=0; j<this->columns; j++){
                Cell &cell = this->GetCellAt(i, j);
                int liveNeighbors = this->GetNumOfLiveNeighbors(i, j);
                
                if(cell.IsAlive()){
                    if(liveNeighbors < 2 || liveNeighbors > 3){
                        cell.SetCellState(Cell::ALIVE_TO_DEAD);
                    }
                } else if (liveNeighbors == 3){
                    cell.SetCellState(Cell::DEAD_TO_ALIVE);
                }
            }
        }
        this->generations++;
    }

    void Board::ToggleCellAt(sf::Vector2f mousePos){
        for(int i=0; i<this->rows; i++){
            for(int j=0; j<this->columns; j++){
                Cell &cell = this->GetCellAt(i, j);
                sf::FloatRect cellRect = cell.GetDrawableCell().getGlobalBounds();
                cellRect.width -= 2*CELL_OUTLINE_THICKNESS; 
                cellRect.height -= 2*CELL_OUTLINE_THICKNESS;
                if(cellRect.contains(mousePos)){
                    if(cell.IsAlive()) cell.SetCellState(Cell::DEAD);
                    else cell.SetCellState(Cell::ALIVE);
                }
            }
        }
    }

    void Board::LoadRandomBoard(){
        srand(static_cast<unsigned>(time(0)));
        for(int i=0; i<this->rows; i++){
            for(int j=0; j<this->columns; j++){
                if(rand()%2==0) this->grid[i][j] = Cell(i, j);
                else this->grid[i][j] = Cell(i, j, Cell::ALIVE);
            }
        }
    } 

    bool Board::LoadPresetBoard(std::string presetPath){
        std::ifstream inFile(presetPath);
        if(inFile.is_open()){
            char ch; int i=0, j=0;
            while(inFile.get(ch)){
                if(ch == '*'){this->grid[i][j] = Cell(i, j); j++;}
                else if(ch == '.'){this->grid[i][j] = Cell(i, j, Cell::ALIVE); j++;}
                else if(ch == '\n'){i++; j=0;}
            }
            inFile.close();
            return true;
        } 
        return false;
    }
}
