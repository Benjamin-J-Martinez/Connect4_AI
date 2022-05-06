#ifndef INTERFACE_H
#define INTERFACE_H

#include "game.h"
#include <iostream>
using namespace std;

void displayBoard(Game c);
void start(Game c);
void play_two_users(Game c);
void play_AI(Game c);
void getUserTurn(int currentPlayer);

#endif
