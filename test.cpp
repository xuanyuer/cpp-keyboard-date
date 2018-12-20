#include <iostream>
#include <sstream>

#include "Date.hpp"
#include "Keyboard.hpp"

using std::cout;
using std::endl;

int main (int argc, const char ** argv)
{
    std::string menu [] =
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

    xy::Date date;
    int choice = -1;
    while (choice != 0)
    {
        choice = keyboard::menuInput ("Date Test", menu, 15);

        switch (choice)
        {
            case 1:
            {
                cout << xy::Date () << endl;
            }
            break;

            case 2:
            {
                xy::Date date2 (date);
                cout << date2 << endl;
            }
            break;
                
            case 3:
            {
                xy::Date date2 (2019, 74, -24);
                cout << date2 << endl;
            }
            break;
                
            case 4:
            {
                cout << date.get_day () << "," << date.get_month () << "," << date.get_year () << endl;
            }
            break;
                
            case 5:
            {
                cout << date.date_in_days () << endl;
            }
            break;
                
            case 6:
            {
                cout << date.get_day_of_week () << endl;
            }
            break;
                
            case 7:
            {
                cout << date.get_day_of_week_string () << endl;
            }
            break;
                
            case 8:
            {
                date.set_day (11);
                date.set_month (12);
                date.set_year (2013);
                cout << date << endl;
            }
            break;
                
            case 9:
            {
                cout << date.to_string () << endl;
            }
            break;
                
            case 10:
            {
                cout << date.to_string ("%d_%d_%d", xy::DateFormat::DAY, xy::DateFormat::MONTH, xy::DateFormat::YEAR) << endl;
            }
            break;
                
            case 11:
            {
                cout << date.days_in_month () << endl;
            }
            break;
                
            case 12:
            {
                cout << (date.is_leap_year () ? "Yes" : "No") << endl;
            }
            break;
            
            case 13:
            {
                cout << xy::Date::now () << endl;
            }
            break;
                
            case 14:
            {
                std::istringstream iss (keyboard::readString ("Enter date : "));
                iss >> date;
                cout << date << endl;
            } 
            break;

            case 15:
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
        }

        cout << endl;
    }

    return 0;
}