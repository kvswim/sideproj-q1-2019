#ifndef LIBRARY_H
#define LIBRARY_H

#include "librarybook.h"
#include "person.h"
#include "librarypatron.h"
#include "date.h"

#include <vector>
#include <ctime>
#include <time.h>
#include <stdio.h>

using namespace std;

class Library
{
public:
    Library();
    ~Library() {}
    Library(const vector<LibraryBook> libraryBooks,
            const vector<LibraryPatron> libraryPatrons, const Date currentDate);

//  obsolete functions since vector is in use
//    void resize(LibraryBook LibraryBooks);
//    void resize(LibraryPatron LibraryPatrons);
//    void checkCapacity(LibraryBook LibraryBooks);
//    void checkCapacity(LibraryPatron LibraryPatrons);

    void assignLibraryCardNumber(Person person);
    double computeOverdueFines(LibraryPatron patron);
    void checkOutBook(LibraryBook librarybook, LibraryPatron patron);
    void checkInBook(LibraryBook librarybook);
    void changeDate();
    void changeDate(Date newDate);
    void addBooktoLibrary(Book book);
    vector<LibraryBook> getLibraryBooksByGenre(Book book);
    vector<LibraryPatron> getPatronsAdult();
    vector<LibraryPatron> getPatronsChild();
    vector<LibraryBook> getCheckedOutBooksbyPatron(LibraryPatron patron);
    int getLibraryBookIndex(LibraryBook libraryBookToFind);

    vector<LibraryBook>& libraryBooks() {return _libraryBooks;}
    vector<LibraryPatron>& libraryPatrons() {return _libraryPatrons;}
    Date& currentDate() {return _currentDate;}

private:
    vector<LibraryBook> _libraryBooks;
    vector<LibraryPatron> _libraryPatrons;
    Date _currentDate;

};

#endif // LIBRARY_H
