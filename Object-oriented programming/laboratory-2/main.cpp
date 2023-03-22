#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"

using std::string, std::cout, std::endl, std::cin;


int MainMenu()
{
    int choice = 0;
    cout << "\nWybierz dostepna z opcji\n";
    cout << "1. Dodaj nowa ksiazke \n";
    cout << "2. Wyswietl liste wszystkich ksiazek \n";
    cout << "3. Wyszukaj autora danej ksiazki\n";
    cout << "4. Wyjscie \n";
    cout << "Wybor: ";
    cin >> choice;
    return choice;
}

Book AddBookMenu()
{
    string author, title, addDate;
    cout << "\nPodaj Autora: ";
    cin >> author;

    cout << "Podaj Nazwe: ";
    cin >> title;

    cout << "Podaj date dodania (format DD-MM-RRRR): ";
    cin >> addDate;
    return { author, title, addDate };
}

std::string GetAuthorName(const Library& library)
{
    string title;
    cout << "\nPodaj nazwe ksiazki: ";
    cin >> title;

    string result = library.SearchForAuthor(title);
    return result;
}

void ShowAllBooks(const Library& library, int numOfBooks)
{
    int counter = 0;
    while(cin.get() != '\n' && counter <= numOfBooks);
    {
        if(getch() == 80)
        {
            
        }
    }
}

int main()
{
    bool quit = false;
    int numOfBooks = 0;
    int choice = 0;
    Library library(20);
    
    while(!quit)
    {
        switch(choice)
        {
            case 1:
            {
                if(numOfBooks == library.GetSize())
                {
                    cout << "\nNiestety biblioteka jest juz pelna !\n";
                }
                else
                {
                    library[numOfBooks] = AddBookMenu();
                    numOfBooks++;
                }
                choice = 0;
                break;
            }
            case 2:
            {
                if(numOfBooks == 0)
                {
                    cout << "\nBiblioteka jest pusta !\n";
                }
                cout << '\n' << library;
                choice = 0;
                break;
            }
            case 3:
            {
                cout << GetAuthorName(library) << "\n";
                choice = 0;
                break;
            }
            case 4:
            {
                quit = true;
                break;
            }
            default:
            {
                choice = MainMenu();
            }
        }
    }
}