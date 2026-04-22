#include <iostream>
#include <string>

/**
 * C++ REVISION #2: Variables and Types
 * Demonstration of primitive types and variable declaration.
 */

int main() {
    // Basic types
    int age = 25;
    double height = 1.75;
    char initial = 'C';
    bool isProgrammer = true;
    std::string name = "Cristiano";

    std::cout << "Name: " << name << '\n';
    std::cout << "Age: " << age << " years old" << '\n';
    std::cout << "Height: " << height << "m" << '\n';
    std::cout << "Initial: " << initial << '\n';
    std::cout << "Programmer: " << (isProgrammer ? "Yes" : "No") << '\n';

    return 0;
}
