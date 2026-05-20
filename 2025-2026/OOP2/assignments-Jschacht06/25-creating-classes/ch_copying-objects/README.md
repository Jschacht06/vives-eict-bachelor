# Copying objects

What would you expect to be the output of the following code? What happens when you create a second object and initialize it with the first?


Expected Output:
First is at [10,20]
Second is at [10,20]
Moving first point to 103, 1234
First is at [103,1234]
Second is at [10,20]

If you initialize a second object with the first it will take the values of that first point at that moment in the code, if you change the first object later in the code the second object will not follow because you dont re initialize it


```cpp
// Compile using:
// g++ main.cpp point.cpp -o points

#include <iostream>
#include "Point.h"

using namespace std;

int main() {
  Geometry::Point first;
  first.moveTo(10, 20);
  cout << "First is at ["
    << first.getX() << ", " << first.getY() << "]" << endl;

  // Initialize second point with first
  Geometry::Point second = first;

  cout << "Second is at ["
    << second.getX() << ", " << second.getY() << "]" << endl;

  cout << "Moving first point to 103, 1234" << endl;
  first.moveTo(103, 1234);

  cout << "First is at ["
    << first.getX() << ", " << first.getY() << "]" << endl;

  cout << "Second is at ["
    << second.getX() << ", " << second.getY() << "]" << endl;

  return 0;
}
```
