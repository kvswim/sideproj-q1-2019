#ifndef DATE_H
#define DATE_H

#include <QDebug>
#include <ctime>

#include "time.h"

class Date
{
public:
    Date();
    Date(int inputTime);
    ~Date() {}
    Date addTime(int plusTime);
    void print();

    int currentTime() {return _currentTime;}

private:
    int _currentTime;
};

#endif // DATE_H
