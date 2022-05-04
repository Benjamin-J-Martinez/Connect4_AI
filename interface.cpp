#include "interface.h"

void displayBoard(Game c)
{
	Board board = c.getBoard();

	for(int i = 0; i < ROWS; i++)
	{
		cout << "|";

		for(int j = 0; j < COLS; i++)
		{
			if(board.getStatus() == 0)
			{
				cout << " |";
			}
			else if(board.getStatus() == 1)
			{
				cout << " X|";
			}
			else
			{
				cout << "O|";
			}
		}
		cout << endl;
	}
	cout << " 1 " << " 2 " << " 3 " << " 4 " << " 5 " << " 6 " << " 7 " << endl;
}

void start()
{
    
}
