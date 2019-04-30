#include "date.h"

Date::Date() {}

Date::Date(int inputTime)
{
    _currentTime = inputTime;
}

Date Date::addTime(int plusTime)
{
    _currentTime += plusTime;
    return Date(_currentTime);
}

void Date::print()
{
    qDebug() << _currentTime;
}
