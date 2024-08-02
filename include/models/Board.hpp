#pragma once

#include "models/Cell.hpp"
#include <vector>

namespace GameOfLife{
    class Board{
        public:
            Board(int rows, int columns);

            int GetRows();
            int GetColumns();
            Cell &GetCellAt(int row, int column);

        private:
           int rows, columns;
           std::vector<std::vector<Cell>> grid;
    };
}
