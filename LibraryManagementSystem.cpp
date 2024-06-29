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

// Main Function
int main() {

    return 0;
}
