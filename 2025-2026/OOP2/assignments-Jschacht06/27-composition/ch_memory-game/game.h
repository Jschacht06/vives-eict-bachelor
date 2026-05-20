#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "board.h"
#include "player.h"

namespace memory_game
{
    class Game
    {
    public:
        enum class GameStatus { NOT_STARTED, IN_PROGRESS, COMPLETED };

    private:
        int gridSize;
        std::vector<Player> players;
        Board board;
        GameStatus status;

    public:
        Game(int gridSize);
        Game();

        bool PlayGame();
        void InitializePlayers();
        void SetupBoard();
        void DisplayBoard() const;
        void DisplayScore() const;
        bool IsValidPosition(int row, int column) const;
        void DisplayGameResults() const;
        bool PlayAgain() const;
        void ClearInputBuffer() const;
    };
}