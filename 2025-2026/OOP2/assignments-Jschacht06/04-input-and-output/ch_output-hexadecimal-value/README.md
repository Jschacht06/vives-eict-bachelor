# Output hexadecimal value

Can you alter the next code snippet so the number is outputted in hexadecimal format, with a leading `0x` and a width of 4 hexadecimal digits? Note that this will require the `iomanip` library to be included (already done for you).

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int number = 23;

    cout << "Number in hex format: 0x"
         << setfill('0') << setw(4) << hex << number << endl;

    return 0;
}
// info found at https://cplusplus.com/reference/iomanip/setiosflags/
```

The expected output is:

```text
Number in hex format: 0x0017
```