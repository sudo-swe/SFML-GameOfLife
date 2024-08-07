#pragma once

#include "DEFINITIONS.hpp"
#include "machine/StateMachine.hpp"
#include "models/Board.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>


namespace GameOfLife {
    struct GameData{
        StateMachine machine;
        sf::RenderWindow window;
        Board board;

        GameData(int rows, int columns) : board(rows, columns){}
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game{
        public:
            Game(int width, int height, std::string title);

        private:
            const float dt = 1.0/60.0f;
            sf::Clock clock;
            GameDataRef data = std::make_shared<GameData>(BOARD_ROWS, BOARD_COLUMNS);

            void Run();
    };
}
