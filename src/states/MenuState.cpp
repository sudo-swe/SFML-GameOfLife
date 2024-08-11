#include "states/MenuState.hpp"
#include "DEFINITIONS.hpp"
#include "machine/StateMachine.hpp"
#include "models/Game.hpp"
#include "states/GameState.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace GameOfLife {
    MenuState::MenuState(GameDataRef data) : data(data) {}

    void MenuState::Init(){
        this->data->assets.LoadTexture("Menu Background", PATH_MENUSTATE_BACKGROUND);
        this->background.setTexture(this->data->assets.GetTexture("Menu Background"));
    }

    void MenuState::HandleInput(){
        sf::Event event;

        while(this->data->window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    this->data->window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Num1:
                            this->data->board.LoadPresetBoard(PATH_PRESET_GLIDER_GUN);
                            this->StartGame();
                            break;
                        case sf::Keyboard::Num2:
                            this->data->board.LoadPresetBoard(PATH_PRESET_SYMMETRY_ACORN);
                            this->StartGame();
                            break;
                        case sf::Keyboard::Num3:
                            this->data->board.LoadPresetBoard(PATH_PRESET_B_HEPTOMINO);
                            this->StartGame();
                            break;
                        case sf::Keyboard::Num4:
                            this->data->board.LoadRandomBoard();
                            this->StartGame();
                            break;
                        case sf::Keyboard::Num5:
                            this->data->board.LoadBlankBoard();
                            this->StartGame();
                            break;
                        case sf::Keyboard::Q:
                            this->data->window.close();
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

    void MenuState::Update(float dt){}

    void MenuState::Draw(float dt){
        this->data->window.clear();
        this->data->window.draw(this->background);
        this->data->window.display();
    }

    void MenuState::StartGame(){
        this->data->machine.AddState(StateRef(new GameState(data)));
    }
}
