#pragma once
#include <cstdlib>

namespace die
{
  class Die
  {
    // attributes
  private:
    int sides = 0;
    // constructors
  public:
    Die(int sides);
    // methods
  public:
    int roll() const;
  };
}