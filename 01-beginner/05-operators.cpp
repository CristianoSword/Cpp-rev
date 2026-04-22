#include <iostream>

/**
 * C++ REVISION #5: Operators
 * Arithmetic, assignment, and comparison operators.
 */

int main() {
    int a = 10, b = 3;

    // Arithmetic
    std::cout << "Addition: " << a + b << '\n';
    std::cout << "Subtraction: " << a - b << '\n';
    std::cout << "Multiplication: " << a * b << '\n';
    std::cout << "Division: " << static_cast<double>(a) / b << '\n'; // C++ static_cast for precision
    std::cout << "Remainder (Modulo): " << a % b << '\n';

    // Increment / Decrement
    a++;
    std::cout << "After increment: " << a << '\n';

    // Comparison
    bool isEqual = (a == 11);
    std::cout << "Is a equal to 11? " << (isEqual ? "Yes" : "No") << '\n';

    return 0;
}
