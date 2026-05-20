#include "board.h"
#include <iostream>
#include <cstdlib> // for rand
#include <ctime>   // for time

using namespace std;

namespace memory_game
{
    Board::Board(int size)
    {
        SetSize(size);
        cards.resize(size * size);
    }

    Board::Board()
    {
        size = 4;
        cards.resize(size * size);
    }

    void Board::Display() const
    {
        cout << "   ";
        for(int k=1; k<=size; k++) cout << k << " ";
        cout << endl;

        for (int i = 0; i < size; ++i)
        {
            cout << (i+1) << " |";
            for (int j = 0; j < size; ++j)
            {
                int index = i * size + j;
                if (cards[index].getFaceUp())
                {
                    cout << cards[index].getValue() << "|";
                }
                else
                {
                    cout << " |"; // Hidden
                }
            }
            cout << endl;
            cout << "  ";
            for(int k=0; k<size*2 +1; k++) cout << "-";
            cout << endl;
        }
    }

    void Board::SetSize(int size)
    {
        this->size = size;
    }

    int Board::GetSize() const
    {
        return size;
    }

    void Board::SetCard(int index, Card card)
    {
        if(index >= 0 && index < (int)cards.size())
            cards[index] = card;
    }

    Card Board::GetCard(int index) const
    {
        return cards[index];
    }

    void Board::SetFaceUp(int index, bool faceUp)
    {
        if(index >= 0 && index < (int)cards.size())
            cards[index].setFaceUp(faceUp);
    }

    bool Board::GetFaceUp(int index) const
    {
        if(index >= 0 && index < (int)cards.size())
            return cards[index].getFaceUp();
        return false;
    }

    void Board::SetCardValue(int index, char value)
    {
        if(index >= 0 && index < (int)cards.size())
            cards[index].setValue(value);
    }

    char Board::GetCardValue(int index) const
    {
        if(index >= 0 && index < (int)cards.size())
            return cards[index].getValue();
        return ' ';
    }

    bool Board::isMatch(int r1, int c1, int r2, int c2) const
    {
        int index1 = r1 * size + c1;
        int index2 = r2 * size + c2;
        return cards[index1].isMatch(cards[index2]);
    }

    bool Board::isComplete() const
    {
        for (const auto& card : cards)
        {
            if (!card.getFaceUp())
            {
                return false;
            }
        }
        return true;
    }

    void Board::Reset()
    {
        for (auto& card : cards)
        {
            card.setFaceUp(false);
        }
    }

    void Board::Shuffle()
    {
        int totalCards = size * size;
        int numPairs = totalCards / 2;

        char currentChar = 'A';
        int cardIdx = 0;
        
        for (int i = 0; i < numPairs; ++i)
        {
            cards[cardIdx].setValue(currentChar);
            cards[cardIdx].setFaceUp(false);
            cardIdx++;
            
            cards[cardIdx].setValue(currentChar);
            cards[cardIdx].setFaceUp(false);
            cardIdx++;

            currentChar++;
        }


        for (int i = 0; i < totalCards; ++i)
        {
            int r = rand() % totalCards;
            Card temp = cards[i];
            cards[i] = cards[r];
            cards[r] = temp;
        }
    }
}