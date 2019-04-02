#ifndef LIBRARY_H
#define LIBRARY_H

#include "librarybook.h"
#include "person.h"
#include "librarypatron.h"
#include "date.h"

#include <vector>

using namespace std;

class Library
{
public:
    Library();
    ~Library();
    void resize(LibraryBook LibraryBooks);
    void resize(LibraryPatron LibraryPatrons);
    void checkCapacity(LibraryBook LibraryBooks);
    void checkCapacity(LibraryPatron LibraryPatrons);
    void assignLibraryCardNumber(Person person);
    void computeOverdueFines();
    void checkOutBook(LibraryBook librarybook, LibraryPatron patron);
    void checkInBook(LibraryBook librarybook, LibraryPatron patron);
    void changeDate();
    void addBooktoLibrary(Book book);
    void getAllLibraryBooks();
    void getLibraryBooksByGenre(Book book);
    void getAllPatrons();
    void getPatronsAdult();
    void getPatronsChild();
    void getCheckedOutBooksbyPatron(LibraryPatron patron);

private:
    vector<LibraryBook> LibraryBooks;
    vector<LibraryPatron> LibraryPatrons;

};

#endif // LIBRARY_H
