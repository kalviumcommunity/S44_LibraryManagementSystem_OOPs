#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Abstract Class
class LibraryItem {
protected:
    std::string title;
    std::string id;

public:
    LibraryItem(const std::string& title, const std::string& id) : title(title), id(id) {}
    virtual void display() const = 0; // Pure virtual function
    virtual ~LibraryItem() {}
};

// Interface
class ILoanable {
public:
    virtual void loanItem() = 0;
    virtual void returnItem() = 0;
    virtual bool isLoaned() const = 0;
    virtual ~ILoanable() {}
};

// Inheritance, Implementing Interface
class Book : public LibraryItem, public ILoanable {
private:
    bool loaned;

public:
    Book(const std::string& title, const std::string& id) : LibraryItem(title, id), loaned(false) {}

    void display() const override {
        std::cout << "Book: " << title << " (ID: " << id << ")" << (loaned ? " [Loaned]" : " [Available]") << std::endl;
    }

    void loanItem() override {
        if (!loaned) {
            loaned = true;
        } else {
            std::cout << "Book is already loaned." << std::endl;
        }
    }

    void returnItem() override {
        if (loaned) {
            loaned = false;
        } else {
            std::cout << "Book was not loaned." << std::endl;
        }
    }

    bool isLoaned() const override {
        return loaned;
    }
};

// Encapsulation and Abstraction
class Patron {
private:
    std::string name;
    std::string patronId;

public:
    Patron(const std::string& name, const std::string& patronId) : name(name), patronId(patronId) {}

    void display() const {
        std::cout << "Patron: " << name << " (ID: " << patronId << ")" << std::endl;
    }
};

// Templates, SOLID Principles (Single Responsibility Principle, Open-Closed Principle)
template <typename T>
class LoanManager {
private:
    std::vector<T*> loanedItems;

public:
    void loanItem(T* item) {
        if (!item->isLoaned()) {
            item->loanItem();
            loanedItems.push_back(item);
        } else {
            std::cout << "Item is already loaned." << std::endl;
        }
    }

    void returnItem(T* item) {
        auto it = std::find(loanedItems.begin(), loanedItems.end(), item);
        if (it != loanedItems.end()) {
            item->returnItem();
            loanedItems.erase(it);
        } else {
            std::cout << "Item was not loaned." << std::endl;
        }
    }

    void displayLoanedItems() const {
        std::cout << "Loaned Items:" << std::endl;
        for (const auto& item : loanedItems) {
            item->display();
        }
    }
};

// Main Function
int main() {
    Book book1("1984", "B001");
    Book book2("To Kill a Mockingbird", "B002");
    Patron patron1("John Doe", "P001");

    LoanManager<Book> bookLoanManager;

    book1.display();
    book2.display();
    patron1.display();

    bookLoanManager.loanItem(&book1);
    bookLoanManager.loanItem(&book2);
    bookLoanManager.displayLoanedItems();

    bookLoanManager.returnItem(&book1);
    bookLoanManager.displayLoanedItems();

    return 0;
}
