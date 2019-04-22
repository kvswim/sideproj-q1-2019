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

void LibraryPatron::print()
{
    qDebug() << this->name() << this->age() << this->libraryCardNumber();
}
