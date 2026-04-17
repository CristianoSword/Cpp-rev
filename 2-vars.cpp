#include <iostream>
#include <string>

using namespace std;

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
    string name = "Cristiano";

    cout << "Name: " << name << endl;
    cout << "Age: " << age << " years old" << endl;
    cout << "Height: " << height << "m" << endl;
    cout << "Initial: " << initial << endl;
    cout << "Programmer: " << (isProgrammer ? "Yes" : "No") << endl;

    return 0;
}
