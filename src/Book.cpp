#include "Book.hpp"
#include <iostream>
#include <sstream>

Book::Book() : id(0) {}

Book::Book(int id, const std::string &title, const std::string &author, int price)
    : id(id), title(title), author(author), price(price) {}

int Book::getId() const
{
    return id;
}

std::string Book::getTitle() const
{
    return title;
}

std::string Book::getAuthor() const
{
    return author;
}

int Book::getPrice() const
{
    return price;
}

void Book::display() const
{
    std::cout << "ID     : " << id << "\n"
              << "Title  : " << title << "\n"
              << "Author : " << author << "\n"
              << "Price : " << price << "\n";
}

std::string Book::toString() const
{
    std::ostringstream oss;
    oss << id << "|" << title << "|" << author << "|" << price;
    return oss.str();
}

bool Book::fromString(const std::string &line, Book &outBook)
{
    std::stringstream ss(line);
    std::string token, title, author;
    int id, price;

    if (!std::getline(ss, token, '|'))
        return false;
    try
    {
        id = std::stoi(token);
    }
    catch (...)
    {
        return false;
    }

    if (!std::getline(ss, title, '|'))
        return false;
    if (!std::getline(ss, author, '|'))
        return false;
    if (!std::getline(ss, token, '|'))
        return false;

    try
    {
        price = std::stoi(token);
    }
    catch (...)
    {
        return false;
    }

    outBook = Book(id, title, author, price);
    return true;
}
