#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book
{
private:
    std::string author;
    std::string title;

public:
    Book();
    Book(const std::string& author, const std::string& title);
    Book(std::string&& author, std::string&& title);
    Book(const Book& book);
    Book(Book&& book);
    ~Book();

    std::string GetAuthor() const;
    void SetAuthor(const std::string& author);
    void SetAuthor(std::string&& author);

    std::string GetTitle() const;
    void SetTitle(const std::string& title);
    void SetTitle(std::string&& title);

    Book& operator=(const Book& book);
    Book& operator=(Book&& book);
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

#endif