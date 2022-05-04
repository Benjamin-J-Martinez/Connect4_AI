#include "board.h"

class Game
{
    private:
        Board gameBoard;

    public:
        int check_game_status(Board b);
        bool turn(int col, int player);
};