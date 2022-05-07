#include "ai.h"
#include "interface.h"
using namespace std;

int best_turn(Game c)
{
    Game clone = c;
    bool valid[COLS];

    int maxConts = 0;
    int bestCol = -1;

    for(int i = 0; i < COLS; i++)
    {
        clone = c;

        valid[i] = clone.turn(i, 2);
        if(clone.check_game_status() == 2)
            return i;

        int continues = 7;
        for(int j = 0; j < COLS; j++)
        {
            Game clone2 = clone;
            bool valid2 = clone2.turn(j, 1);

            if(clone2.check_game_status() == 1 && valid2)
                continues--;
        }

        if(continues > maxConts)
        {
            maxConts = continues;
            bestCol = i;
        }
    }

    if(valid[bestCol])
        return bestCol;
    else
    {
        for(int i = 0; i < COLS; i++)
        {
            if(valid[i])
                return i;
        }
    }

    return bestCol;
}

