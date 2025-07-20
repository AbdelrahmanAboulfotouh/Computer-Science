#include <iostream>
#include <assert.h>
using namespace std;

class Date{
    int Day;
    int Month{};
    int Year{};
public:
    Date(int day,int month,int year):Day(day),Month(month),Year(year){}
    string print(short int format = 0)
    {
        assert(format < 3);
        string date ;
        if(format == 0)
            date = to_string(Day) + "," + to_string(Month) + "," + to_string(Year);
        else if(format == 1)
            date = to_string(Month) + "," + to_string(Day) + "," + to_string(Year);
        else if (format == 2)
            date = to_string(Year) + "," + to_string(Month) + "," + to_string(Month);



        return date;
    }
    int Days_of_month();
    int Days_of_year();
    bool is_leap();
    Date minus_days(int days);
    Date minus_years(int years);
    Date minus_monthes(int monthes);
    Date minus_weeks(int weeks);
};
class Time{
    int Hour;
    int Minute{};
    int Second{};
public:
    Time(int day,int month,int year):Hour(day),Minute(month),Second(year){}
    string print()
    {
        string time = to_string(Hour) + "," + to_string(Minute) + "," + to_string(Second);
        return time;
    }
};