#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    Book();
    ~Book();
    QString getBook();

private:
    QString title, author, genre;
};

#endif // BOOK_H
