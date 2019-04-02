#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <QString>
#include "date.h"
#include "librarypatron.h"
#include "book.h"

class LibraryBook : public Book
{
public:
    LibraryBook();
    ~LibraryBook();
    Date getDueDate();
    QString getCurrentPatron();
    void print();
//    void setAuthor(QString authorToSet);
//    void setGenre(QString genreToSet);
//    void setTitle(QString titleToSet);

private:
    Date dueDate;
    LibraryPatron patron;
};

#endif // LIBRARYBOOK_H
