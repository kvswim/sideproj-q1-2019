#include "date.h"

Date::Date() {}

Date::Date(time_t inputTime)
{
    _currentTime = inputTime;
}

Date Date::addTime(Date plusTime)
{
    _currentTime += plusTime.currentTime();
}

void Date::print()
{
    qDebug() << this->currentTime();
}
