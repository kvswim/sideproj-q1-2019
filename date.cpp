#include "date.h"

Date::Date() {}

Date::Date(int inputDay)
{
    _currentDay = inputDay;
}

Date::Date(const Date &other)
{
    _currentDay = other._currentDay;
}

Date& Date::operator=(const Date& other)
{
    if (this == &other) return *this;
    _currentDay = other._currentDay;
    return *this;
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

QString Date::getDatePrintString()
{
    time_t timeSinceEpoch = 1009843200;
    char buffer[80];
    if(_currentDay != 1)
    {
        timeSinceEpoch += (86400 * _currentDay);
    }
    struct tm *timeinfo = gmtime(&timeSinceEpoch);
    strftime(buffer, 80, "%a %e %b %Y", timeinfo);
    puts(buffer);
    QString printString(buffer);
    return printString;
}
