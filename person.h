#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <iostream>

class Person
{
public:
    Person();
    Person(QString name, int age);
    ~Person();
    void print();

    QString& name() {return _name;}
    int& age() {return _age;}


private:
    QString _name;
    int _age;
};

#endif // PERSON_H
