#include <iostream>
#include <string>

using namespace std;

/**
 * C++ REVISION #4: User Input
 * Using cin to read data from the standard input.
 */

int main() {
    string fullName;
    int age;

    cout << "Enter your age: ";
    cin >> age;

    // We can use cin.ignore() to clear the newline character 
    // before reading a string with getline
    cin.ignore();

    cout << "Enter your full name: ";
    getline(cin, fullName);

    cout << "Hello " << fullName << "! You are " << age << " years old." << endl;

    return 0;
}
