#ifndef LIBRARYPATRON_H
#define LIBRARYPATRON_H

#include "person.h"

#include <QDebug>

class LibraryPatron : public Person
{
public:
    LibraryPatron();
    LibraryPatron(Person person);
    LibraryPatron(Person person, int cardNumber);
    LibraryPatron(const LibraryPatron &other);
    LibraryPatron& operator=(const LibraryPatron& other);
    ~LibraryPatron() {}
    void print();

    int libraryCardNumber() {return _librarycardnumber;}

private:
    int _librarycardnumber;
};

#endif // LIBRARYPATRON_H
