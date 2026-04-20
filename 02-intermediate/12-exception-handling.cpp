#include <iostream>
#include <string>
#include <stdexcept> // Standard exceptions (e.g., runtime_error, out_of_range)

// Lesson 12: Exception Handling (try, catch, throw)
// 
// When an error occurs at runtime (e.g., dividing by zero, file not found),
// the program can "throw" an exception. If it's not "caught", the program crashes.
// 
// - try: A block of code where exceptions might occur.
// - throw: Used to signal that an error happened.
// - catch: A block that handles the thrown exception without crashing.

// A function that might fail
double divide(double a, double b) {
    if (b == 0.0) {
        // Throwing a standard runtime_error with a custom message
        throw std::runtime_error("Division by zero is mathematically impossible!");
    }
    return a / b;
}

// A custom exception class inheriting from std::exception
class NegativeAgeException : public std::exception {
public:
    // Overriding the what() method to provide the error message
    const char* what() const noexcept override {
        return "Age cannot be negative! Are you a time traveler?";
    }
};

void setAge(int age) {
    if (age < 0) {
        // Throwing our custom exception
        throw NegativeAgeException();
    }
    std::cout << "Age successfully set to: " << age << std::endl;
}

int main() {
    std::cout << "--- Lesson 12: Exception Handling ---" << std::endl;

    // ==========================================
    // 1. Handling division by zero
    // ==========================================
    std::cout << "\n[1. Standard Exception]" << std::endl;
    try {
        std::cout << "10 / 2 = " << divide(10.0, 2.0) << std::endl;
        
        // This line will THROW an exception
        std::cout << "5 / 0 = " << divide(5.0, 0.0) << std::endl;
        
        // This line will NEVER run because the flow jumps to the catch block
        std::cout << "This won't be printed." << std::endl;
    } 
    catch (const std::runtime_error& e) {
        // We catch by const reference to avoid copying the exception object
        std::cout << "[ERROR CAUGHT]: " << e.what() << std::endl;
    }

    // ==========================================
    // 2. Handling custom exceptions
    // ==========================================
    std::cout << "\n[2. Custom Exception]" << std::endl;
    try {
        setAge(25);
        setAge(-5); // Will THROW
    }
    catch (const NegativeAgeException& e) {
        std::cout << "[CUSTOM ERROR CAUGHT]: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        // A generic catch block to handle any other standard exceptions.
        // It's good practice to catch the most specific exceptions first,
        // and the base class (std::exception) last.
        std::cout << "[UNKNOWN ERROR]: " << e.what() << std::endl;
    }

    std::cout << "\nProgram reached the end safely without crashing!" << std::endl;

    return 0;
}
