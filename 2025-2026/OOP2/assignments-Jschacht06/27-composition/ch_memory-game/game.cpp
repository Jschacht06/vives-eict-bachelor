#include "game.h"
#include <limits> 
#include <cstdlib> 

using namespace std;

namespace memory_game
{
    Game::Game(int gridSize)
    {
        this->gridSize = gridSize;
        board = Board(gridSize);
        status = GameStatus::NOT_STARTED;
    }

    Game::Game()
    {
        gridSize = 4;
        board = Board(gridSize);
        status = GameStatus::NOT_STARTED;
    }

    bool Game::PlayGame()
    {
        cout << "*** Memory Game ***" << endl;
        InitializePlayers(); 
        
        do {
            SetupBoard();
            status = GameStatus::IN_PROGRESS;
            
            int turn = 0; // index of current player

            cout << "\nLet's start! The board is " << gridSize << "x" << gridSize << "." << endl;

            while (status == GameStatus::IN_PROGRESS)
            {
                // Display Info
                DisplayScore();
                DisplayBoard();

                Player& currentPlayer = players[turn];
                cout << "\n" << currentPlayer.getName() << ", it's your turn!" << endl;

                // Get First Card
                int r1, c1;
                while(true) {
                    cout << "Select your first card (row column): ";
                    if (!(cin >> r1 >> c1)) {
                         cout << "Invalid input. Please enter numbers." << endl;
                         cin.clear();
                         ClearInputBuffer();
                         continue;
                    }
                    r1--; c1--; 
                    
                    if (!IsValidPosition(r1, c1)) {
                        cout << "Invalid position. Try again." << endl;
                        continue;
                    }
                    int idx1 = r1 * gridSize + c1;
                    if (board.GetFaceUp(idx1)) {
                        cout << "Card is already revealed. Pick another." << endl;
                        continue;
                    }
                    break;
                }
                
                // Reveal first card
                int idx1 = r1 * gridSize + c1;
                board.SetFaceUp(idx1, true);
                DisplayBoard();

                // Get Second Card
                int r2, c2;
                while(true) {
                    cout << "Select your second card (row column): ";
                    if (!(cin >> r2 >> c2)) {
                         cout << "Invalid input. Please enter numbers." << endl;
                         cin.clear();
                         ClearInputBuffer();
                         continue;
                    }
                    r2--; c2--; 
                    
                    if (!IsValidPosition(r2, c2)) {
                        cout << "Invalid position. Try again." << endl;
                        continue;
                    }
                    if (r1 == r2 && c1 == c2) {
                        cout << "You cannot pick the same card twice!" << endl;
                        continue;
                    }
                    int idx2 = r2 * gridSize + c2;
                    if (board.GetFaceUp(idx2)) {
                        cout << "Card is already revealed. Pick another." << endl;
                        continue;
                    }
                    break;
                }

                // Reveal second card
                int idx2 = r2 * gridSize + c2;
                board.SetFaceUp(idx2, true);
                DisplayBoard();

                // Check Match
                if (board.isMatch(r1, c1, r2, c2)) {
                    cout << "Congratulations " << currentPlayer.getName() << "! You found a pair!" << endl;
                    currentPlayer.AddOneToScore();
                    turn = (turn + 1) % players.size(); 
                }
                else {
                    cout << "Sorry " << currentPlayer.getName() << ", the cards do not match." << endl;
                    // Hide again
                    board.SetFaceUp(idx1, false);
                    board.SetFaceUp(idx2, false);
                    turn = (turn + 1) % players.size();
                }

                // Check Game Over
                if (board.isComplete()) {
                    status = GameStatus::COMPLETED;
                }
            }

            DisplayGameResults();

        } while (PlayAgain());

        cout << "Thanks for playing!" << endl;
        return true;
    }

    void Game::InitializePlayers()
    {
        int numPlayers = 2; 
        players.clear();

        for (int i = 0; i < numPlayers; ++i)
        {
            string name;
            cout << "Enter name for Player " << (i + 1) << ": ";
            if (cin.peek() == '\n') cin.ignore(); 
            getline(cin, name);
            if(name.empty()) name = "Player " + to_string(i+1);
            players.push_back(Player(name));
        }
    }

    void Game::SetupBoard()
    {
        board.Reset(); 
        board.Shuffle(); 
    }

    void Game::DisplayBoard() const
    {
        board.Display();
    }

    void Game::DisplayScore() const
    {
        cout << "\nScores:" << endl;
        for (const auto& player : players)
        {
            cout << player.getName() << ": " << player.getScore() << " pairs" << endl;
        }
    }

    bool Game::IsValidPosition(int row, int column) const
    {
        return row >= 0 && row < gridSize && column >= 0 && column < gridSize;
    }

    void Game::DisplayGameResults() const
    {
        cout << "\n*** Game Over ***" << endl;
        cout << "Final Scores:" << endl;
        int maxScore = -1;
        string winnerName;
        bool tie = false;

        for (const auto& player : players)
        {
            cout << player.getName() << ": " << player.getScore() << endl;
            if (player.getScore() > maxScore) {
                maxScore = player.getScore();
                winnerName = player.getName();
                tie = false;
            } else if (player.getScore() == maxScore) {
                tie = true;
            }
        }

        if (tie) cout << "It's a tie!" << endl;
        else cout << "Congratulations " << winnerName << "! You won!" << endl;
    }

    bool Game::PlayAgain() const
    {
        cout << "\nWould you like to play again? (y/n): ";
        char choice;
        cin >> choice;
        return (tolower(choice) == 'y');
    }

    void Game::ClearInputBuffer() const
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}