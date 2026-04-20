#include <iostream>
#include <concepts> // Essential for standard concepts like std::integral
#include <string>

// Lesson 14 (Advanced): Concepts (C++20)
// 
// Templates are great, but they have a huge problem: if you pass the wrong type 
// (e.g., a std::string into a math template), the compiler throws thousands of 
// lines of incomprehensible template gibberish errors.
// 
// C++20 Concepts fix this! They allow you to add "Constraints" to your templates.
// "This template ONLY accepts types that fulfill this specific Condition."
// If the condition fails, you get one clean, readable error message.

// ==========================================
// 1. Using Standard Concepts
// ==========================================

// This template only accepts types that are "integral" (int, long, short, char).
// Floats, doubles, and strings are BANNED.
template <std::integral T>
T addIntegers(T a, T b) {
    return a + b;
}

// Alternate syntax (using 'requires' clause)
template <typename T>
requires std::floating_point<T>
T addFloats(T a, T b) {
    return a + b;
}

// ==========================================
// 2. Creating Custom Concepts
// ==========================================

// We define a Concept called "Addable".
// It requires that two objects of type T can be added together using the '+' operator.
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b }; // This expression must be valid
};

template <Addable T>
T genericAdd(T a, T b) {
    return a + b;
}

int main() {
    std::cout << "--- Lesson 14: Concepts (C++20) ---" << std::endl;

    std::cout << "\n[1. Standard Concepts]" << std::endl;
    std::cout << "Adding ints: " << addIntegers(10, 5) << std::endl;
    // std::cout << addIntegers(3.14, 2.0); // COMPILER ERROR: not an integral type!

    std::cout << "Adding floats: " << addFloats(3.14, 2.71) << std::endl;
    // std::cout << addFloats(10, 5); // COMPILER ERROR: not a floating point type!

    std::cout << "\n[2. Custom Concepts]" << std::endl;
    std::string s1 = "Hello";
    std::string s2 = " World";
    
    // Works because std::string has the '+' operator!
    std::cout << "Adding Strings: " << genericAdd(s1, s2) << std::endl;

    return 0;
}
