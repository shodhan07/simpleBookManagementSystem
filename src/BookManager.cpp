#include "BookManager.hpp"
#include <fstream>
#include <iostream>

BookManager::BookManager(const std::string &filePath)
    : filePath(filePath) {}

int BookManager::findIndexById(int id) const
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getId() == id)
            return i;
    }
    return -1;
}

void BookManager::loadFromFile()
{
    books.clear();
    std::ifstream in(filePath);
    if (!in.is_open())
        return;

    std::string line;
    while (std::getline(in, line))
    {
        Book b;
        if (Book::fromString(line, b))
        {
            books.push_back(b);
        }
    }
}

void BookManager::saveToFile() const
{
    std::ofstream out(filePath);
    for (int i = 0; i < books.size(); i++)
    {
        out << books[i].toString() << "\n";
    }
}

bool BookManager::addBook(const Book &book)
{
    if (findIndexById(book.getId()) != -1)
    {
        std::cout << "Book ID already exists.\n";
        return false;
    }
    books.push_back(book);
    return true;
}

Book *BookManager::searchBook(int id)
{
    int index = findIndexById(id);
    if (index == -1)
        return nullptr;
    return &books[index];
}

void BookManager::displayAll() const
{
    if (books.empty())
    {
        std::cout << "No books available.\n";
        return;
    }

    for (int i = 0; i < books.size(); i++)
    {
        std::cout << "----------------\n";
        books[i].display();
    }
}

void BookManager::displayExpensiveBooks(int minPrice)
{
    bool found = false;
    for (const auto &b : books)
    {
        if (b.getPrice() >= minPrice)
        {
            b.display();
            std::cout << "-----------------\n";
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No books found with price >= " << minPrice << "\n";
    }
}
