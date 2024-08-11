#pragma once

#include "machine/State.hpp"
#include "models/Game.hpp"

#include <SFML/Graphics.hpp>

namespace GameOfLife{ 
    class MenuState : public State{
        public:
            MenuState(GameDataRef data);

            void Init();
            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

        private:
            GameDataRef data;
            sf::Sprite background;
    };
}
