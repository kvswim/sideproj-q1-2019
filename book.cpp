#include "book.h"

Book::Book() {
    QString _title, _author, _genre;
}

Book Book::getBook()
{
    return *this;
}
void Book::print()
{
    qDebug() << this->author() << this->genre() << this->title();
}
