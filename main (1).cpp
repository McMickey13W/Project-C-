#include <iostream>
#include <cstring>

using namespace std;




const int MAX_BOOKS = 100;

struct Book {
    char title[50];
    char author[50];
    bool isIssued;
};

Book books[MAX_BOOKS];
int bookCount = 0;

void preloadBooks() {
    const char* titles[20] = {
        "C++ Programming", "Data Structures", "Algorithms in C++", "Computer Networks",
        "Operating Systems", "Database Systems", "Software Engineering", "Discrete Mathematics",
        "Machine Learning Basics", "Artificial Intelligence", "Computer Architecture", "Cybersecurity Fundamentals",
        "Web Development", "Mobile App Development", "Cloud Computing", "Human-Computer Interaction",
        "Compiler Design", "Object-Oriented Design", "Data Mining", "Computer Graphics"
    };
    const char* authors[20] = {
        "Bjarne Stroustrup", "Mark Weiss", "Robert Lafore", "Andrew Tanenbaum",
        "Silberschatz", "Raghu Ramakrishnan", "Ian Sommerville", "Kenneth Rosen",
        "Tom Mitchell", "Stuart Russell", "David Patterson", "William Stallings",
        "Jon Duckett", "Paul Deitel", "Rajkumar Buyya", "Alan Dix",
        "Aho & Ullman", "Grady Booch", "Jiawei Han", "Foley & Van Dam"
    };

    for (int i = 0; i < 20 && bookCount < MAX_BOOKS; i++) {
        strcpy(books[bookCount].title, titles[i]);
        strcpy(books[bookCount].author, authors[i]);
        books[bookCount].isIssued = false;
        bookCount++;
    }
}

void addBook() {
    if (bookCount < MAX_BOOKS) {
        Book newBook;
        cin.ignore();  // Clear newline
        cout << "Enter Book Title: ";
        cin.getline(newBook.title, 50);
        cout << "Enter Book Author: ";
        cin.getline(newBook.author, 50);
        newBook.isIssued = false;

        books[bookCount++] = newBook;
        cout << "Book added successfully.\n";
    } else {
        cout << "Book list is full.\n";
    }
}

void viewBooks() {
    if (bookCount == 0) {
        cout << "No books available.\n";
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        cout << "Index: " << i
             << ", Title: " << books[i].title
             << ", Author: " << books[i].author;
        cout << (books[i].isIssued ? " (Issued)" : " (Available)") << endl;
    }
}

void issueBook(int index) {
    if (index >= 0 && index < bookCount && !books[index].isIssued) {
        books[index].isIssued = true;
        cout << "Book issued successfully." << endl;
    } else {
        cout << "Book cannot be issued." << endl;
    }
}

int main() {
    preloadBooks();  // Load 20 books at program start

cout << "ST.MARY UNIVERSITY" << endl << "COMPUTER SCIENCE DEPARTMENT";

    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. View Books\n";
        cout << "2. Add Book\n";
        cout << "3. Issue Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewBooks();
                break;
            case 2:
                addBook();
                break;
            case 3: {
                int index;
                cout << "Enter book index to issue: ";
                cin >> index;
                issueBook(index);
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
