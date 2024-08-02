#include "models/Cell.hpp"

namespace GameOfLife {
    Cell::Cell(int row, int column, CellState state){
        this->row = row;
        this->column = column;
        this->state = state;
    }

    void Cell::SetCellState(CellState state){
        this->state = state;
    }

    bool Cell::IsAlive(){
        return this->state==ALIVE || this->state==ALIVE_TO_DEAD;
    }

    bool Cell::WillDie(){
        return this->state==DEAD || this->state==ALIVE_TO_DEAD;
    }

    bool Cell::WillLive(){
        return this->state==ALIVE || this->state==DEAD_TO_ALIVE;
    }
}
