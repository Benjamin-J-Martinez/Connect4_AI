#include "board.h"

void Board::update(int x, int y, int status) {board[x][y] = status; }
int Board::getSpace(int x, int y) {return board[x][y]; }
Board::Board()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
            board[i][j] = 0;
    }
}
