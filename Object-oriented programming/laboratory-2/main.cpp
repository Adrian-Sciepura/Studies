#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"

using std::string, std::cout, std::endl;

int main()
{
    /*
    string a="J.K. Rowling", t="Harry Potter";
    Book e;
    cout << "e: "<< e << endl;
    Book b1 = {a, t};
    cout << "b1: "<< b1 << endl;
    Book b2 = {"J.R.R. Tolkien", "Hobbit"};
    cout << "b2: "<< b2 << endl;
    Book b3 = b1;
    cout << "b3: "<< b3 << " b1: " << b1 << endl;
    e = std::move(b2);
    cout << "e: "<< e << " b2:" << b2 << endl;
    e.SetAuthor("C.S. Lewis");
    cout << "e: "<< e << endl;
    e.SetTitle("The Chronicles of Narnia");
    cout << "e: "<< e << endl;
    */

    //Exercise 2

    Library e;
    cout << "e: "<< e << endl;

    Library l1 = {
        {"J.K. Rowling", "Harry Potter"},
        {"J.R.R. Tolkien", "Hobbit"},
        {"C.S. Lewis", "The Chronicles of Narnia"}
    };

    cout << "l1: "<< l1 << endl;
    
    Library l2(2);
    cout << "l2: "<< l2 << endl;
    l2[0] = {"J.R.R. Tolkien", "The lord of the rings"};
    l2[1] = {"Andrzej Sapkowski", "The Witcher"};
    cout << "l2: "<< l2 << endl;
    
    e = std::move(l2);
    cout << "e: " << e << " l2: "<< l2 << endl;
    
    l1[0] = std::move(e[1]);
    cout << "l1: " << l1 << " e: "<< e << endl;
}