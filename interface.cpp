#include "interface.h"

void displayBoard(Game c)
{
	Board board = c.getBoard();

	for(int i = 0; i < ROWS; i++)
	{
		cout << "|";

		for(int j = 0; j < COLS; i++)
		{
			if(board.getStatus(i,j) == 0)
			{
				cout << " |";
			}
			else if(board.getStatus(i,j) == 1)
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
    int choice;
    cout << "Welcome to the Connect 4 Game!\n" << endl;
    cout << "Please select your game mode" << endl;
    cout << "1. Play with another user." << endl;
    cout << "2. Play against a CPU." << endl;
    cout << "3. Quit :((" << endl;

    while(1)
    {
        cout << "Select: ";
        cin >> choice;

        if(choice <= 3 && choice >= 1)
            break;
    }
}
