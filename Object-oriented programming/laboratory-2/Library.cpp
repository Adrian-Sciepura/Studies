#include "Library.h"

Library::Library(std::size_t size)
{
    this->size = size;
    this->books = new Book[size];
}

Library::Library(std::initializer_list<Book> list)
{
    this->size = list.size();
    this->books = new Book[list.size()];

    std::size_t i = 0;
    for(Book book: list)
    {
        this->books[i] = book;
        i++;
    }
}

Library::Library(const Library& library)
{
    this->size = library.size;
    this->books = new Book[library.size];
    for(int i = 0; i < library.size; i++)
    {
        this->books[i] = library.books[i];
    }
}

Library::Library(Library&& library)
{
    this->books = library.books;
    this->size = library.size;
    library.books = nullptr;
    library.size = 0;
}

Library::~Library()
{
    if(books != nullptr)
    {
        delete[] books;
    }
}

std::size_t Library::GetSize() const
{
    return this->size;
}

Library& Library::operator=(const Library& library)
{
    if(this->size != library.size)
    {
        delete[] books;
        this->size = library.size;
        this->books = new Book[library.size];
    }

    for(int i = 0; i < library.size; i++)
    {
        this->books[i] = library.books[i];
    }

    return *this;
}

Library& Library::operator=(Library&& library)
{
    std::swap(this->size, library.size);
    std::swap(this->books, library.books);
    return *this;
}

Book& Library::operator[](std::size_t index)
{
    return books[index];
}

const Book& Library::operator[](std::size_t index) const
{
    return books[index];
}

std::ostream& operator<<(std::ostream& os, const Library& library)
{
    os << std::string("Library: ");
    for(int i = 0; i < library.size; i++)
    {
        os << library.books[i] << ' ';
    }
    return os;
}