#include "states/GameState.hpp"
#include "models/Game.hpp"
#include "DEFINITIONS.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <sstream>
#include <string>

namespace GameOfLife {
    GameState::GameState(GameDataRef data) :
        data(data) {}

    void GameState::Init(){
        this->data->assets.LoadFont("Mouldy Font", PATH_MOULDY_FONT);

        this->generationsText.setFont(this->data->assets.GetFont("Mouldy Font"));
        this->generationsText.setFillColor(GAMESTATE_TEXT_NORMAL_COLOR);
        this->generationsText.setCharacterSize(20);
        this->generationsText.setString("Generations #");
        this->generationsText.setPosition(
                BOARD_MARGIN, 
                BOARD_MARGIN-this->generationsText.getGlobalBounds().height-10
                );

        this->pausedText.setFont(this->data->assets.GetFont("Mouldy Font"));
        this->paused ? this->pausedText.setFillColor(GAMESTATE_TEXT_ACTIVE_COLOR) : this->pausedText.setFillColor(GAMESTATE_TEXT_NORMAL_COLOR);
        this->pausedText.setCharacterSize(20);
        this->pausedText.setString("(P)ause");
        this->pausedText.setPosition(
                SCREEN_WIDTH-BOARD_MARGIN-this->pausedText.getGlobalBounds().width,
                BOARD_MARGIN-this->pausedText.getGlobalBounds().height-10
                );

        if(!this->data->board.LoadPresetBoard(PATH_PRESET_SYMMETRY_ACORN)){
            this->data->board.LoadRandomBoard();
        }
    }

    void GameState::HandleInput(){
        sf::Event event;

        while(this->data->window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    this->data->window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Q:
                            this->data->window.close();
                            break;
                        case sf::Keyboard::P:
                            this->paused = !this->paused;
                            break;
                        default:
                            break;
                    } 
                    break;

                case sf::Event::MouseButtonPressed:
                    switch (event.mouseButton.button) {
                        case sf::Mouse::Left:
                            if(this->paused){
                                sf::Vector2i mousePos = sf::Mouse::getPosition(this->data->window);
                                sf::Vector2f mousePosF = this->data->window.mapPixelToCoords(mousePos);
                                this->data->board.ToggleCellAt(mousePosF);
                            }
                            break;
                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
        }
    }

    void GameState::Update(float dt){
        if (!this->paused && this->clock.getElapsedTime().asSeconds() > GENERATION_DELAY_SECONDS) {
            this->clock.restart();
            this->data->board.ProcessGeneration();
        }

        this->data->board.Update();
        this->UpdateText();
    }

    void GameState::UpdateText(){
        this->paused ? 
            this->pausedText.setFillColor(GAMESTATE_TEXT_ACTIVE_COLOR) : 
            this->pausedText.setFillColor(GAMESTATE_TEXT_NORMAL_COLOR);

        std::ostringstream oss;
        oss << "Generations #" << this->data->board.GetGenerations();
        this->generationsText.setString(oss.str());
    }

    void GameState::Draw(float dt){
        this->data->window.clear(GAMESTATE_BACKGROUND_COLOR);
        this->DrawBoard();
        this->data->window.draw(this->generationsText);
        this->data->window.draw(this->pausedText);
        this->data->window.display();
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
