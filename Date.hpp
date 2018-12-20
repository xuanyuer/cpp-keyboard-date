/*
 * File Name   : Date.hpp
 * Author      : Er Xuan Yu
 * Description : Header file for Date.cpp, a Date class for handling of simple date arithmetics.
 */

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

class Date
{
    public:
        // Constructors
        Date ();
        Date (const Date & date);
        Date (int year, int month, int day);

        // Accessors
        int get_day () const;
        int get_month () const;
        int get_year () const;
        int date_in_days () const;
        int get_day_of_week () const;
        std::string get_day_of_week_string () const;

        // Mutators
        void set_day (int day);
        void set_month (int month);
        void set_year (int year);

        // To String
        std::string to_string () const;
        std::string to_string (const std::string & format, DateFormat arg1, DateFormat arg2, DateFormat arg3) const;

        // Helpers
        void parse_date (int year, int month, int day);
        int days_in_month () const;
        bool is_leap_year () const;
        void adjust_months ();
        void adjust_days ();
        static Date now ();

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
        Date operator ++ (int);

        // Overload Decrement Operators
        int operator - (const Date & date);
        Date operator - (int days);
        Date & operator -= (int days);
        Date & operator -- ();
        Date operator -- (int);

    private:
        int day;
        int month;
        int year;
        
        // Stream operators
        friend std::ostream & operator << (std::ostream & out, const Date & date);
        friend std::istream & operator >> (std::istream & in, Date & date);
};