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