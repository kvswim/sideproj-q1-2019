#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>

#include "library.h"

//if i have to type std::cout and std::endl a million times i might go insane
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (argc != 2)
    {
        qDebug() << "Invalid number of command line arguments.";
    }
    QString command = QString::fromStdString(argv[1]);
    Library runtimeLibrary;
    vector<QString> commandVector;
    QFile file(command);
    if(!file.open(QIODevice::ReadOnly) || !file.exists()) {
        qDebug() << "Unable to open file.";
        return 0;
    }
    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        commandVector.push_back(stream.readLine());
    }
    file.close();

    //tried an enum+map+switch but it didn't work
    //tried while(stream is not empty) loop but was having problems with nextline garbling input?
    //only way is the dirty way
    //shield your eyes children! don't try this at home!

    for (unsigned int i=0; i<commandVector.size(); i++)
    {
        if(commandVector.at(i) == "ADDBOOK")
        {
            //unnecessary temp variables just for human readability
            QString title = commandVector.at(i+1);
            QString author = commandVector.at(i+2);
            QString genre = commandVector.at(i+3);
            Book bookToAdd(title, author, genre);
            runtimeLibrary.addBooktoLibrary(bookToAdd);
            cout << "Added book " << bookToAdd.title().toStdString()
                 << " to library" << endl;
            //set index to one before next command, will be incremented on start of next loop
            i = i+3;
        }

        if (commandVector.at(i) == "ADDPATRON")
        {
            QString name = commandVector.at(i+1);
            int age = commandVector.at(i+2).toInt();
            Person personToAdd(name, age);
            runtimeLibrary.assignLibraryCardNumber(personToAdd);
            cout << "Added person " << personToAdd.name().toStdString()
                 << " to library" << endl;
            i=i+2;
        }

        if(commandVector.at(i) == "BOOKS")
        {
            if(commandVector.at(i+1) == "all")
            {
                for(unsigned int j=0; j<runtimeLibrary.libraryBooks().size(); j++)
                {
                    cout << "Book in library (all): " <<
                            runtimeLibrary.libraryBooks().at(j).title().toStdString()
                         << endl;
                }
            }
            else //next line defines genre of books to get
            {
                QString genre = commandVector.at(i+1);
                vector<LibraryBook> booksByGenre = runtimeLibrary.getLibraryBooksByGenre(genre);
                for(unsigned int j=0; j<booksByGenre.size(); j++)
                {
                    cout << "Book in library by genre: "
                         << genre.toStdString() << " " <<
                            booksByGenre.at(j).title().toStdString()
                         << endl;
                }
            }
            i = i+1;
        }

        if(commandVector.at(i) == "CHECKOUT")
        {
            runtimeLibrary.checkOutBook(commandVector.at(i+1), commandVector.at(i+2).toInt());
            cout << "Checked out book " << commandVector.at(i+1).toStdString() << " to patronID "
                 << commandVector.at(i+2).toInt() << endl;
            i = i+2;
        }

        if(commandVector.at(i) == "CHECKIN")
        {
            runtimeLibrary.checkInBook(commandVector.at(i+1));
            cout << "Checked in book " << commandVector.at(i+1).toStdString() << endl;
            i = i+1;
        }

        if(commandVector.at(i) == "DAY")
        {
            if(commandVector.at(i+1) == "1") //reset to day 1
            {
                runtimeLibrary.resetDate();
                cout << "Library has been set to day 1 (January 1, 2002)." << endl;
            }
            else
            {
//                for(int j=0; j<commandVector.at(i+1).toInt(); j++)
//                {
//                    runtimeLibrary.changeDate(Date()); //add days
//                }
                runtimeLibrary.changeDate(Date(commandVector.at(i+1).toInt()));
                cout << "Library date has been set to day " <<
                        commandVector.at(i+1).toInt() << endl;
            }
            i = i+1;
        }

        if(commandVector.at(i) == "PATRONSBOOKS")
        {
            vector<LibraryBook> checkedOutBooks =
                    runtimeLibrary.getCheckedOutBooksbyPatron(commandVector.at(i+1).toInt());
            cout << "Printing currently checked out books for patron ID #: "
                 << commandVector.at(i+1).toStdString() << endl;
            if(checkedOutBooks.size() == 0)
            {
                cout << "No books currently checked out for above ID." << endl;
            }
            else
            {
                for(unsigned int j=0; j<checkedOutBooks.size(); j++)
                {
                    cout << checkedOutBooks.at(j).title().toStdString() << endl;
                }
            }
            cout << "Done printing for above patron ID." << endl;
            i = i+1;
        }

        if(commandVector.at(i) == "PATRONS")
        {
            if (commandVector.at(i+1) == "all")
            {
                cout << "Printing all patrons." << endl;
                for(unsigned int j=0; j<runtimeLibrary.libraryPatrons().size(); j++)
                {
                    cout << runtimeLibrary.libraryPatrons().at(j).name().toStdString() << endl;
                }
                cout << "Done printing all patrons." << endl;
            }
            if (commandVector.at(i+1) == "adults")
            {
                vector<LibraryPatron> adultPatrons = runtimeLibrary.getPatronsAdult();
                cout << "Printing all adult patrons." << endl;
                for(unsigned int j=0; j<adultPatrons.size(); j++)
                {
                    cout << adultPatrons.at(j).name().toStdString() << endl;
                }
                cout << "Done printing all adult patrons." << endl;
            }
            if (commandVector.at(i+1) == "children")
            {
                vector<LibraryPatron> childPatrons = runtimeLibrary.getPatronsChild();
                cout << "Printing all child patrons." << endl;
                for (unsigned int j=0; j<childPatrons.size(); j++)
                {
                    cout << childPatrons.at(j).name().toStdString() << endl;
                }
                cout << "Done printing all child patrons." << endl;
            }
            i=i+1;
        }
        if(commandVector.at(i) == "\n")
        {
            i = i+1; //ignore newline
        }
        if(i == commandVector.size() - 1) break; //make sure we don't overflow
    }
    cout << "Done with program, press ctrl+c to break." << endl;
    return a.exec();
}
