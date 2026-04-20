#include <iostream>

using namespace std;

/**
 * C++ REVISION #5: Operators
 * Arithmetic, assignment, and comparison operators.
 */

int main() {
    int a = 10, b = 3;

    // Arithmetic
    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << (double)a / b << endl; // Type casting for precision
    cout << "Remainder (Modulo): " << a % b << endl;

    // Increment / Decrement
    a++;
    cout << "After increment: " << a << endl;
    
    // Comparison
    bool isEqual = (a == 11);
    cout << "Is a equal to 11? " << (isEqual ? "Yes" : "No") << endl;

    return 0;
}
