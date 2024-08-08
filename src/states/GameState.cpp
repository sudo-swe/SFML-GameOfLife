#include "states/GameState.hpp"
#include "models/Game.hpp"
#include "DEFINITIONS.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace GameOfLife {
    GameState::GameState(GameDataRef data) :
        data(data) {}

    void GameState::Init(){}

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
                    break;
                default:
                    break;
            }
        }
    }

    void GameState::Update(float dt){
        if(this->paused) this->data->board.Update();
        else if (this->clock.getElapsedTime().asSeconds() > GENERATION_DELAY_SECONDS){
           this->clock.restart();
           this->data->board.ProcessGeneration();
        }
    }

    void GameState::TogglePause(){ 
        this->paused = !this->paused;
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
                break;
            case sf::Keyboard::P:
                this->TogglePause();
                break;
            default:
                break;
        } 
    }

    void GameState::HandleMouseInput(sf::Mouse::Button button){
        switch (button) {
            case sf::Mouse::Left:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(this->data->window);
                    sf::Vector2f mousePosF = this->data->window.mapPixelToCoords(mousePos);
                    this->data->board.ToggleCellAt(mousePosF);
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
