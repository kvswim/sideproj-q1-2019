#include "date.h"

Date::Date() {}

Date::Date(time_t inputTime)
{
    _currentTime = inputTime;
}

void Date::changeDate(Date newDate)
{
    _currentTime = newDate.currentTime();
}

void Date::print()
{
    qDebug() << this->currentTime();
}
