#include "game.h"

/* Parameters: N/A
 * Return: N/A
 * Description: Game object contructor
 */
Game::Game()
{

}

/* Parameters: an integer col representing the column to perfrom the turn and an integer representing the player to go.
 * Return: Returns true if the turn was succesfull and false otherwise.
 * Description: performs an turn on the game potentially changing the status.
 */
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

/* Parameters: N/A
 * Return: A reference to the game Board
 * Description: returns the memory location of the gameboard
 */
Board& Game::getBoard()
{
	return gameBoard;
}

/* Parameters: N/A
 * Return: returns an integer representing the status of the board 0 = playing, 1= player1 win, 2= player2 win.
 * Description: checks the status of the game 
 */
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
            else
            {
                p1 = 0;
                p2 = 0;
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
            else
            {
                p1 = 0;
                p2 = 0;
            }

            if(p1 == 4)
                return 1;
            
            if(p2 == 4)
                return 2;
        }

        p1 = 0;
        p2 = 0;
    }

    //checks diagnol for a connect 4 (bottom left to top right)
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
            else
            {
                p1 = 0;
                p2 = 0;
            }
            
            if(p1 == 4)
                return 1;
            
            if(p2 == 4)
                return 2;
        }

        p1 = 0;
        p2 = 0;
    }

    //first half of diagnol (top left to bottom right)
    for(int rowStart = 0; rowStart < ROWS - 3; rowStart++)
    {
        int row, col;
        
        for(row = rowStart, col = 0; row < ROWS && col < COLS; row++, col++ )
        {
            if(board.getSpace(row, col) == 1)
            {
                p1++;
                p2 = 0;
            }
            else if(board.getSpace(row, col) == 2)
            {
                p2++;
                p1 = 0;
            }
            else
            {
                p1 = 0;
                p2 = 0;
            }
            
            if(p1 == 4)
                return 1;
            
            if(p2 == 4)
                return 2;
        }

        p1 = 0;
        p2 = 0;
    }
    
    //second half of diagnol (top left to bottom right)
    for(int colStart = 1; colStart < COLS - 3; colStart++)
    {
        int row, col;
        for(row = 0, col = colStart; row < ROWS && col < COLS; row++, col++ )
        {
            if(board.getSpace(row, col) == 1)
            {
                p1++;
                p2 = 0;
            }
            else if(board.getSpace(row, col) == 2)
            {
                p2++;
                p1 = 0;
            }
            else
            {
                p1 = 0;
                p2 = 0;
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

