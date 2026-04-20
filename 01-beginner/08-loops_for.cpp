#include <iostream>

using namespace std;

/**
 * C++ REVISION #8: For Loops
 * Repeating actions for a fixed number of times.
 */

int main() {
    cout << "Counting from 1 to 10:" << endl;

    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;

    // Nested for loop (Multiplication Table for 2)
    cout << "Multiplication Table for 2:" << endl;
    for (int j = 1; j <= 10; j++) {
        cout << "2 x " << j << " = " << 2 * j << endl;
    }

    return 0;
}
