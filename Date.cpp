#include <sstream>

#include "Date.hpp"

// ------------------------------ Constructors ------------------------------

Date::Date ()
{
    this -> year = 1970;
    this -> month = JANUARY;
    this -> day = 1;
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

int Date::dateInDays () const
{
    int m = (this -> month + 9) % 12;
    int y = this -> year - m / 10;
    return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (this -> day - 1);
}

// ------------------------------ To String ------------------------------

std::string Date::toString () const
{
    char buffer [100];
    sprintf (buffer, "%02d/%02d/%d", this -> day, this -> month, this -> year);
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

// ------------------------------ Overloaded Operators ------------------------------

Date & Date::operator = (const Date & date)
{
    this -> day = date.getDay ();
    this -> month = date.getMonth ();
    this -> year = date.getYear ();

    return *this;
}

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

Date & Date::operator + (int days)
{
    this -> day += days;
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

    return *this;
}

Date & Date::operator += (int days)
{
    return *this + days;
}

int Date::operator - (const Date & date)
{
    return this -> dateInDays () - date.dateInDays ();
}

// ------------------------------ Private Methods ------------------------------

void Date::adjustMonths ()
{
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