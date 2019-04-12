#include "librarybook.h"

LibraryBook::LibraryBook()
{
    isCheckedOut = false;
}

LibraryBook::LibraryBook(Book book)
{
    this->title() = book.title();
    this->author() = book.author();
    this->genre() = book.genre();
    isCheckedOut = false;
}

void LibraryBook::print()
{
    qDebug() << this->author() << this->title() << this->genre()
             << this->dueDate().currentTime()
             << this->libraryPatron().name() << this->libraryPatron().age()
             << this->libraryPatron().libraryCardNumber();
}
