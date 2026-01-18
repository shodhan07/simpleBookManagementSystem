#pragma once
#include <string>

class Book
{
private:
    int id;
    std::string title;
    std::string author;
    int price;

public:
    Book();
    Book(int id, const std::string &title, const std::string &author, int price);

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getPrice() const;

    void display() const;

    std::string toString() const;
    static bool fromString(const std::string &line, Book &outBook);
};
