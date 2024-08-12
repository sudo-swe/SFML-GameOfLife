#pragma once

#include "DEFINITIONS.hpp"
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
            bool paused = true;
            bool randomColors = false;
            bool trailColors = false;

            float generationDelay = GENERATION_DELAY_SECONDS;

            sf::Text generationsText;
            sf::Text pausedText;

            void UpdateText();
            void DrawBoard();
    };
}
