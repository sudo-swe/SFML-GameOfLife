#include "models/Board.hpp"
#include "models/Cell.hpp"
#include <vector>

namespace GameOfLife {
    Board::Board(int rows, int columns){
        this->rows = rows;
        this->columns = columns;
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
}
