/*
 * File Name   : Date.cpp
 * Author      : Er Xuan Yu
 * Description : Implementation of Date.hpp, a Date class for handling of simple date arithmetics.
 */

#include <ctime>
#include <sstream>

#include "Date.hpp"

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
    this -> day = date.get_day ();
    this -> month = date.get_month ();
    this -> year = date.get_year ();
}

Date::Date (int year, int month, int day)
{
    parse_date (year, month, day);
}

// ------------------------------ Accessors ------------------------------

int Date::get_day () const
{
    return this -> day;
}

int Date::get_month () const
{
    return this -> month;
}

int Date::get_year () const
{
    return this -> year;
}

int Date::date_in_days () const
{
    int m = (this -> month + 9) % 12;
    int y = this -> year - m / 10;
    return (365 * y) + (y / 4) - (y / 100) + (y / 400) + ((m * 306 + 5) / 10) + (this -> day - 1);
}

int Date::get_day_of_week () const
{
    // Credits to sakamoto@sm.sony.co.jp (Tomohiko Sakamoto) on comp.lang.c
    // Returns 0 - 6, 0 being Sunday
    static int t [] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    
    int y = this -> year - this -> month < 3;
    return (y + y / 4 - y / 100 + y / 400 + t [this -> month - 1] + this -> day) % 7;
}

std::string Date::get_day_of_week_string () const
{
    switch (get_day_of_week ())
    {
        case SUNDAY:    return "Sunday";
        case MONDAY:    return "Monday";
        case TUESDAY:   return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY:  return "Thursday";
        case FRIDAY:    return "Friday";
        case SATURDAY:  return "Saturday";
    }
}

// ------------------------------ Mutators ------------------------------

void Date::set_day (int day)
{
    this -> day = day;
    adjust_days ();
}

void Date::set_month (int month)
{
    this -> month = month;
    adjust_months ();
}

void Date::set_year (int year)
{
    this -> year = year;
}

// ------------------------------ Helpers ------------------------------

void Date::parse_date (int year, int month, int day)
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

    adjust_months ();
    adjust_days ();

    if (this -> year < 1) this -> year = 1;
}

int Date::days_in_month () const
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
            return is_leap_year () ? 29 : 28;

        default:
            return 31;
    }
}

bool Date::is_leap_year () const
{
    return this -> year % 400 || (this -> year % 4 == 0 && this -> year % 100 != 0);
}

void Date::adjust_months ()
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

void Date::adjust_days ()
{
    while (this -> day < 1)
    {
        this -> month --;
        if (this -> month == 0)
        {
            this -> month = 12;
            this -> year --;
        }
        this -> day += days_in_month ();
    }

    while (this -> day > days_in_month ())
    {
        this -> day -= days_in_month ();
        this -> month ++;
        if (this -> month == 13)
        {
            this -> month = 1;
            this -> year ++;
        }
    }
}

Date Date::now ()
{
    std::time_t t = std::time (0);
    std::tm * now = std::localtime (&t);

    return Date (now -> tm_year + 1900, now -> tm_mon + 1, now -> tm_mday);
}

// ------------------------------ To String ------------------------------

std::string Date::to_string () const
{
    // Default format is YYYY-MM-DD (Y being of variable length)
    char buffer [100];
    sprintf (buffer, "%d-%02d-%02d", this -> year, this -> month, this -> day);
    return buffer;
}

std::string Date::to_string (const std::string & format, DateFormat arg1, DateFormat arg2, DateFormat arg3) const
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
    this -> day = date.get_day ();
    this -> month = date.get_month ();
    this -> year = date.get_year ();
    return *this;
}

bool Date::operator == (const Date & date)
{
    return  this -> year == date.get_year () &&
            this -> month == date.get_month () &&
            this -> day == date.get_day ();
}

bool Date::operator != (const Date & date)
{
    return !(*this == date);
}

// ------------------------------ Overload Comparator Operators ------------------------------

bool Date::operator < (const Date & date)
{
    return  this -> year < date.get_year () ||
            (this -> year == date.get_year () && this -> month < date.get_month ()) ||
            (this -> year == date.get_year () && this -> month == date.get_month () && this -> day < date.get_day ());
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

    date.set_day (date.get_day () + days);
    date.adjust_days ();

    return date;
}

Date & Date::operator += (int days)
{
    return *this = Date (*this + days);
}

Date & Date::operator ++ ()
{
    return *this = Date (*this + 1);
}

Date Date::operator ++ (int val)
{
    Date date (*this);
    ++ *this;
    return date;
}

// ------------------------------ Overload Decrement Operators ------------------------------

int Date::operator - (const Date & date)
{
    // Returns the difference in days
    return this -> date_in_days () - date.date_in_days ();
}

Date Date::operator - (int days)
{
    Date date (*this);

    date.set_day (date.get_day () - days);
    date.adjust_days ();

    return date;
}

Date & Date::operator -= (int days)
{
    return *this = Date (*this - days);
}

Date & Date::operator -- ()
{
    return *this = Date (*this - 1);
}

Date Date::operator -- (int val)
{
    Date date (*this);
    -- *this;
    return date;
}

// ------------------------------ Stream Operators ------------------------------

std::ostream & operator << (std::ostream & out, const Date & date)
{
    return out << date.day << "/" << date.month << "/" << date.year;
}

std::istream & operator >> (std::istream & in, Date & date)
{
    char ch;
    in >> date.year >> ch >> date.month >> ch >> date.day;
    
    date.adjust_months ();
    date.adjust_days ();

    return in;
}