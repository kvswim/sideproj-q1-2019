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
#include <stdlib.h>

using namespace std;

class Library
{
public:
    Library();
    ~Library() {}
    Library(const vector<LibraryBook> libraryBooks,
            const vector<LibraryPatron> libraryPatrons, const Date currentDate);
    Library(const Library &other);
    Library& operator=(const Library& other);
    void assignLibraryCardNumber(Person person);
    double computeOverdueFines(LibraryPatron patron);
    void checkOutBook(QString title, int patronID);
    void checkInBook(QString title);
    void resetDate();
    void changeDate(Date newDate);
    void addBooktoLibrary(Book book);
    vector<LibraryBook> getLibraryBooksByGenre(QString genre);
    vector<LibraryPatron> getPatronsAdult();
    vector<LibraryPatron> getPatronsChild();
    vector<LibraryBook> getCheckedOutBooksbyPatron(int libraryCardNumber);
    int getLibraryBookIndex(LibraryBook libraryBookToFind);
    int getLibraryBookIndex(QString title);
    int getPatronIndex(int patronID);

    vector<LibraryBook> libraryBooks() {return _libraryBooks;}
    vector<LibraryPatron> libraryPatrons() {return _libraryPatrons;}
    Date getCurrentLibraryDate() {return _currentDate;}


private:
    vector<LibraryBook> _libraryBooks;
    vector<LibraryPatron> _libraryPatrons;
    Date _currentDate;

};

#endif // LIBRARY_H
