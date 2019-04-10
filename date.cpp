#include "date.h"

Date::Date()
{
    time_t _currentTime;
}

Date::Date(time_t inputTime)
{
    time_t _currentTime = inputTime;
}

void Date::changeDate(Date newDate)
{
    _currentTime = newDate.currentTime();
}

void Date::print()
{
    qDebug() << this->currentTime();
}
