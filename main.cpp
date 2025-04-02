#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Library.h"
#include "Book.h"
using namespace std;

void Display_Menu();
void Display_Table_Header();
void saveLibrary(Library &);
void loadLibrary(Library &);

int main()
{
    Library L;
    bool Main_Menu = true;

    cout << "\t\t\t---- Library Application ----\n";
    cout << "\t\t==============================================\n";
    while (Main_Menu)
    {
        Display_Menu();
        int userChoice;
        while (true)
        {
            cin >> userChoice;
            if (userChoice >= 0 && userChoice < 13)
            {
                break;
            }
            else
            {
                cout << "Invalid Input! Please try again.\n";
            }
        }
        switch (userChoice)
        {
        case 1: // Add a new book.
        {
            L.addBook();
            break;
        }
        case 2: // Add multiple Books.
        {
            int n;
            cout << "How Many Added Books?";
            cin >> n;
            L.addMultipleBooks(n);
            break;
        }
        case 3: // Delete a book.
        {
            L.displayAllBooks();
            int index;
            cout << "Choose Book's Index To Delete: ";
            cin >> index;
            L.deleteBook(index);
            break;
        }
        case 4: // Update book's data.
        {
            int editInput;
            cout << "1)Edit Title.\n";
            cout << "2)Edit Author.\n";
            cout << "3)Edit Genre.\n";
            cout << "4)Edit Year.\n";
            cout << "5)Edit Availability.\n";
            cout << "6)Edit isVip.\n";
            cout << "7)Edit Price.\n";
            cout << "8)Edit Rating.\n";
            cout << "Enter Your Choice: ";
            cin >> editInput;

            Display_Table_Header();
            L.displayAllBooks();
            int index;
            cout << "Choose Book's ID To Update: ";
            cin >> index;
            switch (editInput)
            {
            case 1:
            {
                L.updateBookTitle(index);
                break;
            }
            case 2:
            {
                L.updateBookAuthor(index);
                break;
            }
            case 3:
            {
                L.updateBookGenre(index);
                break;
            }
            case 4:
            {
                L.updateBookYear(index);
                break;
            }
            case 5:
            {
                L.updateBookAvailability(index);
                break;
            }
            case 6:
            {
                L.updateBookVip(index);
                break;
            }
            case 7:
            {
                L.updateBookPrice(index);
                break;
            }
            case 8:
            {
                L.updateBookRating(index);
                break;
            }
            default:
                cout << "Invalid Input\n";
                break;
            }
            break;
        }
        case 5: // Search for a book.
        {
            int searchInput;
            cout << "1) Search By ID.\n";
            cout << "2) Search By Title.\n";
            cout << "Enter Your Choice: ";
            cin >> searchInput;
            switch (searchInput)
            {
            case 1:
            {
                int id;
                cout << "Enter Book's ID: ";
                cin >> id;
                Display_Table_Header();
                L.searchByID(id);
                break;
            }
            case 2:
            {
                string title;
                cout << "Enter Book's Title: ";
                cin.ignore();
                getline(cin, title);
                Display_Table_Header();
                L.searchByTitle(title);
                break;
            }
            default:
                cout << "Invalid Input\n";
                break;
            }
            break;
        }
        case 6: // Display by genre.
        {
            string genre;
            int editInput;
            cout << "1) Fantasy\n";
            cout << "2) Classic\n";
            cout << "3) Horror\n";
            cout << "4) Mystery\n";
            cout << "5) Adventure\n";
            cout << "Enter Your Choice: ";
            cin >> editInput;
            switch (editInput)
            {
            case 1:
            {
                genre = "Fantasy";
                break;
            }
            case 2:
            {
                genre = "Classic";
                break;
            }
            case 3:
            {
                genre = "Horror";
                break;
            }
            case 4:
            {
                genre = "Mystery";
                break;
            }
            case 5:
            {
                genre = "Adventure";
                break;
            }
            default:
                cout << "Invalid Input\n";
                break;
            }
            Display_Table_Header();
            L.displaySpecificGenre(genre);
            break;
        }
        case 7: // Display by Rating.
        {
            double ratingInput;
            cout << "Enter Books's Wanted Rating: ";
            cin >> ratingInput;
            Display_Table_Header();
            L.displaySpecificRating(ratingInput);
            break;
        }
        case 8: // Display available books.
        {
            Display_Table_Header();
            L.displayAvailableBooks();
            break;
        }
        case 9: // Display Vip books.
        {
            Display_Table_Header();
            L.displayVipBooks();
            break;
        }
        case 10: // Display library.
        {
            Display_Table_Header();
            L.displayAllBooks();
            break;
        }
        case 11: // Save to file.
        {
            saveLibrary(L);
            break;
        }
        case 12: // Load from file.
        {
            loadLibrary(L);
            break;
        }
        case 0: // Exit Program.
        {
            Main_Menu = false;
            break;
        }

        default:
            break;
        }
    }

    cout << "\n\t\t\tThanks For Using The Application!\n";
    cout << "\t\t\tProject By: Ali Emad\n";
    return 0;
}

