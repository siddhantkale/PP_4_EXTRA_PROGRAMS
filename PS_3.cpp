#include <iostream>
#include <cstring>

class Book {
private:
    char* author;
    char* title;
    float price;
    char* publisher;
    int stock;

public:
    // Constructor to initialize members and allocate memory
    Book(const char* author, const char* title, float price, const char* publisher, int stock)
        : price(price), stock(stock) {
        this->author = new char[strlen(author) + 1];
        strcpy(this->author, author);

        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);

        this->publisher = new char[strlen(publisher) + 1];
        strcpy(this->publisher, publisher);
    }

    // Destructor to free allocated memory
    ~Book() {
        delete[] author;
        delete[] title;
        delete[] publisher;
    }

    // Function to display book details
    void displayDetails() const {
        std::cout << "\nBook Details:\n";
        std::cout << "Author: " << author << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Publisher: " << publisher << std::endl;
        std::cout << "Stock: " << stock << " copies\n";
    }

    // Function to check availability and calculate cost
    void sellBook(int requestedCopies) {
        if (requestedCopies <= stock) {
            float totalCost = requestedCopies * price;
            std::cout << "Book available. Total cost: $" << totalCost << std::endl;
            stock -= requestedCopies;  // Update stock
        } else {
            std::cout << "Required copies not in stock.\n";
        }
    }
};

int main() {
    // Example usage
    Book book1("John Doe", "Programming in C++", 25.99, "Tech Publishing", 10);

    // Display book details
    book1.displayDetails();

    // Sell some copies
    int requestedCopies;
    std::cout << "\nEnter the number of copies required: ";
    std::cin >> requestedCopies;

    book1.sellBook(requestedCopies);

    // Display updated book details
    book1.displayDetails();

    return 0;
}
