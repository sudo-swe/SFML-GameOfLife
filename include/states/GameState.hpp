#pragma once

#include "models/Game.hpp"
#include <SFML/Graphics/Text.hpp>

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
            sf::Text generationsText;
            sf::Text pausedText;

            bool paused = true;
            long generations = 0;


            void HandleKeyboardInput(sf::Keyboard::Key key);
            void HandleMouseInput(sf::Mouse::Button button);
            void DrawBoard();
            void TogglePause();
            void PrintBoard();
    };
}
