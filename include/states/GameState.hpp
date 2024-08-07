#pragma once

#include "models/Game.hpp"
namespace GameOfLife {
    class GameState : public State {
        public: 
            GameState(GameDataRef data);

            void Init();
            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

        private:
            GameDataRef data;
            sf::Sprite background;
            sf::Texture backgroundTexture;

            void HandleKeyboardInput(sf::Keyboard::Key key);
            void DrawBoard();
    };
}
