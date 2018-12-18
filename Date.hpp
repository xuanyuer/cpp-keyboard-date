/*
 * File Name   : Date.hpp
 * Author      : Er Xuan Yu
 * Description : Header file for Date.cpp, a Date class for handling of simple date arithmetics.
 */

enum DateFormat;
enum DayOfWeek;
enum Month;

class Date
{
    public:
        // Constructors
        Date ();
        Date (const Date & date);
        Date (int year, int month, int day);

        // Accessors
        int getDay () const;
        int getMonth () const;
        int getYear () const;
        int dateInDays () const;
        int getDayOfWeek () const;

        // Mutators
        void setDay (int day);
        void setMonth (int month);
        void setYear (int year);

        // To String
        std::string toString () const;
        std::string toString (const std::string & format, DateFormat arg1, DateFormat arg2, DateFormat arg3) const;

        // Helpers
        void parseDate (int year, int month, int day);
        int daysInMonth () const;
        bool isLeapYear () const;
        void adjustMonths ();
        void adjustDays ();

        // Overload Equality Operators
        Date & operator = (const Date & date);
        bool operator == (const Date & date);
        bool operator != (const Date & date);

        // Overload Comparator Operators
        bool operator < (const Date & date);
        bool operator <= (const Date & date);
        bool operator > (const Date & date);
        bool operator >= (const Date & date);

        // Overload Increment Operators
        Date operator + (int days);
        Date & operator += (int days);
        Date & operator ++ ();

        // Overload Decrement Operators
        int operator - (const Date & date);
        Date operator - (int days);
        Date & operator -= (int days);
        Date & operator -- ();

    private:
        int day;
        int month;
        int year;
        
        // Stream operator
        friend std::ostream & operator << (std::ostream & out, const Date & date);
};

std::ostream & operator << (std::ostream & out, const Date & date);