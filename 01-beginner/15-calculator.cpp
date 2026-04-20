#include <iostream>

using namespace std;

/**
 * C++ REVISION #15 PROJECT: Simple Calculator
 * A practical example combining variables, I/O, and switch-case.
 */

int main() {
    double num1, num2;
    char op;

    cout << "--- C++ Simple Calculator ---" << endl;
    
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "\nResult: ";
    switch (op) {
        case '+':
            cout << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << num1 / num2 << endl;
            else
                cout << "Error! Division by zero." << endl;
            break;
        default:
            cout << "Invalid operator." << endl;
            break;
    }

    return 0;
}
