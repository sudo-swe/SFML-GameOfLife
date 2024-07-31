#include "models/Game.hpp"
#include "machine/StateMachine.hpp"
#include "states/SplashState.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

namespace GameOfLife {
    Game::Game(int width, int height, std::string title){
        srand(time(NULL));
        this->data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        this->data->machine.AddState(StateRef(new SplashState(this->data)));
        this->Run();
    }

    void Game::Run(){
        float newTime, frameTime, interpolation;
        float currentTime = this->clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while(this->data->window.isOpen()){
            this->data->machine.ProcessStateChanges();
            newTime = this->clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if(frameTime > 0.25f) frameTime = 0.25f;

            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= this->dt) {
                this->data->machine.GetActiveState()->HandleInput();
                this->data->machine.GetActiveState()->Update(this->dt);
                accumulator -= this->dt;
            }

            interpolation = accumulator/this->dt;
            this->data->machine.GetActiveState()->Draw(interpolation);
        }
    } 
}
