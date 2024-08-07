#include "models/Cell.hpp"
#include "DEFINITIONS.hpp"

namespace GameOfLife {
    Cell::Cell(int row, int column, CellState state)
        : row(row), column(column), state(state)
    {
        this->drawableCell.setSize(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT));
        this->drawableCell.setOutlineThickness(CELL_OUTLINE_THICKNESS);
        this->drawableCell.setOutlineColor(CELL_OUTLINE_COLOR);
        this->UpdateColor();
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

    sf::RectangleShape &Cell::GetDrawableCell(){
        return this->drawableCell;
    }

    void Cell::Update(){
        this->UpdateState();
        this->UpdateColor();
    }

    void Cell::UpdateState(){
        if(this->state == ALIVE || this->state == DEAD_TO_ALIVE) this->state = ALIVE;
        else this->state = DEAD;
    }

    void Cell::UpdateColor(){
        if(this->state == ALIVE){
            this->drawableCell.setFillColor(CELL_ALIVE_FILL_COLOR);
        } else if (this->state == DEAD){
            this->drawableCell.setFillColor(CELL_DEAD_FILL_COLOR);
        }
    }
}
