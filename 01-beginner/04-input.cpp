#include <iostream>
#include <string>

/**
 * C++ REVISION #4: User Input
 * Using std::cin to read data from the standard input.
 */

int main() {
    std::string fullName;
    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;

    // We can use std::cin.ignore() to clear the newline character
    // before reading a string with std::getline
    std::cin.ignore();

    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);

    std::cout << "Hello " << fullName << "! You are " << age << " years old." << std::endl;

    return 0;
}
