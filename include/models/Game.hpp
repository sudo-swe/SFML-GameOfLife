#pragma once

#include "machine/StateMachine.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>


namespace GameOfLife {
    struct GameData{
        StateMachine machine;
        sf::RenderWindow window;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game{
        public:
            Game(int width, int height, std::string title);

        private:
            const float dt = 1.0/60.0f;
            sf::Clock clock;
            GameDataRef data = std::make_shared<GameData>();

            void Run();
    };
}
