#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QDebug>

class Book
{
public:
    Book();
    Book(QString title, QString author, QString genre);
    ~Book() {}
    void print();

    //TODO pass by reference probably not required?
    //when switched to pass by value, program compiles but stops all output :-S
    QString& title() {return _title;}
    QString& author() {return _author;}
    QString& genre() {return _genre;}

    /*void setTitle(QString title) {_title = title;}
    void setAuthor(QString author) {_author = author;}
    void setGenre(QString genre) {_genre = genre;}*/

protected:
    QString _title, _author, _genre;
};

#endif // BOOK_H
