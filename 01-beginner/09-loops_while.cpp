#include <iostream>

using namespace std;

/**
 * C++ REVISION #9: While and Do-While Loops
 * Repeating actions based on a boolean condition.
 */

int main() {
    int count = 5;

    // while: check condition first
    cout << "While loop countdown: ";
    while (count > 0) {
        cout << count << " ";
        count--;
    }
    cout << endl;

    // do-while: execute once, then check condition
    int choice;
    do {
        cout << "\nEnter 0 to exit: ";
        cin >> choice;
    } while (choice != 0);

    cout << "Exited successfully." << endl;

    return 0;
}
