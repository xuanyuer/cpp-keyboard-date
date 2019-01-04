/*
 * File Name   : Date.hpp
 * Author      : xyer24@outlook.com
 * Description : Header file for Date.cpp, a Date class for handling of simple date arithmetics.
 */

#ifndef DATE_H
#define DATE_H

namespace xy
{
    enum DateStyle
    {
        DMY, DYM, MDY, MYD, YDM, YMD
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
            int         get_day                () const;
            int         get_day_of_week        () const;
            std::string get_day_of_week_string () const;
            int         get_month              () const;
            std::string get_month_string       () const;
            int         get_year               () const;

            // Mutators
            void set_day   (int day);
            void set_month (int month);
            void set_year  (int year);

            // To String
            std::string to_string () const;
            std::string to_string (const std::string & format, DateStyle style) const;

            // Helpers
            int         date_in_days  () const;
            int         days_in_month () const;
            bool        is_leap_year  () const;
            static Date now           ();
            void        parse_date    (int year, int month, int day);

            // Overload Equality Operators
            bool   operator == (const Date & date);
            bool   operator != (const Date & date);
            Date & operator =  (const Date & date);

            // Overload Comparator Operators
            bool operator <  (const Date & date);
            bool operator <= (const Date & date);
            bool operator >  (const Date & date);
            bool operator >= (const Date & date);

            // Overload Increment Operators
            Date   operator +  (int days);
            Date & operator ++ ();
            Date   operator ++ (int);
            Date & operator += (int days);

            // Overload Decrement Operators
            int    operator -  (const Date & date);
            Date   operator -  (int days);
            Date & operator -- ();
            Date   operator -- (int);
            Date & operator -= (int days);

        private:
            int day;
            int month;
            int year;
            
            // Adjustment Methods
            void adjust_days   ();
            void adjust_months ();

            // Stream operators
            friend std::ostream & operator << (std::ostream & out, const Date & date);
            friend std::istream & operator >> (std::istream & in, Date & date);
    };
}

#endif