#include "player.h"

namespace memory_game
{
    Player::Player(const std::string& name)
    {
        setName(name);
    }
    Player::Player()
    {
        name = "Player";
    }

    std::string Player::getName() const
    {
        return name;
    }

    void Player::setName(const std::string& name)
    {
        this->name = name;
    }
    int Player::getScore() const
    {
        return score;
    }
    void Player::SetScore(int score)
    {
        this->score = score;
    }
    void Player::AddOneToScore()
    {
        score += 1;
    }
    
}