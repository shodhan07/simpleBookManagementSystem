#include <iostream>
#include "BookManager.hpp"

int main()
{
    BookManager manager("data/books.txt");
    manager.loadFromFile();

    int choice;
    do
    {
        std::cout << "\n=== Book Management System ===\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. View All Books\n";
        std::cout << "3. Search Book\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            int id;
            std::string title, author;

            std::cout << "Enter book ID: ";
            std::cin >> id;
            std::cin.ignore();

            std::cout << "Enter title: ";
            std::getline(std::cin, title);

            std::cout << "Enter author: ";
            std::getline(std::cin, author);

            Book b(id, title, author);
            if (manager.addBook(b))
            {
                manager.saveToFile();
                std::cout << "Book added.\n";
            }
        }
        else if (choice == 2)
        {
            manager.displayAll();
        }
        else if (choice == 3)
        {
            int id;
            std::cout << "Enter book ID: ";
            std::cin >> id;

            Book *b = manager.searchBook(id);
            if (b)
            {
                b->display();
            }
            else
            {
                std::cout << "Book not found.\n";
            }
        }

    } while (choice != 0);

    return 0;
}
