#include "person.h"

Person::Person() {}

Person::Person(QString name, int age)
{
    _name = name;
    _age = age;
}

Person::Person(const Person &other)
{
    _name = other._name;
    _age = other._age;
}

Person& Person::operator = (const Person& other)
{
    if (this == &other) return *this;
    _name = other._name;
    _age = other._age;
    return *this;
}

void Person::print()
{
    qDebug() << _name << _age;
}
