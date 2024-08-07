
#include "models/Board.hpp"
#include "models/Cell.hpp"
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

    void Board::ToggleCellAt(sf::Vector2f mousePos){
        for(int i=0; i<this->rows; i++){
            for(int j=0; j<this->columns; j++){
                Cell &cell = this->GetCellAt(i, j);
                if(cell.GetDrawableCell().getGlobalBounds().contains(mousePos)){
                    if(cell.IsAlive()) cell.SetCellState(Cell::ALIVE_TO_DEAD);
                    else cell.SetCellState(Cell::DEAD_TO_ALIVE);
                }
            }
        }
    }
}
