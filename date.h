#ifndef DATE_H
#define DATE_H

#include <QDebug>
#include <ctime>

#include "time.h"

class Date
{
public:
    Date();
    Date(time_t inputTime);
    ~Date() {}
    Date addTime(Date plusTime);
    void print();

    time_t currentTime() {return _currentTime;}

private:
    time_t _currentTime;
};

#endif // DATE_H
