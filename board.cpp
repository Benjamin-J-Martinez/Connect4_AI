#include "board.h"

void Board::update(int x, int y, int status) {board[x][y] = status; }
int Board::getStatus(int x, int y) {return board[x][x]}
