#include "Book.h"

Book::Book()
{
    this->author = "";
    this->title = "";
    this->addDate = "";
    //std::cout << "Non parameterized constructor \n";
}

Book::Book(const std::string& author, const std::string& title, const std::string& addDate)
{
    this->author = author;
    this->title = title;
    this->addDate = addDate;
    //std::cout << "Parameterized constructor \n";
}

Book::Book(std::string&& author, std::string&& title, std::string&& addDate)
{
    this->author = std::move(author);
    this->title = std::move(title);
    this->addDate = std::move(addDate);
    //std::cout << "Parameterized move constructor \n";
}

Book::Book(const Book& book)
{
    this->author = book.author;
    this->title = book.title;
    this->addDate = book.addDate;
    //std::cout << "Copy constructor \n";
}

Book::Book(Book&& book)
{
    this->author = std::move(book.author);
    this->title = std::move(book.title);
    this->addDate = std::move(book.addDate);
    //std::cout << "Move constructor \n";
}

Book::~Book()
{
    //std::cout << "Destructed Book(author: " << this->author << ", title: " << this->title << ") \n";
}

std::string Book::GetAuthor() const
{
    return this->author;
}

std::string Book::GetAddDate() const
{
    return this->addDate;
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
    this->addDate = book.addDate;
    return *this;
}

Book& Book::operator=(Book&& book)
{
    this->author = std::move(book.author);
    this->title = std::move(book.title);
    this->addDate = std::move(book.addDate);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << book.GetTitle() << std::string(", autorstwa: ") << book.GetAuthor() << std::string(", dodano: ") << book.GetAddDate();
    return os;
}