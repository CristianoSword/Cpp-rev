#include <iostream>
#include <string>

/**
 * C++ REVISION #12: Strings
 * Working with the std::string class for text manipulation.
 */

int main() {
    std::string greeting = "Hello";
    std::string name = "Cristiano";

    // Concatenation
    std::string message = greeting + ", " + name + "!";
    std::cout << message << '\n';

    // String length
    std::cout << "Message length: " << message.length() << '\n';

    // String indexing
    std::cout << "First character: " << message[0] << '\n';

    // Substring (position, length)
    std::string sub = message.substr(0, 5);
    std::cout << "Substring: " << sub << '\n';

    // Finding text
    std::size_t found = message.find("Cristiano");
    if (found != std::string::npos) {
        std::cout << "'Cristiano' found at index: " << found << '\n';
    }

    return 0;
}
