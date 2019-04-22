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
    qDebug() << this->author() << this->title() << this->genre()
             << this->dueDate().currentTime()
             << this->libraryPatron().name() << this->libraryPatron().age()
             << this->libraryPatron().libraryCardNumber();
}
