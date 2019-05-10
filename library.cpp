#include "library.h"

Library::Library()
{
    _currentDate = Date(1); //set to January 1, 2002 12:00 AM GMT
}

Library::Library(const vector<LibraryBook> libraryBooks,
                 const vector<LibraryPatron> libraryPatrons,
                 const Date currentDate)
{
    _libraryBooks = libraryBooks;
    _libraryPatrons = libraryPatrons;
    _currentDate = currentDate;
}

Library::Library(const Library &other)
{
    _libraryBooks = other._libraryBooks;
    _libraryPatrons = other._libraryPatrons;
    _currentDate = other._currentDate;
}

Library& Library::operator=(const Library& other)
{
    if (this == &other) return *this;
    _libraryBooks = other._libraryBooks;
    _libraryPatrons = other._libraryPatrons;
    _currentDate = other._currentDate;
    return *this;
}

void Library::assignLibraryCardNumber(Person person)
{
    if (_libraryPatrons.empty()) //first member gets card# 1001
    {
        LibraryPatron newPatron = LibraryPatron(person, 1001);
        _libraryPatrons.push_back(newPatron);
    }
    else //everyone after gets last+1
    {
        int lastId = _libraryPatrons.back().libraryCardNumber();
        int newId = ++lastId;
        LibraryPatron newPatron = LibraryPatron (person, newId);
        _libraryPatrons.push_back(newPatron);
    }
}

double Library::computeOverdueFines(LibraryPatron patron)
{
    //1 day = 86400 seconds
    //adults >=12 charged $0.25/day overdue
    //children <12 charged 0.10/day
    double overdueFines = 0.0;
    double quarter = 0.25;
    double dime = 0.1;
    vector<LibraryBook> checkedOutBooks = getCheckedOutBooksbyPatron(patron.libraryCardNumber());
    if (checkedOutBooks.size() != 0)
    {
        for (unsigned int i = 0; i<checkedOutBooks.size(); ++i)
        {
            int overdueTime = 0;
            int dbIndex = getLibraryBookIndex(checkedOutBooks.at(i).title());
            int dueDate = _libraryBooks.at(dbIndex).dueDate().currentDay();
            int currentDate = _currentDate.currentDay();
            if (currentDate > dueDate)
            {
                overdueTime = currentDate - dueDate;
            }
            if(patron.age() >= 12) //adult
            {
                overdueFines += quarter * overdueTime; //implicit recast to double
            }
            else //child
            {
                overdueFines += dime * overdueTime;
            }
        }
    }
    return overdueFines;
}

void Library::checkOutBook(QString title, int patronID)
{
    //children <12 can check out for (7 days)
    //adults >=12 can check out for (14 days)
    int dbIndex = getLibraryBookIndex(title);
    int patronIndex = getPatronIndex(patronID);
    //error: book was not found in db
    //error: book tried to be checked out to someone not in db
    //-1 indicates not found
    if (dbIndex == -1)
    {
        qDebug() << "Error: That book was not found in the database.";
        return;
    }
    if (patronIndex == -1)
    {
        qDebug() << "Error: That patron was not found in the database.";
        return;
    }
    else //book is in db, patron is in db.
    {
        if (_libraryBooks.at(dbIndex).isCheckedOut() == true)
        {
            qDebug() << "Error: That book is already checked out.";
            return;
        }
        else //all checks passed.
        {
            if (_libraryPatrons.at(patronIndex).age() >= 12)
            {
                _libraryBooks.at(dbIndex).setPatron(_libraryPatrons.at(patronIndex));
                _libraryBooks.at(dbIndex).setCheckedOut(true);
                Date dueDate(_currentDate.currentDay() + 14);
                _libraryBooks.at(dbIndex).setDueDate(dueDate);
            }
            else
            {
                _libraryBooks.at(dbIndex).setPatron(_libraryPatrons.at(patronIndex));
                _libraryBooks.at(dbIndex).setCheckedOut(true);
                Date dueDate(_currentDate.currentDay() + 7);
                _libraryBooks.at(dbIndex).setDueDate(dueDate);
            }
        }
    }
}

