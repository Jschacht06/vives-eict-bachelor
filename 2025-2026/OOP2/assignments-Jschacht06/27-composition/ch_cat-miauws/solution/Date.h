#pragma once
#include <string>
namespace DateLib
{
    class Date
    {
        // attributes
    private:
        int day = 1;
        int month = 10;
        int year = 2025;

        // constructors
    public:
        Date(void);
        Date(int day);
        Date(int day, int month);
        Date(int day, int month, int year);
        ~Date(void);

        // methods
    public:
        std::string getString(void) const;
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
    };

};
