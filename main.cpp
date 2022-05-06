#include "interface.h"
using namespace std;

int main()
{
    Game connect4;
/*	connect4.getBoard().update(0,2,1);
	 connect4.getBoard().update(0,1,2);
	cout << connect4.getBoard().getStatus(0,2) << endl;
	 cout << connect4.getBoard().getStatus(0,1) << endl;
  */  displayBoard(connect4);

	start(connect4);

    return 0;
}
