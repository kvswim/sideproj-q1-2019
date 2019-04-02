#include "person.h"

Person::Person()
{

}

Person::~Person()
{

}

void Person::print()
{
 std::cout << "DEBUG (PERSON): NAME: "
           << this->name.toStdString()
           << " AGE: " << age;
}
