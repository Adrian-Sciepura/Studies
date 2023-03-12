#include <iostream>
#include <string>
#include "Book.h"

using std::string, std::cout, std::endl;

int main()
{
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
}