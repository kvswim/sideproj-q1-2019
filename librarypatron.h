#ifndef LIBRARYPATRON_H
#define LIBRARYPATRON_H

#include "person.h"

class LibraryPatron : public Person
{
public:
    LibraryPatron();
    ~LibraryPatron();
    void print();
    int getLibraryCardNumber();

private:
    int librarycardnumber;
};

#endif // LIBRARYPATRON_H
