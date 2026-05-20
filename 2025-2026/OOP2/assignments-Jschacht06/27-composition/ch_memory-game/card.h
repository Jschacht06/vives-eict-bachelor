#pragma once
#include <string>
namespace memory_game
{
    class Card
    {
    // attributes
    private:
     char value;
     bool faceUp = false;
    //constructors
    public:
        Card();
        Card(char value);
    //methods
    public:
        char getValue() const;
        void setValue(char value);
        bool getFaceUp() const;
        void setFaceUp(bool faceUp);
        bool isMatch(Card otherCard) const;
        
    };
}
