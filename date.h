#ifndef DATE_H
#define DATE_H

#include <QDebug>
#include <ctime>

#include "time.h"

class Date
{
public:
    Date();
    Date(int inputDay);
    ~Date() {}
    Date addTime(int daysToAdd);
    void print();
    //getter
    int currentDay() {return _currentDay;}
private:
    int _currentDay;
};

#endif // DATE_H
