#include "states/GameState.hpp"
#include "DEFINITIONS.hpp"
#include "models/Game.hpp"
#include <iostream>

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
                case sf::Event::MouseButtonPressed:
                    this->HandleMouseInput(event.mouseButton.button);
                default:
                    break;
            }
        }
    }

    void GameState::Update(float dt){
        if(this->clock.getElapsedTime().asSeconds() > 2.0f){
            this->clock.restart();
            this->data->board.Update();
        }
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

    void GameState::HandleMouseInput(sf::Mouse::Button button){
        switch (button) {
            case sf::Mouse::Left:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(this->data->window);
                    this->data->board.ToggleCellAt(this->data->window.mapPixelToCoords(mousePos));
                }
                break;
            default:
                break;
        }
    }

    void GameState::DrawBoard(){
        int rows = this->data->board.GetRows();
        int columns = this->data->board.GetColumns();

        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                sf::RectangleShape &cell = this->data->board.GetCellAt(i, j).GetDrawableCell();
                cell.setPosition(BOARD_MARGIN + j * CELL_WIDTH, BOARD_MARGIN + i * CELL_HEIGHT);
                this->data->window.draw(cell);
            }
        }
    }
}
