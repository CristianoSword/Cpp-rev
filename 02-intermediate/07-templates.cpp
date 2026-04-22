#include <iostream>
#include <string>
#include <utility>

// Lesson 07: Basic Templates
//
// Templates allow you to write generic code that works with any data type.
// Instead of writing a function for 'int' and another identical one for 'float',
// you write ONE template, and the compiler generates the variations as needed.

// 1. Function Template
// Conceptually: T is a placeholder for a type.
// We pass by const& so we don't copy heavy types (e.g. std::string) and
// return by const& so we don't copy the result either.
template <typename T>
const T& getMaximum(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// 2. Class Template
// Creating a generic "Box" that can store ANY type of data.
template <typename T>
class Box {
private:
    T item; // The type is generic!

public:
    // Constructor taking the generic type
    explicit Box(T initialItem) : item(std::move(initialItem)) {}

    const T& getItem() const {
        return item;
    }

    void setItem(T newItem) {
        item = std::move(newItem);
    }

    void printItem() const {
        std::cout << "Box contains: " << item << '\n';
    }
};

int main() {
    std::cout << "--- Lesson 07: Basic Templates ---" << '\n';

    // --- Testing Function Template ---
    std::cout << "\n[Function Templates]" << '\n';

    // The compiler deduces T = int
    std::cout << "Max of 5 and 10: " << getMaximum(5, 10) << '\n';

    // The compiler deduces T = double
    std::cout << "Max of 3.14 and 2.71: " << getMaximum(3.14, 2.71) << '\n';

    // The compiler deduces T = std::string
    std::string word1 = "Apple";
    std::string word2 = "Zebra";
    std::cout << "Max alphabetically: " << getMaximum(word1, word2) << '\n';

    // --- Testing Class Template ---
    std::cout << "\n[Class Templates]" << '\n';

    // For classes, you usually have to explicitly state the type in angle brackets < >.
    Box<int> intBox(42);
    intBox.printItem();

    Box<std::string> stringBox("A generic string inside a box");
    stringBox.printItem();

    Box<double> doubleBox(99.99);
    doubleBox.printItem();

    return 0;
}
