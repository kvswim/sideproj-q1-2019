#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QDebug>
#include <string>

class Book
{
public:
    Book();
    Book(const Book &other);
    Book(QString title, QString author, QString genre);
    ~Book() {}
    Book& operator=(const Book& other);
    void print();

    //TODO pass by reference probably not required?
    //when switched to pass by value, program compiles but stops all output :-S
    QString& title() {return _title;}
    QString& author() {return _author;}
    QString& genre() {return _genre;}

protected:
    QString _title, _author, _genre;
};

#endif // BOOK_H
