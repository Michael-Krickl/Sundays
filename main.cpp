#include <iostream>
#include <math.h>

using namespace std;

int calcDays(int fromDay, int fromMonth, int fromYear, int toDay, int toMonth, int toYear);
int calcMonthDays(int month, int year);

int main()
{
    cout << floor(calcDays(1, 1, 1900, 31, 12, 2000)/ 7) << " total Sundays from 1/1/1900 to 31/12/2000" << endl;
}

int calcDays(int fromDay, int fromMonth, int fromYear, int toDay, int toMonth, int toYear)
{
    int day = fromDay,
        month = fromMonth,
        year = fromYear,
        monthlyDays,
        days = 0;

    monthlyDays = calcMonthDays(month, year);
    if(monthlyDays < 0) return -1;

    while(year != toYear || month != toMonth || day != toDay)
    {
        ++day;
        ++days;

        if(day > monthlyDays)
        {
            day = 1;
            ++month;

            if(month > 12)
            {
                month = 1;
                ++year;
            }

            monthlyDays = calcMonthDays(month, year);
            if(monthlyDays < 0) return -1;
        }
    }

    return days;
}

int calcMonthDays(int month, int year)
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        case 2: return (year % 4 == 0) || (year % 100 == 0 && year % 400) ? 29 : 28;
        default: cout << "Illegal Month" << endl;
            return -1;
    }
}