void Display_Menu()
{
    cout << "\n\t\t\t==================================" << "\n";
    cout << "\t\t\tLibrary Menu:" << "\n";
    cout << "\t\t\t--------------------------" << "\n";
    cout << "\t\t\t1. Add a new Book." << "\n";
    cout << "\t\t\t2. Add multiple Books." << "\n";
    cout << "\t\t\t3. Delete a book." << "\n";
    cout << "\t\t\t4. Update book's data." << "\n";
    cout << "\t\t\t5. Search for a book." << "\n";
    cout << "\t\t\t6. Display by genre." << "\n";
    cout << "\t\t\t7. Display by Rating." << "\n";
    cout << "\t\t\t8. Display available books." << "\n";
    cout << "\t\t\t9. Display Vip books." << "\n";
    cout << "\t\t\t10. Display library." << "\n";
    cout << "\t\t\t11. Save to Books.txt." << "\n";
    cout << "\t\t\t12. Load from Books.txt." << "\n";
    cout << "\t\t\t0. Exit." << "\n";
    cout << "\t\t\t==================================" << "\n";
    cout << "Enter Your Choice: ";
}

void Display_Table_Header()
{
    cout << left << setw(10) << setfill(' ') << "\nID"
         << left << setw(30) << setfill(' ') << " Author"
         << left << setw(45) << setfill(' ') << " Title"
         << left << setw(13) << setfill(' ') << " Genre"
         << left << setw(10) << setfill(' ') << " Year"
         << left << setw(15) << setfill(' ') << " Availability"
         << left << setw(10) << setfill(' ') << " Vip"
         << left << setw(10) << setfill(' ') << " Price"
         << left << setw(7) << setfill(' ') << " Rating\n"
         << "-------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void saveLibrary(Library &lib)
{
    ofstream out("Books.txt");
    if (out.is_open())
    {
        for (int i = 0; i < lib.getCounter(); i++)
        {
            Book book = lib.getBook(i);
            out << "ID: " << book.getID() << "\n";
            out << "Author: " << book.getAuthor() << "\n";
            out << "Title: " << book.getTitle() << "\n";
            out << "Genre: " << book.getGenre() << "\n";
            out << "Year: " << book.getYear() << "\n";
            out << "Available: " << (book.getAvailable() ? "Yes" : "No") << "\n";
            out << "VIP: " << (book.getIsVip() ? "Yes" : "No") << "\n";
            out << "Price: " << fixed << setprecision(2) << book.getPrice() << "\n";
            out << "Rating: " << fixed << setprecision(1) << book.getRating() << "\n";
            if (i != lib.getCounter() - 1)
                out << "\n";
        }
        out.close();
        cout << "Library saved successfully to Books.txt!\n";
    }
    else
    {
        cout << "Failed to open Books.txt for saving!\n";
    }
}

void loadLibrary(Library &lib)
{
    lib.clearBooks();
    ifstream in("Books.txt");
    if (in.is_open())
    {
        string line, author, title, genre;
        int id, year;
        double price, rating;
        bool isAvailable, isVIP;

        while (getline(in, line))
        {
            if (line.empty())
                continue;

            id = (line.find("ID: ") == 0) ? stoi(line.substr(line.find(":") + 2)) : 0;

            getline(in, line);
            author = (line.find("Author: ") == 0) ? line.substr(line.find(":") + 2) : "";

            getline(in, line);
            title = (line.find("Title: ") == 0) ? line.substr(line.find(":") + 2) : "";

            getline(in, line);
            genre = (line.find("Genre: ") == 0) ? line.substr(line.find(":") + 2) : "";

            getline(in, line);
            year = (line.find("Year: ") == 0) ? stoi(line.substr(line.find(":") + 2)) : 0;

            getline(in, line);
            isAvailable = (line.find("Available: ") == 0 && line.substr(line.find(":") + 2) == "Yes");

            getline(in, line);
            isVIP = (line.find("VIP: ") == 0 && line.substr(line.find(":") + 2) == "Yes");

            getline(in, line);
            price = (line.find("Price: ") == 0) ? stod(line.substr(line.find(":") + 2)) : 0.0;

            getline(in, line);
            rating = (line.find("Rating: ") == 0) ? stod(line.substr(line.find(":") + 2)) : 0.0;

            if (id != 0 && !author.empty() && !title.empty())
            {
                Book B(id, author, title, genre, year, isAvailable, isVIP, price, rating);
                lib.addBook(B);
            }
        }

        in.close();
        cout << "Library loaded successfully from Books.txt!\n";
    }
    else
    {
        cout << "Failed to open Books.txt for loading!\n";
    }
}
