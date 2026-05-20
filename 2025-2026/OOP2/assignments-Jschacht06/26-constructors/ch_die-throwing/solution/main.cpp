#include "die.h"
#include <iostream>
#include <ctime> // nodig voor verschillende nummers na elke executie

using namespace std;
using namespace die;

int main(int argc, char const *argv[])
{
  srand(time(nullptr)); // nodig voor verschillende nummers na elke executie
  Die sixEyes(6);
  cout << "Rolling...." << endl;
  cout << sixEyes.roll() << endl;
  cout << "Rolling again...." << endl;
  cout << sixEyes.roll() << endl;
  Die twentyEyes(20);
  cout << "Rolling...." << endl;
  cout << twentyEyes.roll() << endl;
  cout << "Rolling again...." << endl;
  cout << twentyEyes.roll() << endl;



}