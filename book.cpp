#include "Book.h"
#include <iostream>
#include <iomanip>
using namespace std;

Book::Book() // Default Constructor
{
    ID = 0;
    Author = "NULL";
    Title = "NULL";
    Genre = "NULL";
    Year = 0;
    Available = false;
    isVip = false;
    Price = 0.0;
    Rating = 0.0;
}

Book::Book(int id) // Parameterized Constructor
{
    ID = id;
}
Book::Book(int id, string author, string title, string genre, int year, bool available, bool isvip, double price, double rating) // Parameterized Constructor
{
    ID = id;
    Author = author;
    Title = title;
    Genre = genre;
    Year = year;
    Available = available;
    isVip = isvip;
    Price = price;
    Rating = rating;
}
Book::Book(Book &copy) // Copy Constructor
{
    ID = copy.ID;
    Author = copy.Author;
    Title = copy.Title;
    Genre = copy.Genre;
    Year = copy.Year;
    Available = copy.Available;
    isVip = copy.isVip;
    Price = copy.Price;
    Rating = copy.Rating;
}

// Setters
void Book::setID(int id)
{
    ID = id;
}
void Book::setAuthor(string author)
{
    Author = author;
}
void Book::setTitle(string title)
{
    Title = title;
}
void Book::setGenre(string genre)
{
    Genre = genre;
}
void Book::setYear(int year)
{
    Year = year;
}
void Book::setAvailable(bool available)
{
    Available = available;
}
void Book::setIsVip(bool isvip)
{
    isVip = isvip;
}
void Book::setPrice(double price)
{
    Price = price;
}
void Book::setRating(double rating)
{
    Rating = rating;
}

// Getters
int Book::getID()
{
    return ID;
}
string Book::getAuthor()
{
    return Author;
}
string Book::getTitle()
{
    return Title;
}
string Book::getGenre()
{
    return Genre;
}
int Book::getYear()
{
    return Year;
}
bool Book::getAvailable()
{
    return Available;
}
bool Book::getIsVip()
{
    return isVip;
}
double Book::getPrice()
{
    return Price;
}
double Book::getRating()
{
    return Rating;
}

// Display && Destructor
void Book::displayBookData()
{
    cout << left << setw(10) << setfill(' ') << ID;
    cout << left << setw(30) << setfill(' ') << Author;
    cout << left << setw(45) << setfill(' ') << Title;
    cout << left << setw(13) << setfill(' ') << Genre;
    cout << left << setw(10) << setfill(' ') << Year;
    cout << left << setw(15) << setfill(' ') << (Available ? "Yes" : "No");
    cout << left << setw(10) << setfill(' ') << (isVip ? "Yes" : "No");
    cout << left << setw(10) << setfill(' ') << Price;
    cout << left << setw(7) << setfill(' ') << Rating;
    cout << left;
    cout << "\n";
}

Book::~Book()
{
}
