#include "librarypatron.h"

LibraryPatron::LibraryPatron()
{
    QString _name;
    int _age;
    int _librarycardnumber;
}
LibraryPatron::LibraryPatron(Person person)
{
    QString _name = person.name();
    int _age = person.age();
    int _librarycardnumber;
}
LibraryPatron::LibraryPatron(Person person, int cardNumber)
{
    QString _name = person.name();
    int _age = person.age();
    int _librarycardnumber = cardNumber;
}

void LibraryPatron::print()
{
    qDebug() << this->name() << this->age() << this->libraryCardNumber();
}
