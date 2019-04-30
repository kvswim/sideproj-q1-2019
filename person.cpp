#include "person.h"

Person::Person() {}

Person::Person(QString name, int age)
{
    _name = name;
    _age = age;
}


void Person::print()
{
    qDebug() << _name << _age;
}
