#pragma once
#include <string>
#include "Date.h"

namespace AnimalTree
{
  class Cat
  {
    // attributes
  private:
  std::string name = "";
  std::string food = "";
  DateLib::Date birthDate;
  int numberOfLegs = 4;

    // constructors
  public:
    Cat(std::string name, std::string food, DateLib::Date birthdate);
    Cat(std::string name, std::string food, int birthDay, int birthMonth, int birthYear);

    // Destructor
    ~Cat();

    // methods
    public:
      std::string getSound();
      std::string getString();
  

  };
};