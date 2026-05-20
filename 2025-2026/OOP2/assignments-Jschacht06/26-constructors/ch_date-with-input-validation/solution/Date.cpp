#include "Date.h"
#include <stdexcept>
#include <iomanip>
#include <sstream>

namespace DateLib
{
    Date::Date(void)
    {
    }
    Date::Date(int day)
    {
        setDay(day);
    }
    Date::Date(int day, int month)
    {
        setDay(day);
        setMonth(month);
    }
    Date::Date(int day, int month, int year)
    {
        setDay(day);
        setMonth(month);
        setYear(year);
    }
    Date::~Date(void)
    {
    }
    void Date::setDay(int day)
    {
        if (day < 1 || day > 31)
        {
            throw std::invalid_argument("Day must be between 1 and 31");
        }
        this->day = day;
    }
    void Date::setMonth(int month)
    {
        if (month < 1 || month > 12)
        {
            throw std::invalid_argument("Month must be between 1 and 12");
        }
        this->month = month;
    }
    void Date::setYear(int year)
    {
        if (year < 1)
        {
            throw std::invalid_argument("Year must be greater than 0"); // simple validation, just to
        }
        this->year = year;
    }
    std::string Date::getString(void) const
    {
        std::stringstream ss;

        // Format: DD/MM/YYYY with leading zeros
        ss << std::setw(2) << std::setfill('0') << day << "/"
           << std::setw(2) << std::setfill('0') << month << "/"
           << std::setw(4) << std::setfill('0') << year;

        return ss.str();
    }

}