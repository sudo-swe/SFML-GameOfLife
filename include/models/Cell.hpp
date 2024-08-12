#include "DEFINITIONS.hpp"
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
            sf::Color colors[6] = {
                CELL_ALIVE_RANDOM_COLOR_1,
                CELL_ALIVE_RANDOM_COLOR_2,
                CELL_ALIVE_RANDOM_COLOR_3,
                CELL_ALIVE_RANDOM_COLOR_4,
                CELL_ALIVE_RANDOM_COLOR_5,
                CELL_ALIVE_RANDOM_COLOR_6
            };
            sf::Color shades[11] = {
                CELL_DEAD_TRAIL_1,
                CELL_DEAD_TRAIL_2,
                CELL_DEAD_TRAIL_3,
                CELL_DEAD_TRAIL_4,
                CELL_DEAD_TRAIL_5,
                CELL_DEAD_TRAIL_6,
                CELL_DEAD_TRAIL_7,
                CELL_DEAD_TRAIL_8,
                CELL_DEAD_TRAIL_9,
                CELL_DEAD_TRAIL_10,
                CELL_DEAD_TRAIL_11
            };
            int deadShade = sizeof(this->shades)-1;

            void UpdateState();
            void UpdateColor(bool randomColors, bool trailColors);
            sf::Color GetRandomColor();
    };
}
