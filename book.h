#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;


class Book
{
private:
    int ID;
    string Author;
    string Title;
    string Genre;
    int Year;
    bool Available;
    bool isVip;
    double Price;
    double Rating;

public:
    // Constructors
    Book();
    Book(int);
    Book(int, string, string, string, int, bool, bool, double, double);
    Book(Book &);

    // Setters
    void setID(int);
    void setAuthor(string);
    void setTitle(string);
    void setGenre(string);
    void setYear(int);
    void setAvailable(bool);
    void setIsVip(bool);
    void setPrice(double);
    void setRating(double);

    // Getters
    int getID();
    string getAuthor();
    string getTitle();
    string getGenre();
    int getYear();
    bool getAvailable();
    bool getIsVip();
    double getPrice();
    double getRating();

    // Display && Destructor
    void displayBookData();
    ~Book();
};

#endif
