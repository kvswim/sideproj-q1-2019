#ifndef DATE_H
#define DATE_H

#include "time.h"

class Date
{
public:
    Date();
    ~Date();
    void changeDate();
    void getTimeDifference();

private:
    time_t currentTime;
};

#endif // DATE_H
