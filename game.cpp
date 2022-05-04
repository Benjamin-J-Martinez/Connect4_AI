#include "game.h"

bool Game::turn(int col, int player)
{
    int status;
    for(int i = ROWS - 1; i >= 0; i--)
    {
        if(gameBoard.getStatus(i, col) == 0)
        {
            gameBoard.update(i, col, player);
            return true;
        }       
    }

    return false;
}