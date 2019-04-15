#include "librarypatron.h"

LibraryPatron::LibraryPatron() {}

LibraryPatron::LibraryPatron(Person person)
{
   this->name() = person.name();
   this->age() = person.age();
}
LibraryPatron::LibraryPatron(Person person, int cardNumber)
{
    this->name() = person.name();
    this->age() = person.age();
    this->libraryCardNumber() = cardNumber;
}

void LibraryPatron::print()
{
    qDebug() << this->name() << this->age() << this->libraryCardNumber();
}
