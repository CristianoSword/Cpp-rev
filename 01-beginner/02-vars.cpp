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

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << " years old" << std::endl;
    std::cout << "Height: " << height << "m" << std::endl;
    std::cout << "Initial: " << initial << std::endl;
    std::cout << "Programmer: " << (isProgrammer ? "Yes" : "No") << std::endl;

    return 0;
}
