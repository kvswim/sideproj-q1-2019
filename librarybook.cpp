#include "librarybook.h"

LibraryBook::LibraryBook()
{
    _isCheckedOut = false;
}

LibraryBook::LibraryBook(Book book)
{
    _title = book.title();
    _author = book.author();
    _genre = book.genre();
    _isCheckedOut = false;
}

LibraryBook& LibraryBook::operator=(const LibraryBook& other)
{
    if (this == &other) return *this;
    _title = other._title;
    _author = other._author;
    _genre = other._genre;
    _dueDate = other._dueDate;
    _patron = other._patron;
    _isCheckedOut = other._isCheckedOut;
    return *this;
}

void LibraryBook::print()
{
    qDebug() << _author << _title << _genre
             << _dueDate.currentDay()
             << _patron.name() << _patron.age()
             << _patron.libraryCardNumber();
}
