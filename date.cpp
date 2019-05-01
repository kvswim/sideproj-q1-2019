#include "date.h"

Date::Date() {}

Date::Date(int inputDay)
{
    _currentDay = inputDay;
}

Date Date::addTime(int daysToAdd)
{
    _currentDay += daysToAdd;
    return Date(_currentDay);
}

void Date::print()
{
    qDebug() << _currentDay;
}
