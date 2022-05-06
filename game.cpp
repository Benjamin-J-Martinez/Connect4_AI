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
	
}

