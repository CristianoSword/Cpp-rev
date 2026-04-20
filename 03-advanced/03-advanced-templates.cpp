#include <iostream>
#include <string>

// Lesson 03 (Advanced): Advanced Templates and Specialization
// 
// Templates are powerful, but sometimes we want a generic behavior for MOST types,
// and a SPECIFIC behavior for a particular type. This is Template Specialization.
// 
// Furthermore, Variadic Templates (C++11) allow a template to accept an 
// ARBITRARY number of arguments (like printf).

// ==========================================
// 1. Template Specialization
// ==========================================

// Generic template
template <typename T>
class Printer {
public:
    void print(T value) {
        std::cout << "Generic Printer: " << value << std::endl;
    }
};

// Specialized template ONLY for std::string
// Syntax: template <> class Name<SpecificType>
template <>
class Printer<std::string> {
public:
    void print(std::string value) {
        std::cout << "STRING-SPECIFIC Printer! [\"" << value << "\"]" << std::endl;
    }
};

// Specialized template ONLY for bool
template <>
class Printer<bool> {
public:
    void print(bool value) {
        std::cout << "BOOL-SPECIFIC Printer! [" << (value ? "TRUE" : "FALSE") << "]" << std::endl;
    }
};


// ==========================================
// 2. Variadic Templates
// ==========================================

// Base case to stop recursion when there are no more arguments
void printAll() {
    std::cout << std::endl;
}

// Variadic template taking at least one 'T', and a "pack" of remaining 'Args'
template <typename T, typename... Args>
void printAll(T first, Args... rest) {
    std::cout << first << " ";
    // This recursively calls printAll with the remaining arguments,
    // peeling them off one by one.
    printAll(rest...); 
}

int main() {
    std::cout << "--- Lesson 03: Advanced Templates ---" << std::endl;

    std::cout << "\n[1. Template Specialization]" << std::endl;
    Printer<int> intPrinter;
    intPrinter.print(42); // Calls generic
    
    Printer<double> doublePrinter;
    doublePrinter.print(3.14); // Calls generic

    Printer<std::string> stringPrinter;
    stringPrinter.print("Hello Templates"); // Calls string specialization!

    Printer<bool> boolPrinter;
    boolPrinter.print(true); // Calls bool specialization!


    std::cout << "\n[2. Variadic Templates]" << std::endl;
    std::cout << "Printing multiple types magically: ";
    
    // We can pass ANY number of arguments of ANY types!
    printAll(100, "Arthur", 3.1415, 'A', false);

    return 0;
}
