#include "states/SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "machine/StateMachine.hpp"
#include "models/Game.hpp"
#include "states/GameState.hpp"
#include <ctime>

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
                case sf::Event::KeyPressed:
                    this->HandleKeyboardInput(event.key.code);
                    break;
                default:
                    break;
            }
        }
    }

    void SplashState::HandleKeyboardInput(sf::Keyboard::Key key){
        switch (key) {
            case sf::Keyboard::Q:
                this->data->window.close();
            default:
                break;
        } 
    }

    void SplashState::Update(float dt){
        if(this->clock.getElapsedTime().asSeconds() > SPLASHSTATE_DELAY_SECONDS){
            this->data->machine.AddState(StateRef(new GameState(data)));
        }
    }

    void SplashState::Draw(float dt){
        this->data->window.clear();
        this->data->window.draw(this->background);
        this->data->window.display();
    }
}
