#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QDebug>
#include <iostream>

class Person
{
public:
    Person();
    Person(QString name, int age);
    Person(const Person &other);
    ~Person() {}
    Person& operator =(const Person& other);
    void print();

    QString name() {return _name;}
    int age() {return _age;}


protected:
    QString _name;
    int _age;
};

#endif // PERSON_H
