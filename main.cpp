#include <iostream>
#include <string>
#include <iomanip> // For output formatting with setw
#include <cctype>  // For character manipulation (toupper)

using namespace std;

const int MAX_BOOKS = 100; // Maximum number of books the library can hold

// Class to represent a book with title, author, and publication year
class Book
{
private:
    string title;
    string author;
    int year;

public:
    // Constructor to initialize a Book object
    Book(string t = "", string a = "", int y = 0) : title(t), author(a), year(y) {}

    // Getter functions to access private members
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }

    // Function to set book details
    void setBookDetails(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }
};

// Class for managing the library and its collection of books
class Library
{
private:
    Book books[MAX_BOOKS]; // Array to store Book objects
    int bookCount; // Current number of books in the library

public:
    Library() : bookCount(0) {}

    // Convert a given title to uppercase
    void ConvertToUpper(string &title) const
    {
        for (char &ch : title)
        {
            ch = toupper(ch);
        }
    }

    // Add a new book to the library
    void AddBook()
    {
        if (bookCount >= MAX_BOOKS)
        {
            cout << "Library is full. Cannot add more books." << endl;
            return;
        }

        string title, author;
        int year;

        cout << "Enter the book title: ";
        cin.ignore();
        getline(cin, title);


        // Check if the book is already in the library
        for (int i = 0; i < bookCount; ++i)
        {
            if (books[i].getTitle() == title)
            {
                cout << "This book is already in the library." << endl;
                return;
            }
        }

        cout << "Enter the author's name: ";
        getline(cin, author);

        cout << "Enter the year of publication: ";
        cin >> year;

        // Add the new book to the library
        books[bookCount].setBookDetails(title, author, year);
        ++bookCount;
        cout << "Book successfully added!" << endl;
    }

    // Display all books in the library
    void DisplayBooks() const
    {
        if (bookCount == 0)
        {
            cout << "No books available in the library." << endl;
        }
        else
        {
            cout << "List of Books: " << endl;
            cout << left << setw(30) << "Title"
                 << setw(25) << "Author" << "Year" << endl;
            for (int i = 0; i < bookCount; ++i)
            {
                cout << left << setw(30) << books[i].getTitle()
                     << setw(25) << books[i].getAuthor()
                     << books[i].getYear() << endl;
            }
        }
    }

    // Search for a book by title
    void FindBook() const
    {
        string title;
        cout << "Enter the title of the book to search: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, title);
        ConvertToUpper(title);

        bool found = false;
        for (int i = 0; i < bookCount; ++i)
        {
            if (books[i].getTitle() == title)
            {
                cout << "Book found!" << endl;
                cout << "Title: " << books[i].getTitle() << endl;
                cout << "Author: " << books[i].getAuthor() << endl;
                cout << "Year: " << books[i].getYear() << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Book not found in the library." << endl;
        }
    }
};

// Main menu for interacting with the library
void ShowMenu(Library &lib)
{
    int choice;
    while (true)
    {
        cout << "\nLibrary Menu" << endl;
        cout << "1 - Add a Book" << endl;
        cout << "2 - Show All Books" << endl;
        cout << "3 - Search for a Book" << endl;
        cout << "4 - Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            lib.AddBook();
            break;
        case 2:
            system("cls");
            lib.DisplayBooks();
            break;
        case 3:
            system("cls");
            lib.FindBook();
            break;
        case 4:
            system("cls");
            return;
        default:
            system("cls");
            cout << "Invalid choice, please try again." << endl;
            cin.clear();
            break;
        }
    }
}

int main() {
    Library lib;
    ShowMenu(lib);
    return 0;
}
