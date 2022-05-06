#include "ai.h"

int AI::best_move(Game c)
{
    if(c.check_game_status() == 2)
        return 1;
    
    if(c.check_game_status() == 1)
        return 0;

    int bestCol;
    if(c.check_game_status() == 0)
    {

        for(int i = 0; i < COLS; i++)
        {
            Game clone = c;
            clone.turn(i, 2);
            best_move(clone);
        }

        return bestCol;
        
    }
}