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
            void Update(bool randomColors);
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

            void UpdateState();
            void UpdateColor(bool randomColors);
            void SetRandomColor();
    };
}
