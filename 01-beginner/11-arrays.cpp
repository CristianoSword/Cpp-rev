#include <iostream>

using namespace std;

/**
 * C++ REVISION #11: Arrays
 * Storing multiple values of the same type in a contiguous memory block.
 */

int main() {
    // Array declaration and initialization
    int scores[5] = {90, 85, 70, 95, 80};

    // Accessing elements (0-indexed)
    cout << "First score: " << scores[0] << endl;
    cout << "Last score: " << scores[4] << endl;

    // Modifying an element
    scores[2] = 75;

    // Iterating through an array
    cout << "All scores: ";
    for (int i = 0; i < 5; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    // Size of array (in bytes)
    cout << "Total size in bytes: " << sizeof(scores) << endl;
    cout << "Number of elements: " << sizeof(scores) / sizeof(scores[0]) << endl;

    return 0;
}
