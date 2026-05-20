#include "Game.h"
#include <iostream>
#include <limits>
#include <cstdlib> // rand
#include <ctime>   // time

using namespace std;

// constructor
Game::Game() {
    // settings
    cout << "\n*** Tic Tac Toe ***\n" << endl;
    
    // size
    size = 3;
    cout << "Enter board size (3 for standard 3x3, etc): ";
    while(!(cin >> size) || size < 3) {
        cout << "Invalid size. Minimum 3: ";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // opponent choice
    int opponentChoice = 0;
    cout << "Choose Opponent: (1) Human, (2) Computer: ";
    while(!(cin >> opponentChoice) || (opponentChoice != 1 && opponentChoice != 2)) {
        cout << "Enter 1 or 2: ";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // names
    cout << "Enter name of player 1: ";
    cin >> p1Name;

    if (opponentChoice == 1) {
        cout << "Enter name of player 2: ";
        cin >> p2Name;
        p2Type = HUMAN;
    } else {
        p2Name = "Computer";
        p2Type = COMPUTER;
    }

    // Initialize board
    board = new Cell*[size];
    for(int i = 0; i < size; ++i) {
        board[i] = new Cell[size];
        for(int j = 0; j < size; ++j) {
            board[i][j] = EMPTY;
        }
    }
}

// destructor
Game::~Game() {
    for(int i = 0; i < size; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

void Game::start() {
    GameStatus status = PLAYING;
    currentPlayerIdx = 1;
    int winningPlayer = 0;

    cout << "\nLet's start! Input format: <row> <column>" << endl;

    while(status == PLAYING) {
        printBoard();

        if(currentPlayerIdx == 1) {
            getPlayerMove(p1Name, PLAYER_X);
        } else {
            if(p2Type == HUMAN) getPlayerMove(p2Name, PLAYER_O);
            else {
                getComputerMove();
                cout << "Computer has played." << endl;
            }
        }

        status = checkGameStatus(winningPlayer);

        if(status == PLAYING) {
            currentPlayerIdx = (currentPlayerIdx == 1) ? 2 : 1;
        }
    }

    printBoard();
    if(status == WIN) {
        string winner = (winningPlayer == 1) ? p1Name : p2Name;
        cout << "\nCongratulations " << winner << "! You won!" << endl;
    } else {
        cout << "\nIt's a draw!" << endl;
    }
}


void Game::printBoard() const {
    cout << endl;
    for (int i = 0; i < size; ++i) {
        cout << "  ";
        for (int j = 0; j < size; ++j) {
            cout << " " << getCellSymbol(board[i][j]) << " ";
            if (j < size - 1) cout << "|";
        }
        cout << endl;
        if (i < size - 1) {
            cout << "  ";
            for (int k = 0; k < size * 4 - 1; ++k) cout << "-";
            cout << endl;
        }
    }
    cout << endl;
}

char Game::getCellSymbol(Cell cell) const {
    switch (cell) {
        case PLAYER_X: return 'X';
        case PLAYER_O: return 'O';
        default: return ' ';
    }
}

void Game::getPlayerMove(string name, Cell symbol) {
    int r, c;
    while (true) {
        cout << name << ": enter your position (row col): ";
        if (!(cin >> r >> c)) {
            cout << "Invalid input." << endl;
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        r--; c--; // Convert to 0-index
        if (isValidMove(r, c)) {
            board[r][c] = symbol;
            break;
        } else {
            cout << "Invalid move!" << endl;
        }
    }
}

void Game::getComputerMove() {
    int r, c;
    while (true) {
        r = rand() % size;
        c = rand() % size;
        if (board[r][c] == EMPTY) {
            board[r][c] = PLAYER_O;
            break;
        }
    }
}

bool Game::isValidMove(int row, int col) const {
    if (row < 0 || row >= size || col < 0 || col >= size) return false;
    return board[row][col] == EMPTY;
}

GameStatus Game::checkGameStatus(int& winningPlayer) const {

    

    for(int i=0; i<size; i++) {
        // Row check
        if(board[i][0] != EMPTY) {
            bool win = true;
            for(int k=1; k<size; k++) if(board[i][k] != board[i][0]) win = false;
            if(win) { winningPlayer = (board[i][0] == PLAYER_X) ? 1:2; return WIN; }
        }
        // Col check
        if(board[0][i] != EMPTY) {
            bool win = true;
            for(int k=1; k<size; k++) if(board[k][i] != board[0][i]) win = false;
            if(win) { winningPlayer = (board[0][i] == PLAYER_X) ? 1:2; return WIN; }
        }
    }

    // 3. Draw Check
    bool full = true;
    for(int i=0; i<size; i++) 
        for(int j=0; j<size; j++) 
            if(board[i][j] == EMPTY) full = false;
            
    return full ? DRAW : PLAYING;
}