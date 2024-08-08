
#include "models/Board.hpp"
#include "models/Cell.hpp"
#include "DEFINITIONS.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <vector>

namespace GameOfLife {
    Board::Board(int rows, int columns)
        : rows(rows) , columns(columns)
    {
        this->grid.resize(this->rows);
        for(int i=0; i<this->rows; i++){
            this->grid[i].resize(this->columns);
            for(int j=0; j<this->columns; j++){
                this->grid[i][j] = Cell(i, j); 
            }
        }
    }

    int Board::GetRows(){
        return this->rows;
    }

    int Board::GetColumns(){
        return this->columns;
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

    int Board::GetNumOfLiveNeighbors(int row, int column){
        std::vector<std::pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
        {0, 1},{1, -1}, {1, 0}, {1, 1}};
        
        int count = 0;
        for (auto& dir : directions) {
            int newX = row + dir.first;
            int newY = column + dir.second;

            if (row + dir.first >= 0 
                    && row + dir.first < this->rows 
                    && column + dir.second >= 0 
                    && column + dir.second < this->columns) {
                if(this->GetCellAt(row + dir.first, column + dir.second).IsAlive()) count++;
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
                    if(liveNeighbors<2) cell.SetCellState(Cell::ALIVE_TO_DEAD);
                    else if(liveNeighbors>3) cell.SetCellState(Cell::ALIVE_TO_DEAD);
                } else if (liveNeighbors == 3){
                    cell.SetCellState(Cell::DEAD_TO_ALIVE);
                }
            }
        }

        this->Update();
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
}
