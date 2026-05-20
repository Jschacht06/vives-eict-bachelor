#pragma once
#include <string>
namespace memory_game
{
class Player
{
    // attributes
    private:
     std::string name;
     int score = 0;
    //constructors
    
    public:
        Player();
        Player(const std::string& name);
    //methods
    public:
        std::string getName() const;
        void setName(const std::string& name);
        int getScore() const;
        void SetScore(int score);
        void AddOneToScore();
};

}