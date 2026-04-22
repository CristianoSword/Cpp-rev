#include <iostream>
#include <cmath> // for std::fabs

/**
 * C++ REVISION #15 PROJECT: Simple Calculator
 * A practical example combining variables, I/O, and switch-case.
 */

int main() {
    double num1, num2;
    char op;

    std::cout << "--- C++ Simple Calculator ---" << '\n';

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "\nResult: ";
    switch (op) {
        case '+':
            std::cout << num1 + num2 << '\n';
            break;
        case '-':
            std::cout << num1 - num2 << '\n';
            break;
        case '*':
            std::cout << num1 * num2 << '\n';
            break;
        case '/':
            // Floating-point comparison with 0 is unreliable for very small
            // values (e.g. 1e-12). Use an epsilon-based check instead.
            if (std::fabs(num2) > 1e-9)
                std::cout << num1 / num2 << '\n';
            else
                std::cout << "Error! Division by zero." << '\n';
            break;
        default:
            std::cout << "Invalid operator." << '\n';
            break;
    }

    return 0;
}
