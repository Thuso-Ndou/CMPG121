/*
Name: Thuso
Surname: Ndou
Student No: 37853058
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// define a struct
struct Book
{
    string title;
    string author;
    long int ISBN;
    int year;
};

// Function to add a book to the binary file
void addBook()
{
    // create an ofstream writer object
    ofstream writeData("libraryDatabase.bin", ios::binary);

    // declare a book of Book structure
    Book book;

    // user input for book title
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, book.title);

    // user input for author name
    cout << "Enter author: ";
    cin.ignore();
    getline(cin, book.author);

    // user input for ISBN number
    cout << "Enter ISBN: ";
    cin >> book.ISBN;

    // user input for year
    cout << "Enter Year Published: ";
    cin >> book.year;
    cin.ignore();


    if(!(writeData.is_open()))
    {
        // display a open file error message
        cout << "File Failed to open\n";
    }
    else
    {
        // write data to the file
        writeData.write(reinterpret_cast<char*>(&book) ,sizeof(Book));

        // close file
        writeData.close();

        // successful message
        cout << "\nBook added successfully!\n";
    }
}

// Function to search by ISBN
void searchByISBN() {
    // create an fstream reader object
    ifstream readData("libraryDatabase.bin", ios::binary);

    // declare variables
    long int isbnNumber;
    bool isFound = false;

    // user input for ISBN number
    cout << "Enter ISBN to search: ";
    cin >> isbnNumber;

    if (!(readData.is_open()))
    {
        // display file error message
        cout << "File Failed to open\n";
    }
    else
    {
        // create a book variable of structure Book
        Book book;

        while (readData.read(reinterpret_cast<char*>(&book), sizeof(Book)))
        {
            if (book.ISBN == isbnNumber)
            {
                // set is found to true
                isFound = true;

                // break out of the loop
                break;
            }
        }

        // close file
        readData.close();

        if (isFound)
        {
            // display the results when isbn is found
            cout << "Title: " << book.title << "\n";
            cout << "Author: " << book.author << "\n";
            cout << "ISBN: " << book.ISBN << "\n";
            cout << "Year Published: " << book.year << "\n";
        }
        else
        {
            // when the isbn is not found
            cout << "Book not found." << "\n";
        }
    }
}

// Function to list all books
void listAllBooks()
{
    // create fstream reader object
    ifstream readData("libraryDatabase.bin", ios::binary);

    if (readData.is_open())
    {
        // display file error message
        cout << "File failed to open.\n";
    }
    else
    {
        // create a variable of a Book structure
        Book book;

        while (readData.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
            cout << "Title: " << book.title << "\n";
            cout << "Author: " << book.author << "\n";
            cout << "ISBN: " << book.ISBN << "\n";
            cout << "Year Published: " << book.year << "\n";
            cout << "\n";
        }

        // close file
        readData.close();
    }
}



int main()
{
    // declare variables
    int userOption;

    do
    {
        // display menu
        cout << "\nChoose an option: \n";
        cout << "1. Add a book \n";
        cout << "2. Search by ISBN \n";
        cout << "3. List All Books \n";
        cout << "4. Exit \n";

        // user input for option number
        cout << "\n";
        cin >> userOption;

        switch(userOption)
        {
            case 1:
                addBook();
                break;
            case 2:
                searchByISBN();
                break;
            case 3:
                listAllBooks();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Option. Try again.\n";
                break;
        }

    } while(userOption != 4);

    return 0;
}
