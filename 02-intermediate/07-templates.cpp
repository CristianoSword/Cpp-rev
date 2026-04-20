#include <iostream>
#include <string>

// Lesson 07: Basic Templates
// 
// Templates allow you to write generic code that works with any data type.
// Instead of writing a function for 'int' and another identical one for 'float',
// you write ONE template, and the compiler generates the variations as needed.

// 1. Function Template
// Conceptually: T is a placeholder for a type.
template <typename T>
T getMaximum(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}

// 2. Class Template
// Creating a generic "Box" that can store ANY type of data.
template <typename T>
class Box {
private:
    T item; // The type is generic!

public:
    // Constructor taking the generic type
    Box(T initialItem) : item(initialItem) {}

    T getItem() const {
        return item;
    }

    void setItem(T newItem) {
        item = newItem;
    }

    void printItem() const {
        std::cout << "Box contains: " << item << std::endl;
    }
};

int main() {
    std::cout << "--- Lesson 07: Basic Templates ---" << std::endl;

    // --- Testing Function Template ---
    std::cout << "\n[Function Templates]" << std::endl;
    
    // The compiler deduces T = int
    std::cout << "Max of 5 and 10: " << getMaximum(5, 10) << std::endl;
    
    // The compiler deduces T = double
    std::cout << "Max of 3.14 e 2.71: " << getMaximum(3.14, 2.71) << std::endl;
    
    // The compiler deduces T = std::string
    std::string word1 = "Apple";
    std::string word2 = "Zebra";
    std::cout << "Max alphabetically: " << getMaximum(word1, word2) << std::endl;

    // --- Testing Class Template ---
    std::cout << "\n[Class Templates]" << std::endl;

    // For classes, you usually have to explicitly state the type in angle brackets < >.
    Box<int> intBox(42);
    intBox.printItem();

    Box<std::string> stringBox("A generic string inside a box");
    stringBox.printItem();

    Box<double> doubleBox(99.99);
    doubleBox.printItem();

    return 0;
}
