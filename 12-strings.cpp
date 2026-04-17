#include <iostream>
#include <string>

using namespace std;

/**
 * C++ REVISION #12: Strings
 * Working with the std::string class for text manipulation.
 */

int main() {
    string greeting = "Hello";
    string name = "Cristiano";

    // Concatenation
    string message = greeting + ", " + name + "!";
    cout << message << endl;

    // String length
    cout << "Message length: " << message.length() << endl;

    // String indexing
    cout << "First character: " << message[0] << endl;

    // Substring (position, length)
    string sub = message.substr(0, 5);
    cout << "Substring: " << sub << endl;

    // Finding text
    size_t found = message.find("Cristiano");
    if (found != string::npos) {
        cout << "'Cristiano' found at index: " << found << endl;
    }

    return 0;
}
