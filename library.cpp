#include "Library.h"
#include "Book.h"
#include <iostream>
using namespace std;

Library::Library()
{
    Counter = 0;
    Capacity = 1;
    Books = new Book[Capacity];
}
void Library::addBook()
{
    if (Counter == Capacity)
    {
        Resize();
    }
    string author, title, genre;
    int id, year;
    bool isVip, available;
    double price, rating;
    cout << "Enter Book's ID: ";
    cin >> id;
    cout << "Enter Book's Author: ";
    cin.ignore();
    getline(cin, author);
    cout << "Enter Book's Title: ";
    getline(cin, title);
    cout << "Enter Book's Genre: ";
    cin >> genre;
    cout << "Enter Book's Year: ";
    cin >> year;
    cout << "Is the book available?(0/1) ";
    cin >> available;
    cout << "Is the book Vip?(0/1) ";
    cin >> isVip;
    cout << "Enter Book's Price: ";
    cin >> price;
    cout << "Enter Book's Rating: ";
    cin >> rating;
    Book B(id, author, title, genre, year, available, isVip, price, rating);
    Books[Counter++] = B;
    cout << "Book Added Successfully!\n";
}
void Library::addBook(Book B)
{
    if (Counter == Capacity)
    {
        Resize();
    }
    Books[Counter++] = B;
    cout << "Book Added Successfully!\n";
}
void Library::addMultipleBooks(int n)
{
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            addBook();
        }
        cout << "Books Added Successfully!\n";
    }
    else
    {
        cout << "Invalid Input!\n";
    }
}
void Library::deleteBook(int n)
{
    if (n >= 0 && n < Counter)
    {
        for (int i = n; i < Counter - 1; i++)
        {
            Books[i] = Books[i + 1];
        }
        Counter--;
        cout << "Book Deleted Successfully!\n";
    }
    else
    {
        cout << "Invalid book index!\n";
    }
}
void Library::updateBookTitle(int id)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getID() == id)
        {
            string newTitle;
            cout << "Enter Updated Title: ";
            cin.ignore();
            getline(cin, newTitle);
            Books[i].setTitle(newTitle);
            cout << "Book Updated Successfully!\n";
            return;
        }
    }
    cout << "Invalid Book ID!\n";
}
void Library::updateBookAuthor(int id)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getID() == id)
        {
            string newAuthor;
            cout << "Enter Updated Author: ";
            cin.ignore();
            getline(cin, newAuthor);
            Books[i].setAuthor(newAuthor);
            cout << "Book Updated Successfully!\n";
            return;
        }
    }
    cout << "Invalid Book ID!\n";
}

void Library::updateBookGenre(int id)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getID() == id)
        {
            string newGenre;
            cout << "Enter Updated Genre: ";
            cin >> newGenre;
            Books[i].setGenre(newGenre);
            cout << "Book Updated Successfully!\n";
            return;
        }
    }
    cout << "Invalid Book ID!\n";
}
void Library::updateBookYear(int id)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getID() == id)
        {
            int newYear;
            cout << "Enter Updated Year: ";
            cin >> newYear;
            Books[i].setYear(newYear);
            cout << "Book Updated Successfully!\n";
            return;
        }
    }
    cout << "Invalid Book ID!\n";
}
void Library::updateBookAvailability(int id)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getID() == id)
        {
            bool newAvailability;
            cout << "Is It Available(0/1)? ";
            cin >> newAvailability;
            Books[i].setAvailable(newAvailability);
            cout << "Book Updated Successfully!\n";
            return;
        }
    }
    cout << "Invalid Book ID!\n";
}
void Library::updateBookVip(int id)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getID() == id)
        {
            bool newVip;
            cout << "Is It Vip(0/1)? ";
            cin >> newVip;
            Books[i].setIsVip(newVip);
            cout << "Book Updated Successfully!\n";
            return;
        }
    }
    cout << "Invalid Book ID!\n";
}
void Library::updateBookPrice(int id)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getID() == id)
        {
            double newPrice;
            cout << "Enter Updated Price: ";
            cin >> newPrice;
            Books[i].setPrice(newPrice);
            cout << "Book Updated Successfully!\n";
            return;
        }
    }
    cout << "Invalid Book ID!\n";
}
void Library::updateBookRating(int id)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getID() == id)
        {
            double newRating;
            cout << "Enter Updated Rating: ";
            cin >> newRating;
            Books[i].setRating(newRating);
            cout << "Book Updated Successfully!\n";
            return;
        }
    }
    cout << "Invalid Book ID!\n";
}

void Library::searchByID(int id)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getID() == id)
        {
            Books[i].displayBookData();
            return;
        }
    }
    cout << "Book Not Found!\n";
}
void Library::searchByTitle(string title)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getTitle() == title)
        {
            Books[i].displayBookData();
            return;
        }
    }
    cout << "Book Not Found!\n";
}
void Library::displaySpecificGenre(string genre)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getGenre() == genre)
        {
            Books[i].displayBookData();
        }
    }
}
void Library::displaySpecificRating(double rating)
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getRating() >= rating)
        {
            Books[i].displayBookData();
        }
    }
}
void Library::displayAvailableBooks()
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getAvailable())
        {
            Books[i].displayBookData();
        }
    }
}
void Library::displayVipBooks()
{
    for (int i = 0; i < Counter; i++)
    {
        if (Books[i].getIsVip())
        {
            Books[i].displayBookData();
        }
    }
}
void Library::displayAllBooks()
{
    for (int i = 0; i < Counter; i++)
    {
        Books[i].displayBookData();
    }
}
Book Library::getBook(int index)
{
    if (index >= 0 && index < Counter)
    {
        return Books[index];
    }
    else
    {
        cout << "Invalid index! Returning a default book.\n";
        return Book();
    }
}

int Library::getCounter()
{
    return Counter;
}

Library::~Library()
{
    delete[] Books;
}
