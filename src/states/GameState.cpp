#include "states/GameState.hpp"
#include "DEFINITIONS.hpp"
#include "models/Game.hpp"

namespace GameOfLife {
    GameState::GameState(GameDataRef data) :
        data(data)
    {

    }

    void GameState::Init(){

    }

    void GameState::HandleInput(){
        sf::Event event;

        while(this->data->window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    this->data->window.close();
                    break;
                case sf::Event::KeyPressed:
                    this->HandleKeyboardInput(event.key.code);
                    break;
                default:
                    break;
            }
        }
    }

    void GameState::Update(float dt){
        
    }

    void GameState::Draw(float dt){
        this->data->window.clear(sf::Color::White);
        this->DrawBoard();
        this->data->window.display();
    }

    void GameState::HandleKeyboardInput(sf::Keyboard::Key key){
        switch (key) {
            case sf::Keyboard::Q:
                this->data->window.close();
            default:
                break;
        } 
    }

    void GameState::DrawBoard(){
        int rows = this->data->board.GetRows();
        int columns = this->data->board.GetColumns();

        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                sf::RectangleShape cell = this->data->board.GetCellAt(i, j).GetDrawableCell();
                cell.setPosition(BOARD_MARGIN + j * CELL_WIDTH, BOARD_MARGIN + i * CELL_HEIGHT);
                this->data->window.draw(cell);
            }
        }
    }
}
