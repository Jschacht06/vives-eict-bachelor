#pragma once
#include "Cat.h"
#include "Date.h"
#include <sstream>

namespace AnimalTree
{
  Cat::Cat(std::string name, std::string food, DateLib::Date birthDate)
      : name(name), food(food), birthDate(birthDate), numberOfLegs(4)
  {
  }
  Cat::Cat(std::string name, std::string food, int birthDay, int birthMonth, int birthYear)
      : name(name), food(food), birthDate(birthDay, birthMonth, birthYear), numberOfLegs(4)
  {
  }
  Cat::~Cat() {}

  std::string Cat::getSound()
  {
    return "Sound: Miauw!!!";
  }

  std::string Cat::getString()
  {
    std::stringstream ss;
    ss << "Name: " << name
       << ", birthdate: " << birthDate.getString()
       << ", number of legs: " << numberOfLegs
       << ", food: " << food;
    return ss.str();
  }
}
