#include "book.h"

Book::Book() {}

Book::Book(QString title, QString author, QString genre)
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
