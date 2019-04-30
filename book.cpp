#include "book.h"

Book::Book() {}

Book::Book(QString title, QString author, QString genre)
{
    _author = author;
    _genre = genre;
    _title = title;
}

void Book::print()
{
    qDebug() << _author << _genre << _title;
}
