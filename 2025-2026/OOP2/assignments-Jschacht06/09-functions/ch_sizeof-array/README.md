# Sizeof array

What is happening here? Why is the output of this code snippet wrong?

We try to see the size of the array inside the function with sizeof but in the function we see the size of the pointer instead of the array which can be bigger then the array so we would try to loop thru more elements then there are available in the array.


Course:
When you pass an array to a function, the array will decay (it will be implicitly converted to a pointer that points to the first element of the array). This means that using the sizeof operator on an array passed to a function will result in the size of the pointer, which is usually 4 or 8 bytes (depending on the architecture of your machine)



```cpp
#include <iostream>
using namespace std;

int sum(int values[]) {
  int result = 0;
  for(unsigned int i = 0; i < sizeof(values); i++) {
    result += values[i];
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
Solution
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