#ifndef LIBRARY_H
#define LIBRARY_H

#include <initializer_list>
#include "Book.h"

class Library
{
private:
    std::size_t size;
    Book* books;

public:
    Library(std::size_t size = 1);
    Library(std::initializer_list<Book> list);
    Library(const Library& library);
    Library(Library&& library);
    ~Library();
    
    std::size_t GetSize() const;

    Library& operator=(const Library& library);
    Library& operator=(Library&& library);
    Book& operator[](std::size_t index);
    const Book& operator[](std::size_t index) const;
    friend std::ostream& operator<<(std::ostream& os, const Library& library);
};

#endif