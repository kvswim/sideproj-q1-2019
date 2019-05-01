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

void LibraryBook::print()
{
    qDebug() << _author << _title << _genre
             << _dueDate.currentDay()
             << _patron.name() << _patron.age()
             << _patron.libraryCardNumber();
}
