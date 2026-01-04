#pragma once
#include <vector>
#include <string>
#include "Book.hpp"

class BookManager
{
private:
    std::vector<Book> books;
    std::string filePath;

    int findIndexById(int id) const;

public:
    BookManager(const std::string &filePath);

    void loadFromFile();
    void saveToFile() const;

    bool addBook(const Book &book);
    Book *searchBook(int id);

    void displayAll() const;
};
