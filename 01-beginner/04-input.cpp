#include <iostream>
#include <limits>
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

    // After reading a number with >>, the trailing newline is still in the
    // buffer. std::cin.ignore() without arguments only discards ONE character,
    // which breaks if the user typed extra whitespace. The robust form ignores
    // everything up to and including the next newline.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);

    std::cout << "Hello " << fullName << "! You are " << age << " years old." << std::endl;

    return 0;
}
