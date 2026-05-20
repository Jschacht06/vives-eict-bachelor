# Define a variable for age

How would you define a variable to store the age of a person in? Make sure to give it an appropriate name. Explain why you choose that exact data type.

I would use an integer because its the default data type for numbers. You can use unsigned int because an age cannot be negative but since it is still the same size you are safer using an int. 
If your are tight on memory you can use a short since that also covers more then every age possible.
Examples:

```cpp
#include <iostream>

using namespace std;

int main() {
  // Display Hello world! in the terminal
  cout << "Hello world!" << endl;

  int age = 0;
  unsigned int age2 = 0;
  unsigned short age3 = 0;

  return 0;
}

