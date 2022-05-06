#include "game.h"

Game::Game()
{

}
bool Game::turn(int col, int player)
{
    for(int i = ROWS - 1; i >= 0; i--)
    {
        if(gameBoard.getSpace(i, col) == 0)
        {
            gameBoard.update(i, col, player);
            return true;
        }
    }

    return false;
}

Board& Game::getBoard()
{
	return gameBoard;
}

int Game::check_game_status()
{
    Board board = getBoard();
    int p1, p2;

    //checks rows for a connect 4
    for(int i = ROWS-1; i >= 0; i--)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(board.getSpace(i, j) == 1)
            {
                p1++;
                p2 = 0;
            }  
            else if(board.getSpace(i, j) == 2)
            {
                p2++;
                p1 = 0;
            }
            
            if(p1 == 4)
                return 1;
            
            if(p2 == 4)
                return 2;
        }

        p1 = 0;
        p2 = 0;
    }

    //checks columns for a connect 4
    for(int j = 0; j < COLS; j++)
    {
        for(int i = ROWS-1; i >= 0; i--)
        {
            if(board.getSpace(i, j) == 1)
            {
                p1++;
                p2 = 0;
            }  
            else if(board.getSpace(i, j) == 2)
            {
                p2++;
                p1 = 0;
            }
            
            if(p1 == 4)
                return 1;
            
            if(p2 == 4)
                return 2;
        }

        p1 = 0;
        p2 = 0;
    }

    //checks diagnol for a connect 4
    for(int line = 1; line <= (ROWS + COLS - 1); line++)
    {
        int start_col =  (0 > line - ROWS) ? 0 : line - ROWS;

        int temp = (line < (COLS - start_col)) ? line : (COLS - start_col);
        int count = (temp < ROWS) ? temp : ROWS;

        for(int j = 0; j < count; j++)
        {
            int minu = (ROWS < line) ? ROWS : line;

            if(board.getSpace(minu - j - 1, start_col + j) == 1)
            {
                p1++;
                p2 = 0;
            }  
            else if(board.getSpace(minu - j - 1, start_col + j) == 2)
            {
                p2++;
                p1 = 0;
            }
            
            if(p1 == 4)
                return 1;
            
            if(p2 == 4)
                return 2;
        }

        p1 = 0;
        p2 = 0;
    }

    return 0;
}

