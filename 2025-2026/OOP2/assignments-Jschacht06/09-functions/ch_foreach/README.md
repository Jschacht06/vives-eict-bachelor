# Foreach

What is wrong with the code below?
Not possible to loop thru the raw values of the array we need to define its size and make a for loop adding each value individually 

```cpp
#include <iostream>
using namespace std;

int sum(int values[]) {
  int result = 0;
  for(auto value : values) {
    result += value;
  }
  return result;
}

int main() {

  int numbers[] = { 2, 8, 15 };

  cout << "Sum of numbers: "
    << sum(numbers) << endl;

  return 0;
}
```

Solution:
```cpp
#include <iostream>
using namespace std;

int sum(int values[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += values[i];
    }
    return result;
}

int main() {

  int numbers[] = { 2, 8, 15 };

  cout << "Sum of numbers: "
    << sum(numbers, sizeof(numbers) / sizeof(numbers[0])) << endl;

  return 0;
}
```