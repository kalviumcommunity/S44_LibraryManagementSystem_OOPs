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

// Main Function
int main() {

    return 0;
}
