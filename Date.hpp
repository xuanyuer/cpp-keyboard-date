enum DateFormat
{
    DAY,
    MONTH,
    YEAR
};

enum Month
{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

class Date
{
    public:
        // Constructors
        Date ();
        Date (int year, int month, int day);

        // Accessors
        int getDay () const;
        int getMonth () const;
        int getYear () const;

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
        int dateInDays () const;

        // Overloaded operators
        Date & operator = (const Date & date);
        bool operator < (const Date & date);
        bool operator <= (const Date & date);
        bool operator > (const Date & date);
        bool operator >= (const Date & date);
        bool operator == (const Date & date);
        bool operator != (const Date & date);
        Date & operator + (int days);
        Date & operator += (int days);
        int operator - (const Date & date);

    private:
        int day;
        int month;
        int year;

        void adjustMonths ();
        void adjustDays ();
};