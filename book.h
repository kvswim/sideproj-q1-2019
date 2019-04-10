#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QDebug>

class Book
{
public:
    Book();
    ~Book() {}
    QString& title() {return _title;}
    QString& author() {return _author;}
    QString& genre() {return _genre;}
    Book getBook();
    void print();

private:
    QString _title, _author, _genre;
};

#endif // BOOK_H
