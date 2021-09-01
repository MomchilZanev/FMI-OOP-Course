#include <iostream>
#include "Date.hpp"
using namespace std;

int main()
{
    Date d1(31, 3, 2014); // 31.03.2014
    cout << d1.getDay() << '.' << d1.getMonth() << '.' << d1.getYear() << endl;
    Date d2; //01.01.2000
    cout << d2.getDay() << '.' << d2.getMonth() << '.' << d2.getYear() << endl;
    d1.addDays(1); // 01.04.2014
    cout << d1.getDay() << '.' << d1.getMonth() << '.' << d1.getYear() << endl;
    d1.removeDays(1); //31.03.2014
    cout << d1.getDay() << '.' << d1.getMonth() << '.' << d1.getYear() << endl;
    cout << d1.daysToXmas() << endl; //269
    cout << d1.isLeapYear() << endl; //false (2014 is not a leap year)
    cout << d1.isLaterThen(d2) << endl; //false

    Date d3(13, 4, 2016); // 13.04.2016
    Date d4(19, 8, 2018); // 19.08.2018
    cout << d3.daysUntil(d4) << endl; //858
    Date d5(17, 3, 2021); // 19.08.2018
    cout << d5.daysUntilNextYear() << endl; //290
}