#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "Book.h"


class Library
{
private:
    int Counter;
    int Capacity;
    Book *Books = new Book[Capacity];
    void Resize()
    {
        Capacity *= 2;
        Book *temp = new Book[Capacity];
        for (int i = 0; i < Counter; i++)
        {
            temp[i] = Books[i];
        }
        delete[] Books;
        Books = temp;
    }

public:
    Library();
    void clearBooks()
    {
        for (int i = 0; i < Counter; i++)
        {
            Books[i] = Book();
        }
        Counter = 0;
    }

    void addBook();
    void addBook(Book);
    void addMultipleBooks(int);
    void deleteBook(int);
    void updateBookTitle(int);
    void updateBookAuthor(int);
    void updateBookGenre(int);
    void updateBookYear(int);
    void updateBookAvailability(int);
    void updateBookVip(int);
    void updateBookPrice(int);
    void updateBookRating(int);
    void searchByID(int);
    void searchByTitle(string);
    void displaySpecificGenre(string);
    void displaySpecificRating(double);
    void displayAvailableBooks();
    void displayVipBooks();
    void displayAllBooks();
    Book getBook(int);
    int getCounter();
    ~Library();
};

#endif
