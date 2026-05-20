#include "die.h"

namespace die
{
  Die::Die(int sides)
      : sides(sides)
  {
  }

  int Die::roll() const
  {
    return (rand() % sides) + 1;
  }
}
