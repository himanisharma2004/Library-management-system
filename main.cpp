#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isAvailable;
};

class Library {
    vector<Book> books;
    int nextId;

public:
    Library() : nextId(1) {}

    void addBook(const string& title, const string& author) {
        Book newBook = { nextId++, title, author, true };
        books.push_back(newBook);
        cout << "Book added successfully with ID: " << newBook.id << endl;
    }

    void viewBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        cout << "\nLibrary Books:\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id
                 << ", Title: " << book.title
                 << ", Author: " << book.author
                 << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
        }
    }

    void deleteBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                books.erase(it);
                cout << "Book with ID " << id << " deleted successfully.\n";
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    void borrowBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (book.isAvailable) {
                    book.isAvailable = false;
                    cout << "You have borrowed: " << book.title << endl;
                } else {
                    cout << "Book is already borrowed.\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    void returnBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (!book.isAvailable) {
                    book.isAvailable = true;
                    cout << "You have returned: " << book.title << endl;
                } else {
                    cout << "Book was not borrowed.\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }
};

int main() {
    Library library;
    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Delete Book\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore();
                string title, author;
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.addBook(title, author);
                break;
            }
            case 2:
                library.viewBooks();
                break;
            case 3: {
                int id;
                cout << "Enter book ID to delete: ";
                cin >> id;
                library.deleteBook(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter book ID to borrow: ";
                cin >> id;
                library.borrowBook(id);
                break;
            }
            case 5: {
                int id;
                cout << "Enter book ID to return: ";
                cin >> id;
                library.returnBook(id);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
