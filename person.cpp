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

Person::~Person()
{

}

void Person::print()
{
 std::cout << "DEBUG (PERSON): NAME: "
           << name().toStdString()
           << " AGE: " << age();
}
