#include <iostream>
#include <sstream>

#include "Date.hpp"
#include "Keyboard.hpp"

using std::cout;
using std::endl;

const std::string MENU [] =
{
    "Default Constructor",
    "Copy Constructor",
    "Param Constructor",
    "Get Day, Month, Year",
    "Date In Days",
    "Day of Week",
    "Day of Week String",
    "Set Day, Month, Year",
    "To String",
    "To String Dynamic",
    "Days in Month",
    "Is Leap Year",
    "Now",
    "In Stream",
    "Operators"
};

void default_constructor (xy::Date & date);
void copy_constructor (xy::Date & date);
void param_constructor (xy::Date & date);
void get_dmy (xy::Date & date);
void date_in_days (xy::Date & date);
void day_of_weeks (xy::Date & date);
void day_of_week_string (xy::Date & date);
void set_dmy (xy::Date & date);
void to_string (xy::Date & date);
void to_string_dynamic (xy::Date & date);
void days_in_month (xy::Date & date);
void is_leap_year (xy::Date & date);
void now (xy::Date & date);
void in_stream (xy::Date & date);
void operators (xy::Date & date);

int main (int argc, const char ** argv)
{
    xy::Date date;
    std::string title = "Date Test";

    int choice = -1;
    while (choice != 0)
    {
        choice = keyboard::menu_input (title, MENU, keyboard::get_array_length (MENU));

        switch (choice)
        {
            case 1:  default_constructor (date); break;
            case 2:  copy_constructor (date);    break;
            case 3:  param_constructor (date);   break;
            case 4:  get_dmy (date);             break;
            case 5:  date_in_days (date);        break;
            case 6:  day_of_weeks (date);        break;
            case 7:  day_of_week_string (date);  break;
            case 8:  set_dmy (date);             break;
            case 9:  to_string (date);           break;
            case 10: to_string_dynamic (date);   break;
            case 11: days_in_month (date);       break;
            case 12: is_leap_year (date);        break;
            case 13: now (date);                 break;
            case 14: in_stream (date);           break;
            case 15: operators (date);
        }
    }

    return 0;
}

void default_constructor (xy::Date & date)
{
    cout << xy::Date () << endl;
}

void copy_constructor (xy::Date & date)
{
    xy::Date date2 (date);
    cout << date2 << endl;
}

void param_constructor (xy::Date & date)
{
    xy::Date date2 (2019, 74, -24);
    cout << date2 << endl;
}

void get_dmy (xy::Date & date)
{
    cout << date.get_day () << "," << date.get_month () << "," << date.get_year () << endl;
}

void date_in_days (xy::Date & date)
{
    cout << date.date_in_days () << endl;
}

void day_of_weeks (xy::Date & date)
{
    cout << date.get_day_of_week () << endl;
}

void day_of_week_string (xy::Date & date)
{
    cout << date.get_day_of_week_string () << endl;
}

void set_dmy (xy::Date & date)
{
    date.set_day (11);
    date.set_month (12);
    date.set_year (2013);
    cout << date << endl;
}

void to_string (xy::Date & date)
{
    cout << date.to_string () << endl;
}

void to_string_dynamic (xy::Date & date)
{
    cout << "DMY : " << date.to_string ("%d_%d_%d", xy::DateStyle::DMY) << endl;
    cout << "DYM : " << date.to_string ("%d_%d_%d", xy::DateStyle::DYM) << endl;
    cout << "MDY : " << date.to_string ("%d_%d_%d", xy::DateStyle::MDY) << endl;
    cout << "MYD : " << date.to_string ("%d_%d_%d", xy::DateStyle::MYD) << endl;
    cout << "YDM : " << date.to_string ("%d_%d_%d", xy::DateStyle::YDM) << endl;
    cout << "YMD : " << date.to_string ("%d_%d_%d", xy::DateStyle::YMD) << endl;
}

void days_in_month (xy::Date & date)
{
    cout << date.days_in_month () << endl;
}

void is_leap_year (xy::Date & date)
{
    cout << (date.is_leap_year () ? "Yes" : "No") << endl;
}

void now (xy::Date & date)
{
    cout << xy::Date::now () << endl;
}

void in_stream (xy::Date & date)
{
    cout << "Enter date : ";
    std::cin >> date;
    cout << date << endl;
}

void operators (xy::Date & date)
{
    date = xy::Date::now ();
    cout << "=        : " << date << endl;
    cout << "==       : " << (date == xy::Date::now ()) << endl;
    cout << "!=       : " << (date == xy::Date::now ()) << endl;
    cout << "<        : " << (date < xy::Date::now ()) << endl;
    cout << "<=       : " << (date <= xy::Date::now ()) << endl;
    cout << ">        : " << (date > xy::Date::now ()) << endl;
    cout << ">=       : " << (date >= xy::Date::now ()) << endl;
    cout << "+        : " << date + 1 << endl;
    cout << "+=       : " << (date += 1) << endl;
    cout << "++ (pre) : " << ++ date << endl;
    cout << "++       : " << date ++ << endl;
    cout << "-        : " << date - xy::Date::now () << endl;
    cout << "-        : " << date - 1 << endl;
    cout << "-=       : " << (date -= 1) << endl;
    cout << "-- (pre) : " << -- date << endl;
    cout << "--       : " << date -- << endl;
}