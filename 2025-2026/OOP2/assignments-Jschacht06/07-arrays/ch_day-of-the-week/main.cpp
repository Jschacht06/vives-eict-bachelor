#include <iostream>

using namespace std;

int main() {

  unsigned int dayOfTheWeek = 0;
  const string days[] = {
      "Monday", "Tuesday", "Wednesday", 
      "Thursday", "Friday", "Saturday", "Sunday"
    };
  do {
    cout << "Please enter the day of the week (1 - 7): ";
    cin >> dayOfTheWeek;
  } while (dayOfTheWeek < 1 || dayOfTheWeek > 7);
  cout << "Then it's " << days[dayOfTheWeek - 1] << " today" << endl;

  return 0;
}