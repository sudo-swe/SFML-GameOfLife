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

            Cell(int row, int column, CellState state=DEAD);

            void SetCellState(CellState state);
            bool IsAlive();
            bool WillDie();
            bool WillLive();

        private: 
            int row, column;
            CellState state;
    };
}
