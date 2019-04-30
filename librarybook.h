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

    //getters
    Date dueDate(){return _dueDate;}
    LibraryPatron libraryPatron(){return _patron;}
    bool isCheckedOut(){return _isCheckedOut;}
    //setters
    void setCheckedOut(bool isCheckedOut){_isCheckedOut = isCheckedOut;}
    void setDueDate(Date dateToSet){_dueDate = dateToSet;}
    void setPatron(LibraryPatron libraryPatron){_patron = libraryPatron;}

private:
    Date _dueDate;
    LibraryPatron _patron;
    bool _isCheckedOut;
};

#endif // LIBRARYBOOK_H
