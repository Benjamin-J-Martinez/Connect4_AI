#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game
{
    private:
        Board gameBoard;

    public:
        Game();
        int check_game_status();
        bool turn(int col, int player);
        Board getBoard();
};

#endif
