#include "card.h"

namespace memory_game
{
    Card::Card(char value)
    {
        setValue(value);
        this->faceUp = false;
    }

    Card::Card()
    {
        value = ' ';
        faceUp = false;
    }

    char Card::getValue() const
    {
        return value;
    }

    void Card::setValue(char value)
    {
        this->value = value;
    }

    bool Card::getFaceUp() const
    {
        return faceUp;
    }

    void Card::setFaceUp(bool faceUp)
    {
        this->faceUp = faceUp;
    }

    bool Card::isMatch(Card otherCard) const
    {
        return this->value == otherCard.value;
    }
}