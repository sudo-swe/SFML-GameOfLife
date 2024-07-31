#include "states/SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "models/Game.hpp"

namespace GameOfLife {
    SplashState::SplashState(GameDataRef data) : data(data){}

    void SplashState::Init(){
        this->backgroundTexture.loadFromFile(PATH_SPLASH_BACKGROUND);
        this->background.setTexture(this->backgroundTexture);
    }

    void SplashState::HandleInput(){
        sf::Event event;

        while(this->data->window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    this->data->window.close();
                    break;
                default:
                    break;
            }
        }
    }

    void SplashState::Update(float dt){}

    void SplashState::Draw(float dt){
        this->data->window.clear();
        this->data->window.draw(this->background);
        this->data->window.display();
    }
}
