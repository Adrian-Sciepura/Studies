#include "Book.h"

Book::Book()
{
    this->author = "None";
    this->title = "None";
    std::cout << "Non parameterized constructor \n";
}

Book::Book(const std::string& author, const std::string& title)
{
    this->author = author;
    this->title = title;
    std::cout << "Parameterized constructor \n";
}

Book::Book(std::string&& author, std::string&& title)
{
    this->author = std::move(author);
    this->title = std::move(title);
    std::cout << "Parameterized move constructor \n";
}

Book::Book(const Book& book)
{
    this->author = book.author;
    this->title = book.title;
    std::cout << "Copy constructor \n";
}

Book::Book(Book&& book)
{
    this->author = std::move(book.author);
    this->title = std::move(book.title);
    std::cout << "Move constructor \n";
}

Book::~Book()
{
    std::cout << "Destructed Book(author: " << this->author << ", title: " << this->title << ") \n";
}

std::string Book::GetAuthor() const
{
    return this->author;
}

void Book::SetAuthor(const std::string& author)
{
    this->author = author;
}

void Book::SetAuthor(std::string&& author)
{
    this->author = std::move(author);
}

std::string Book::GetTitle() const
{
    return title;
}

void Book::SetTitle(const std::string& title)
{
    this->title = title;
}

void Book::SetTitle(std::string&& title)
{
    this->title = std::move(title);
}

Book& Book::operator=(const Book& book)
{
    this->author = book.author;
    this->title = book.title;
    return *this;
}

Book& Book::operator=(Book&& book)
{
    this->author = std::move(book.author);
    this->title = std::move(book.title);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << book.GetTitle() << std::string(" was written by: ") << book.GetAuthor();
    return os;
}