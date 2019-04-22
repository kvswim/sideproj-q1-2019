#include "library.h"
Library::Library()
{
    _currentDate = Date(1009843200); //set to January 1, 2002 12:00 AM GMT
}
Library::Library(const vector<LibraryBook> libraryBooks,
                 const vector<LibraryPatron> libraryPatrons,
                 const Date currentDate)
{
    _libraryBooks = libraryBooks;
    _libraryPatrons = libraryPatrons;
    _currentDate = currentDate;
}

//obsolete functions since vector is in use
//void Library::resize(LibraryBook LibraryBooks){}
//void Library::resize(LibraryPatron LibraryPatrons){}
//void Library::checkCapacity(LibraryBook LibraryBooks) {}
//void Library::checkCapacity(LibraryPatron LibraryPatrons) {}

void Library::assignLibraryCardNumber(Person person)
{
    if (libraryPatrons().empty()) //first member gets card# 1001
    {
        LibraryPatron newPatron = LibraryPatron(person, 1001);
        libraryPatrons().push_back(newPatron);
    }
    else //everyone after gets last+1
    {
        int lastId = libraryPatrons().back().libraryCardNumber();
        int newId = ++lastId;
        LibraryPatron newPatron = LibraryPatron (person, newId);
        libraryPatrons().push_back(newPatron);
    }
}

double Library::computeOverdueFines(LibraryPatron patron)
{
    //1 day = 86400 seconds
    //adults >=12 charged $0.25/day overdue
    //children <12 charged 0.10/day
    double overdueFines = 0.0;
    vector<LibraryBook> checkedOutBooks = getCheckedOutBooksbyPatron(patron.libraryCardNumber());
    for (unsigned int i = 0; i<checkedOutBooks.size(); ++i)
    {
        int dbIndex = getLibraryBookIndex(checkedOutBooks.at(i));
        Date overdueTime = libraryBooks().at(dbIndex).dueDate().currentTime()
                - currentDate().currentTime();
        //acts as floor so we aren't too mean to people who just wanna read books
        int overdueTimeinDays = overdueTime.currentTime() / 86400;
        if(patron.age() >= 12) //adult
        {
            overdueFines = (double) 0.25 * overdueTimeinDays;
        }
        else //child
        {
            overdueFines = (double) 0.1 * overdueTimeinDays;
        }
    }
    return overdueFines;
}

void Library::checkOutBook(QString title, int patronID)
{
    //children <12 can check out for 604800 seconds
    //adults >=12 can check out for 1210000 seconds
    int dbIndex = getLibraryBookIndex(title);
    int patronIndex = getPatronIndex(patronID);
    if (dbIndex == -1 || patronIndex == -1)
    {
        qDebug() << "Something went wrong. dbIndex is " << dbIndex
                 << "PatronIndex is " << patronIndex;
    }
    else //book is in db, patron is in db.
    {
        if (libraryBooks().at(dbIndex).isCheckedOut() == true)
        {
            qDebug() << "Error: That book is already checked out.";
        }
        else //all checks passed.
        {
            if (libraryPatrons().at(patronIndex).age() >= 12)
            {
                libraryBooks().at(dbIndex).libraryPatron() =
                        libraryPatrons().at(patronIndex);
                libraryBooks().at(dbIndex).isCheckedOut() = true;
                libraryBooks().at(dbIndex).dueDate() =
                        currentDate().addTime(1210000);
            }
            else
            {
                libraryBooks().at(dbIndex).libraryPatron() =
                        libraryPatrons().at(patronIndex);
                libraryBooks().at(dbIndex).isCheckedOut() = true;
                libraryBooks().at(dbIndex).dueDate() =
                        currentDate().addTime(604800);
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
    }
    double fine = computeOverdueFines(libraryBooks().at(dbIndex).libraryPatron());
    cout << "Note: patron " << libraryBooks().at(dbIndex).libraryPatron().name().toStdString()
         << "owes " << fine << " in fines." << endl;
    libraryBooks().at(dbIndex).libraryPatron() = LibraryPatron(); //reset w constructor
    libraryBooks().at(dbIndex).isCheckedOut() = false;
    libraryBooks().at(dbIndex).dueDate() = Date();
}

void Library::changeDate() //adds one day
{
    currentDate().addTime(86400);
}

void Library::changeDate(Date newDate)
{
    currentDate().addTime(newDate);
}

void Library::addBooktoLibrary(Book book)
{
    LibraryBook newLibraryBook = LibraryBook(book);
    libraryBooks().push_back(newLibraryBook);
}



vector<LibraryBook> Library::getLibraryBooksByGenre(QString genre)
{
    vector<LibraryBook> booksByGenre;
    for (unsigned int i=0; i<libraryBooks().size(); ++i)
    {
        if (libraryBooks().at(i).genre() == genre)
        {
            booksByGenre.push_back(libraryBooks().at(i));
        }
    }
    return booksByGenre;
}



vector<LibraryPatron> Library::getPatronsAdult()
{
    vector<LibraryPatron> adultPatrons;
    for (unsigned int i=0; i<libraryPatrons().size(); ++i)
    {
        LibraryPatron tempPatron = libraryPatrons().at(i);
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
    for (unsigned int i=0; i<libraryPatrons().size(); ++i)
    {
        LibraryPatron tempPatron = libraryPatrons().at(i);
        if (tempPatron.age() < 12)
        {
            childPatrons.push_back(tempPatron);
        }
    }
    return childPatrons;
}

vector<LibraryBook> Library::getCheckedOutBooksbyPatron(int libraryCardNumber) //TODO something's broken here
{
    vector<LibraryBook> checkedOutBooks;
    for (unsigned int i=0; i<libraryBooks().size(); ++i)
    {
        if (libraryBooks().at(i).libraryPatron().libraryCardNumber() == libraryCardNumber
                && libraryBooks().at(i).isCheckedOut() == true)
        {
            checkedOutBooks.push_back(libraryBooks().at(i));
        }
    }
    return checkedOutBooks;
}

int Library::getLibraryBookIndex(LibraryBook libraryBookToFind){
    int bookId = -1;
    for (unsigned int i=0; i<libraryBooks().size(); ++i)
    {
        if ((libraryBooks().at(i).author() == libraryBookToFind.author()) &&
                libraryBooks().at(i).genre() == libraryBookToFind.genre() &&
                libraryBooks().at(i).title() == libraryBookToFind.title())
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
    for(unsigned int i=0; i<libraryBooks().size(); i++)
    {
        if(libraryBooks().at(i).title() == title)
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
    for (unsigned int i=0; i<libraryPatrons().size(); i++)
    {
        if(libraryPatrons().at(i).libraryCardNumber() == patronID)
        {
            patronIndex = i;
            return patronIndex;
        }
    }
    return patronIndex;
}
