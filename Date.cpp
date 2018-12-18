/*
 * File Name   : Date.cpp
 * Author      : Er Xuan Yu
 * Description : Implementation of Date.hpp, a Date class for handling of simple date arithmetics.
 */

#include <sstream>

#include "Date.hpp"

// ------------------------------ Enums ------------------------------

enum DateFormat
{
    DAY, MONTH, YEAR
};

enum DayOfWeek
{
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

enum Month
{
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
    AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

// ------------------------------ Constructors ------------------------------

Date::Date ()
{
    // Defaults date to January 1, 1970
    this -> year = 1970;
    this -> month = JANUARY;
    this -> day = 1;
}

Date::Date (const Date & date)
{
    this -> day = date.getDay ();
    this -> month = date.getMonth ();
    this -> year = date.getYear ();
}

Date::Date (int year, int month, int day)
{
    parseDate (year, month, day);
}

// ------------------------------ Accessors ------------------------------

int Date::getDay () const
{
    return this -> day;
}

int Date::getMonth () const
{
    return this -> month;
}

int Date::getYear () const
{
    return this -> year;
}

int Date::dateInDays () const
{
    int m = (this -> month + 9) % 12;
    int y = this -> year - m / 10;
    return (365 * y) + (y / 4) - (y / 100) + (y / 400) + ((m * 306 + 5) / 10) + (this -> day - 1);
}

int Date::getDayOfWeek () const
{
    // Credits to sakamoto@sm.sony.co.jp (Tomohiko Sakamoto) on comp.lang.c
    static int t [] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    
    int y = this -> year;
    y -= this -> month < 3;
    
    // 0 for Sunday, 6 for Saturday
    return (y + y / 4 - y / 100 + y / 400 + t [this -> month - 1] + this -> day) % 7;
}

// ------------------------------ Mutators ------------------------------

void Date::setDay (int day)
{
    this -> day = day;
}

void Date::setMonth (int month)
{
    this -> month = month;
}

void Date::setYear (int year)
{
    this -> year = year;
}

// ------------------------------ Helpers ------------------------------

void Date::parseDate (int year, int month, int day)
{
    /*
     * Converts date values into a valid date
     * Invalid month will be adjusted accordingly,
     * followed by invalid day
     * After which year < 1 will be considered as year 1
     */

    this -> year = year;
    this -> month = month;
    this -> day = day;

    adjustMonths ();
    adjustDays ();

    if (this -> year < 1) this -> year = 1;
}

int Date::daysInMonth () const
{
    switch (this -> month)
    {
        case APRIL:
        case JUNE:
        case AUGUST:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;
        
        case FEBRUARY:
            return isLeapYear () ? 29 : 28;

        default:
            return 31;
    }
}

bool Date::isLeapYear () const
{
    return this -> year % 400 || (this -> year % 4 == 0 && this -> year % 100 != 0);
}

void Date::adjustMonths ()
{
    // month with value 0 will be treated as 12
    if (this -> month == 0)
    {
        this -> month  = 12;
        this -> year --;
        return;
    }

    if (this -> month < 0)
    {
        this -> year -= this -> month / -12;
        this -> month %= 12;
        this -> month += 12;
        return;
    }
    
    if (month > 12)
    {
        this -> year += this -> month / 12;
        this -> month %= 12;
        return;     
    }
}

void Date::adjustDays ()
{
    while (this -> day < 1)
    {
        this -> month --;
        if (this -> month == 0)
        {
            this -> month = 12;
            this -> year --;
        }
        this -> day += daysInMonth ();
    }

    while (this -> day > daysInMonth ())
    {
        this -> day -= daysInMonth ();
        this -> month ++;
        if (this -> month == 13)
        {
            this -> month = 1;
            this -> year ++;
        }
    }
}

// ------------------------------ To String ------------------------------

std::string Date::toString () const
{
    // Default format is YYYY-MM-DD (Y being of variable length)
    char buffer [100];
    sprintf (buffer, "%d-%02d-%02d", this -> day, this -> month, this -> year);
    return buffer;
}

std::string Date::toString (const std::string & format, DateFormat arg1, DateFormat arg2, DateFormat arg3) const
{
    char buffer [100];
    sprintf (buffer, format.c_str (),
             arg1 == DAY ? this -> day : (arg1 == MONTH ? this -> month : this -> year),
             arg2 == DAY ? this -> day : (arg2 == MONTH ? this -> month : this -> year),
             arg3 == DAY ? this -> day : (arg3 == MONTH ? this -> month : this -> year));
    return buffer;
}

// ------------------------------ Overload Equality Operators ------------------------------

Date & Date::operator = (const Date & date)
{
    return *this = Date (date);
}

bool Date::operator == (const Date & date)
{
    return this -> year == date.getYear () &&
            this -> month == date.getMonth () &&
            this -> day == date.getDay ();
}

bool Date::operator != (const Date & date)
{
    return !(*this == date);
}

// ------------------------------ Overload Comparator Operators ------------------------------

bool Date::operator < (const Date & date)
{
    return this -> year < date.getYear () ||
            (this -> year == date.getYear () && this -> month < date.getMonth ()) ||
            (this -> year == date.getYear () && this -> month == date.getMonth () && this -> day < date.getDay ());
}

bool Date::operator <= (const Date & date)
{
    return *this < date || *this == date;
}

bool Date::operator > (const Date & date)
{
    return !(*this <= date);
}

bool Date::operator >= (const Date & date)
{
    return !(*this < date);
}

// ------------------------------ Overload Increment Operators ------------------------------

Date Date::operator + (int days)    // Add days
{
    Date date (*this);

    date.setDay (date.getDay () + days);
    date.adjustDays ();

    return date;
}

Date & Date::operator += (int days)
{
    *this = Date (*this + days);
    return *this;
}

Date & Date::operator ++ ()
{
    *this = Date (*this + 1);
    return *this;
}

// ------------------------------ Overload Decrement Operators ------------------------------

int Date::operator - (const Date & date)    // Minus days
{
    // Returns this difference in days
    return this -> dateInDays () - date.dateInDays ();
}

Date Date::operator - (int days)
{
    Date date (*this);

    date.setDay (date.getDay () - days);
    date.adjustDays ();

    return date;
}

Date & Date::operator -= (int days)
{
    *this = Date (*this - days);
    return *this;
}

Date & Date::operator -- ()
{
    *this = Date (*this - 1);
    return *this;
}

// ------------------------------ Stream Operator ------------------------------

std::ostream & operator << (std::ostream & out, const Date & date)
{
    return out << date.day << "/" << date.month << "/" << date.year;
}