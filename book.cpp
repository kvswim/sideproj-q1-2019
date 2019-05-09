#include "book.h"

Book::Book() {}

Book::Book(QString title, QString author, QString genre)
{
    _author = author;
    _genre = genre;
    _title = title;
}

Book::Book(const Book &other)
{
    _author = other._author;
    _genre = other._genre;
    _title = other._title;
}

void Book::print()
{
    qDebug() << _author << _genre << _title;
}

Book& Book::operator=(const Book& other)
{
    if (this == &other) return *this;
    _author = other._author;
    _genre = other._genre;
    _title = other._title;
    return *this;
}
