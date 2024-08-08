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
            sf::Clock clock;
            sf::Sprite background;
            sf::Texture backgroundTexture;
            bool paused = false;

            void HandleKeyboardInput(sf::Keyboard::Key key);
            void HandleMouseInput(sf::Mouse::Button button);
            void DrawBoard();
            void TogglePause();
    };
}
