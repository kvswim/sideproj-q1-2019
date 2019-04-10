#ifndef LIBRARY_H
#define LIBRARY_H

#include "librarybook.h"
#include "person.h"
#include "librarypatron.h"
#include "date.h"

#include <vector>
#include <ctime>

using namespace std;

class Library
{
public:
    Library();
    ~Library();
    Library(const vector<LibraryBook> libraryBooks,
            const vector<LibraryPatron> libraryPatrons, const Date currentDate);

//    void resize(LibraryBook LibraryBooks);
//    void resize(LibraryPatron LibraryPatrons);
//    void checkCapacity(LibraryBook LibraryBooks);
//    void checkCapacity(LibraryPatron LibraryPatrons);

    void assignLibraryCardNumber(Person person);
    void computeOverdueFines();
    void checkOutBook(LibraryBook librarybook, LibraryPatron patron);
    void checkInBook(LibraryBook librarybook, LibraryPatron patron);
    void changeDate();
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
