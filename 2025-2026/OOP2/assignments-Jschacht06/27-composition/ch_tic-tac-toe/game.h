#pragma once

#include <string>

enum Cell { EMPTY, PLAYER_X, PLAYER_O };
enum GameStatus { PLAYING, WIN, DRAW };
enum PlayerType { HUMAN, COMPUTER };

class Game {
private:
    // variables
    Cell** board;
    int size;
    std::string p1Name;
    std::string p2Name;
    PlayerType p2Type;
    int currentPlayerIdx;

    
    void printBoard() const;
    void getPlayerMove(std::string name, Cell symbol);
    void getComputerMove();
    bool isValidMove(int row, int col) const;
    GameStatus checkGameStatus(int& winningPlayer) const;
    char getCellSymbol(Cell cell) const;

public:
    // Constructor
    Game();
    
    // Destructor
    ~Game();

    // The main loop to play one match
    void start();
};
