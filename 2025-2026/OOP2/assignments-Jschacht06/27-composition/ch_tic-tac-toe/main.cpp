#include <iostream>
#include "Game.h"
#include <cstdlib> // rand
#include <ctime>   // time

using namespace std;

int main() {
    // Seed random once at the start of the program
    srand(static_cast<unsigned int>(time(0)));

    bool keepPlaying = true;
    while (keepPlaying) {
        // Create the game object
        // The Constructor is called immediately here
        Game myGame; 

        // Play the game
        myGame.start();

        // When 'myGame' goes out of scope (at the end of the while loop),
        // the Destructor is called automatically, cleaning up the memory.
        
        cout << "Play again? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'n' || choice == 'N') keepPlaying = false;
    }

    return 0;
}