#ifndef INTERFACE_H
#define INTERFACE_H

#include "game.h"
#include "ai.h"
#include <iostream>
#include <time.h>
#include <limits>
using namespace std;

void displayBoard(Game c);
void start(Game c);
void play_two_users(Game& c);
void play_AI(Game c);
bool getUserTurn(Game& c, int currentPlayer);

#endif
