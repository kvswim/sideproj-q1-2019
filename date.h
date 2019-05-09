#ifndef DATE_H
#define DATE_H

#include <QDebug>
#include <time.h>

class Date
{
public:
    Date();
    Date(int inputDay);
    Date(const Date &other);
    ~Date() {}
    Date& operator=(const Date& other);
    Date addTime(int daysToAdd);
    void print();
    QString getDatePrintString();
    //getter
    int currentDay() {return _currentDay;}
private:
    int _currentDay;
};

#endif // DATE_H
