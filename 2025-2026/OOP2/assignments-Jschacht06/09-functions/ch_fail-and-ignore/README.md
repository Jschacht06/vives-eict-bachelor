# Fail and ignore

The code snippet belows reads a number from the user between `1` and `10`. However if the user provides an unparsable value, such as a string, the application becomes unusable. Fix this by using the `cin` functions `fail()`, `clear()` and `ignore()`.

```cpp
#include <iostream>

using namespace std;

int main() {

  int number = 0;
  do {
    cout << "Please enter a number between 1 and 10: ";
    cin >> number;
    
  } while (number < 1 || number > 10);

  return 0;
}
```


Solution
```cpp
#include <iostream>

using namespace std;

int main() {

  int number = 0;
  do {
    cout << "Please enter a number between 1 and 10: ";
    cin >> number;
    if (cin.fail()) {
        cin.clear(); // clear the fail state
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number." << endl;
    }
  } while (number < 1 || number > 10);

  return 0;
}
```