#include "librarypatron.h"

LibraryPatron::LibraryPatron() {}

LibraryPatron::LibraryPatron(Person person)
{
   _name = person.name();
   _age = person.age();
}

LibraryPatron::LibraryPatron(Person person, int cardNumber)
{
    _name = person.name();
    _age = person.age();
    _librarycardnumber = cardNumber;
}

LibraryPatron::LibraryPatron(const LibraryPatron &other) : Person(other)
{
    _name = other._name;
    _age = other._age;
    _librarycardnumber = other._librarycardnumber;
}

LibraryPatron& LibraryPatron::operator =(const LibraryPatron& other)
{
    if (this == &other) return *this;
    _name = other._name;
    _age = other._age;
    _librarycardnumber = other._librarycardnumber;
    return *this;
}

void LibraryPatron::print()
{
    qDebug() << _name << _age << _librarycardnumber;
}
