#include "game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    memory_game::Game game;
    game.PlayGame();
    
    return 0;
}