#ifndef BOARD_H
#define BOARD_H

#define ROWS 6
#define COLS 7

class Board
{
    private:
        int board[6][7];

    public:
        Board();
        void update(int x, int y, int status);
        int getStatus(int x, int y);
};

#endif
