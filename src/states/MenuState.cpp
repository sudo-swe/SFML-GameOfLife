#include "states/MenuState.hpp"
#include "DEFINITIONS.hpp"
#include "models/Game.hpp"

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
}
