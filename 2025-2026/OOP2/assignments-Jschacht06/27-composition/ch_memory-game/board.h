#pragma once
#include <vector>
#include <string>
#include "card.h"

namespace memory_game 
{
    class Board 
    {
    private:
        std::vector<Card> cards;
        int size;

    public:
        Board(int size);
        Board();

        void Display() const;
        void SetSize(int size);
        int GetSize() const;
        void SetCard(int index, Card card);
        Card GetCard(int index) const;
        
        void SetFaceUp(int index, bool faceUp);
        bool GetFaceUp(int index) const;
        
        void SetCardValue(int index, char value);
        char GetCardValue(int index) const;
        
        
        bool isMatch(int r1, int c1, int r2, int c2) const;
        bool isComplete() const;
        void Reset();
        void Shuffle();
    };
}