void Library::checkInBook(QString title)
{
    int dbIndex = getLibraryBookIndex(title);
    if (dbIndex == -1)
    {
        qDebug() << "Error: Unable to find library book in current db.";
        return;
    }
    if (!_libraryBooks.at(dbIndex).isCheckedOut())
    {
        qDebug() << "Error: That book isn't checked out.";
        return;
    }
    _libraryBooks.at(dbIndex).setPatron(LibraryPatron()); //reset w constructor
    _libraryBooks.at(dbIndex).setCheckedOut(false);
    _libraryBooks.at(dbIndex).setDueDate(Date());
}

void Library::resetDate()
{
    _currentDate = Date(1);
}

void Library::changeDate(Date newDate)
{
    _currentDate = newDate;
    for (unsigned int i = 0; i<_libraryPatrons.size(); ++i)
    {
        cout << "Patron " << _libraryPatrons.at(i).name().toStdString()
             << " owes " << computeOverdueFines(_libraryPatrons.at(i))
             << " in fines." << endl;
    }

}

void Library::addBooktoLibrary(Book book)
{
    int dbIndex = getLibraryBookIndex(book.title());
    if (dbIndex != -1)
    {
        qDebug() << "That book is already in the db.";
        return;
    }
    LibraryBook newLibraryBook = LibraryBook(book);
    _libraryBooks.push_back(newLibraryBook);
}



vector<LibraryBook> Library::getLibraryBooksByGenre(QString genre)
{
    vector<LibraryBook> booksByGenre;
    for (unsigned int i=0; i<_libraryBooks.size(); ++i)
    {
        if (_libraryBooks.at(i).genre() == genre)
        {
            booksByGenre.push_back(_libraryBooks.at(i));
        }
    }
    return booksByGenre;
}



vector<LibraryPatron> Library::getPatronsAdult()
{
    vector<LibraryPatron> adultPatrons;
    for (unsigned int i=0; i<_libraryPatrons.size(); ++i)
    {
        LibraryPatron tempPatron = _libraryPatrons.at(i);
        if(tempPatron.age() >= 12)
        {
            adultPatrons.push_back(tempPatron);
        }
    }
    return adultPatrons;
}

vector<LibraryPatron> Library::getPatronsChild()
{
    vector<LibraryPatron> childPatrons;
    for (unsigned int i=0; i<_libraryPatrons.size(); ++i)
    {
        LibraryPatron tempPatron = _libraryPatrons.at(i);
        if (tempPatron.age() < 12)
        {
            childPatrons.push_back(tempPatron);
        }
    }
    return childPatrons;
}

vector<LibraryBook> Library::getCheckedOutBooksbyPatron(int libraryCardNumber)
{
    vector<LibraryBook> checkedOutBooks;
    if(getPatronIndex(libraryCardNumber) == -1)
    {
        qDebug() << "Error: that patron does not exist in db.";
        return checkedOutBooks; //empty vector
    }
    for (unsigned int i=0; i<_libraryBooks.size(); ++i)
    {
        if (_libraryBooks.at(i).libraryPatron().libraryCardNumber() == libraryCardNumber
                && _libraryBooks.at(i).isCheckedOut() == true)
        {
            checkedOutBooks.push_back(_libraryBooks.at(i));
        }
    }
    return checkedOutBooks;
}

int Library::getLibraryBookIndex(LibraryBook libraryBookToFind){
    int bookId = -1;
    for (unsigned int i=0; i<_libraryBooks.size(); ++i)
    {
        if ((_libraryBooks.at(i).author() == libraryBookToFind.author()) &&
                _libraryBooks.at(i).genre() == libraryBookToFind.genre() &&
                _libraryBooks.at(i).title() == libraryBookToFind.title())
        {
            bookId = i;
            return bookId;
        }
    }
    return bookId; //if not found return -1
}

int Library::getLibraryBookIndex(QString title)
{
    int dbIndex = -1;
    for(unsigned int i=0; i<_libraryBooks.size(); i++)
    {
        if(_libraryBooks.at(i).title() == title)
        {
            dbIndex = i;
            return dbIndex;
        }
    }
    return dbIndex;
}

int Library::getPatronIndex(int patronID)
{
    int patronIndex = -1;
    for (unsigned int i=0; i<_libraryPatrons.size(); i++)
    {
        if(_libraryPatrons.at(i).libraryCardNumber() == patronID)
        {
            patronIndex = i;
            return patronIndex;
        }
    }
    return patronIndex;
}
