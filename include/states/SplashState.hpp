#pragma once

#include "machine/State.hpp"
#include "models/Game.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


namespace GameOfLife{ 
    class SplashState : public State{
        public:
            SplashState(GameDataRef data);

            void Init();
            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

        private:
            GameDataRef data;
            sf::Sprite background;
            sf::Texture backgroundTexture;
    };
}
