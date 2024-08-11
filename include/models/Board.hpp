#pragma once

#include "models/Cell.hpp"
#include <string>
#include <vector>

namespace GameOfLife{
    class Board{
        public:
            Board(int rows, int columns, std::string preset="");

            int GetRows();
            int GetColumns();
            Cell &GetCellAt(int row, int column);
            void ToggleCellAt(sf::Vector2f mousePos);
            void Update();
            void ProcessGeneration();

        private:
           int rows, columns;
           std::vector<std::vector<Cell>> grid;

           int GetNumOfLiveNeighbors(int row, int column);
    };
}
