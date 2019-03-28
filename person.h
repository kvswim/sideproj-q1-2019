#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
public:
    Person();
    ~Person();
    void print();

private:
    QString name;
    int age;
};

#endif // PERSON_H
