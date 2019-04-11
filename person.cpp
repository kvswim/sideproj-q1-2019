#include "person.h"

Person::Person()
{
    QString _name;
    int _age;
}

Person::Person(QString name, int age)
{
    QString _name = name;
    int _age = age;
}


void Person::print()
{
    qDebug() << this->name() << this->age();
}
