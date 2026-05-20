# Changing array values

What is going on here? Why can the `messItUp` function change the values of the passed array?

Because we dont pass an array by value but with pointers, this means we dont create a copy of the data like we usually do we use a "pointer" towards that actual value so if you change it inside the function you also change the value outside the function.
```cpp
#include <iostream>
using namespace std;

void messItUp(int numbers[], size_t size) {
  for (unsigned int i = 0; i < size; i++) {
    numbers[i] = numbers[i] * 1337;
  }
}

int main() {

  int numbers[] = { 2, 8, 15 };

  messItUp(numbers, sizeof(numbers)/sizeof(numbers[0]));

  for (unsigned int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;

  return 0;
}
```
