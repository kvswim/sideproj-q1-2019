#include "librarybook.h"

LibraryBook::LibraryBook()
{
    Date _dueDate;
    LibraryPatron _patron;
    QString _title, _author, _genre;
    bool isCheckedOut = false;
}

LibraryBook::LibraryBook(Book book)
{
    QString _title = book.title();
    QString _author = book.author();
    QString _genre = book.genre();
    bool isCheckedOut = false;
    LibraryPatron _patron;
    Date _dueDate;
}

void LibraryBook::print()
{

}
