#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <QString>
#include <QDebug>
#include "date.h"
#include "librarypatron.h"
#include "book.h"

class LibraryBook : public Book
{
public:
    LibraryBook();
    LibraryBook(Book book);
    ~LibraryBook() {}
    void print();

    Date& dueDate(){return _dueDate;}
    LibraryPatron& libraryPatron(){return _patron;}

private:
    Date _dueDate;
    LibraryPatron _patron;
    bool isCheckedOut;
};

#endif // LIBRARYBOOK_H
