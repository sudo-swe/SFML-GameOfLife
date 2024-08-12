#pragma once

#include "models/Cell.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <vector>

namespace GameOfLife{
    class Board{
        public:
            Board(int rows, int columns);

            int GetRows();
            int GetColumns();
            long GetGenerations();
            Cell &GetCellAt(int row, int column);

            void Update(bool randomColors, bool trailColors);
            void ProcessGeneration();

            void LoadRandomBoard();
            void LoadBlankBoard();
            bool LoadPresetBoard(std::string presetPath);
            void ToggleCellAt(sf::Vector2f mousePos);

        private:
           int rows, columns;
           long generations=0;
           std::vector<std::vector<Cell>> grid;

           int GetNumOfLiveNeighbors(int row, int column);
    };
}
