#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

#pragma once

namespace GameOfLife {
    class Cell{
        public:
            enum CellState {
                DEAD=0,
                ALIVE=1,
                ALIVE_TO_DEAD=2,
                DEAD_TO_ALIVE=3
            };

            Cell(){}
            Cell(int row, int column, CellState state=DEAD);

            void SetCellState(CellState state);
            bool IsAlive();
            bool WillDie();
            bool WillLive();
            void Update(bool randomColors, bool trailColors);
            sf::RectangleShape &GetDrawableCell();

        private: 
            int row, column;
            CellState state;
            sf::RectangleShape drawableCell;
            sf::Color colors[5] = {
                sf::Color::Red,
                sf::Color::Green,
                sf::Color::Blue,
                sf::Color::Yellow,
                sf::Color::Magenta
            };
            sf::Color shades[5] = {
                sf::Color(150, 0, 0),
                sf::Color(125, 0, 0),
                sf::Color(100, 0, 0),
                sf::Color(50, 0, 0),
                sf::Color(0, 0, 0)
            };
            int deadShade = 4;

            void UpdateState();
            void UpdateColor(bool randomColors, bool trailColors);
            void SetRandomColor();
    };
}
