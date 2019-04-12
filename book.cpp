#include "book.h"

Book::Book() {}

//TODO constructor(author, genre, title)

Book Book::getBook()
{
    return *this;
}
void Book::print()
{
    qDebug() << this->author() << this->genre() << this->title();
}
