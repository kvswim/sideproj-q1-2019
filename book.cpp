#include "book.h"

Book::Book() {}

Book::Book(QString author, QString genre, QString title)
{
    _author = author;
    _genre = genre;
    _title = title;
}

Book Book::getBook()
{
    return *this;
}
void Book::print()
{
    qDebug() << this->author() << this->genre() << this->title();
}
