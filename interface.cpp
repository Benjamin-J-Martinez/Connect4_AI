#include "interface.h"

/* Parameters: an object of type Game
 * Return: N/A
 * Description: displays the current game board
 */
void displayBoard(Game c)
{
	Board board = c.getBoard();

	cout << "--------------- " << endl;

	for(int i = 0; i < ROWS; i++)
	{
		cout << "|";

		for(int j = 0; j < COLS; j++)
		{
			if(board.getSpace(i,j) == 0)
			{
				cout << " |";
			}
			else if(board.getSpace(i,j) == 1)
			{
				cout << "X|";
			}
			else
			{
				cout << "O|";
			}
		}
		cout << endl;
	}
	cout << "--------------- " << endl;
	cout << " 1 " << "2 " << "3 " << "4 " << "5 " << "6 " << "7" << endl;
}

/* Parameters: an object of type Game
 * Return: N/A
 * Description: displays the start menu of the game, prompts for choice from the user based on the menu's options
 */
void start(Game c)
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

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			continue;
		}

        if(choice <= 3 && choice >= 1)
            break;
    }

	if(choice == 1)
		play_two_users(c);
	else if(choice == 2)
		play_AI(c);
	else
	{
		cout << "Goodbye :(((" << endl;
		return;

	}
}

/* Parameters: an object of type Game
 * Return: N/A
 * Description: runs a game of user vs user
 */
void play_two_users(Game& c)
{
	int numTurns = 1;
	int currentTurn = 1;
	int gameStatus = c.check_game_status();

	while(gameStatus == 0 && numTurns <= 42) //game runs till their is a winner or 42 turns have been played, filling the board
	{
		displayBoard(c); // initial, empty board is displayed
		if(!getUserTurn(c, currentTurn))
			continue;


		if(currentTurn == 1)
			currentTurn = 2;
		else
			currentTurn = 1;

		numTurns++;
		gameStatus = c.check_game_status(); //check for winner or a draw after a turn is made

		if(gameStatus == 1) // game is ended if player 1 connects 4 in a row, displaying that they have won
		{
			displayBoard(c); //display final board
			cout << "PLAYER 1 WINS!!" << endl;
		}
		
		if(gameStatus == 2) // game is ended if player 2 connects 4 in a row, displaying that they have won
		{
			displayBoard(c); //display final board
			cout << "PLAYER 2 WINS!!" << endl;
		}
		
		if(numTurns > 42) // once the board is full, print the final board and tell the user that a draw has occured
        	{
                	displayBoard(c);
                	cout << "Draw" << endl;
        	}
	}
}

/* Parameters: an object of type Game
 * Return: N/A
 * Description: runs a game of user vs AI
 */
void play_AI(Game c)
{
	srand(time(NULL));
	int numTurns = 1;
	int currentTurn = 1;
	int gameStatus = c.check_game_status();

	int col = rand() % 7;

	while(gameStatus == 0 && numTurns < 42)
	{
		displayBoard(c);

		if(currentTurn == 1)
		{
			if(!getUserTurn(c, currentTurn))
				continue;
			else
				currentTurn = 2;
		}
		else
		{
			if(numTurns <= 4)
			{
				c.turn(col, 2);
				numTurns++;
				currentTurn = 1;
				continue;
			}
			
			c.turn(best_turn(c), currentTurn);
			currentTurn = 1;
		}
		
		numTurns++;
		gameStatus = c.check_game_status();

		if(gameStatus == 1) //game is ended if player 1 connects 4 in a row, displaying that they have won
		{
			displayBoard(c); //display final board
			cout << "PLAYER 1 WINS!!" << endl;
		}
		
		if(gameStatus == 2) // game is ended if player 2 connects 4 in a row, displaying that they have won
		{
			displayBoard(c); //display final board
			cout << "PLAYER 2 WINS!!" << endl;
		}
			
		if(numTurns > 42) // once the board is full, print the final board and tell the user that a draw has occured
		{
			displayBoard(c);
			cout << "Draw" << endl;
		}
	}
}

/* Parameters: int variable, either 1 or 2, representing which player's turn it is
 * Return: N/A
 * Description: this function checks whose turn it currently is, prompts the user for input and checks if the move is valid, if it is then the move will occur, not then the user
   will be notified of this invalid move and will be asked to re-enter a choice
 */
bool getUserTurn(Game& c, int currentPlayer)
{
	int col;

	cout << "Player " << currentPlayer << " choose a column(1-7): "; //user inputs which column they'd like to make their move in
	cin  >> col;
	while(1)
	{
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Player " << currentPlayer << " choose a column(1-7): ";
			cin >> col;
		}
		else
			break;

	}


	col--;

	if((col >= 0 && col < 7) && c.turn(col, currentPlayer)) // taken if selected column is valid & move is possible(column is not full)
		return true;

	cout << "Invalid move" << endl; // if the selected column is not within 1-7 or the column is full
	return false;
}
