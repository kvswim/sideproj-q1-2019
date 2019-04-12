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
void Library::computeOverdueFines() //TODO
{
    //1 day = 86400 seconds
    //adults >=12 charged $0.25/day overdue
    //children <12 charged 0.10/day
}

void Library::checkOutBook(LibraryBook librarybook, LibraryPatron patron) //TODO
{
    //children <12 can check out for 604800 seconds
    //adults >=12 can check out for 1210000 seconds
}

void Library::checkInBook(LibraryBook librarybook, LibraryPatron patron) //TODO
{

}

void Library::changeDate() //TODO
{

}

void Library::addBooktoLibrary(Book book)
{
    LibraryBook newLibraryBook = LibraryBook(book);
    libraryBooks().push_back(newLibraryBook);
}



vector<LibraryBook> Library::getLibraryBooksByGenre(Book book)
{
    vector<LibraryBook> booksByGenre;
    for (int i=0; i<libraryBooks().size(); ++i)
    {
        if (libraryBooks().at(i).genre() == book.genre())
        {
            booksByGenre.push_back(libraryBooks().at(i));
        }
    }
    return booksByGenre;
}



vector<LibraryPatron> Library::getPatronsAdult()
{
    vector<LibraryPatron> adultPatrons;
    for (int i=0; i<libraryPatrons().size(); ++i)
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
    for (int i=0; i<libraryPatrons().size(); ++i)
    {
        LibraryPatron tempPatron = libraryPatrons().at(i);
        if (tempPatron.age() < 12)
        {
            childPatrons.push_back(tempPatron);
        }
    }
    return childPatrons;
}

vector<LibraryBook> Library::getCheckedOutBooksbyPatron(LibraryPatron patron)
{
    vector<LibraryBook> checkedOutBooks;
    for (int i=0; i<libraryBooks().size(); ++i)
    {
        if (libraryBooks().at(i).libraryPatron().name() == patron.name())
        {
            checkedOutBooks.push_back(libraryBooks().at(i));
        }
    }
    return checkedOutBooks;
}

int Library::getLibraryBookIndex(LibraryBook libraryBookToFind){
    int bookId;
    for (int i=0; i<libraryBooks().size(); ++i)
    {
        if ((libraryBooks().at(i).author() == libraryBookToFind.author()) &&
                libraryBooks().at(i).genre() == libraryBookToFind.genre() &&
                libraryBooks().at(i).title() == libraryBookToFind.title())
        {
            return bookId;
        }
    }
    return -1; //if not found return -1
}
