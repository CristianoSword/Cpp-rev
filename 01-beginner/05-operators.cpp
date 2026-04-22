#include <iostream>

/**
 * C++ REVISION #5: Operators
 * Arithmetic, assignment, and comparison operators.
 */

int main() {
    int a = 10, b = 3;

    // Arithmetic
    std::cout << "Addition: " << a + b << std::endl;
    std::cout << "Subtraction: " << a - b << std::endl;
    std::cout << "Multiplication: " << a * b << std::endl;
    std::cout << "Division: " << static_cast<double>(a) / b << std::endl; // C++ static_cast for precision
    std::cout << "Remainder (Modulo): " << a % b << std::endl;

    // Increment / Decrement
    a++;
    std::cout << "After increment: " << a << std::endl;

    // Comparison
    bool isEqual = (a == 11);
    std::cout << "Is a equal to 11? " << (isEqual ? "Yes" : "No") << std::endl;

    return 0;
}
