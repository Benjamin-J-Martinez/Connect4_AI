#ifndef BOARD_H
#define BOARD_H

#define ROWS 6
#define COLS 7

class Board
{
    private:
        int board[6][7];
        int status;

    public:
        Board();
        void update(int x, int y, int status);
        int getSpace(int x, int y);
};

#endif
