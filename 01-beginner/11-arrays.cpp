#include <iostream>

/**
 * C++ REVISION #11: Arrays
 * Storing multiple values of the same type in a contiguous memory block.
 */

int main() {
    // Array declaration and initialization
    int scores[5] = {90, 85, 70, 95, 80};

    // Accessing elements (0-indexed)
    std::cout << "First score: " << scores[0] << std::endl;
    std::cout << "Last score: " << scores[4] << std::endl;

    // Modifying an element
    scores[2] = 75;

    // Iterating through an array
    std::cout << "All scores: ";
    for (int i = 0; i < 5; i++) {
        std::cout << scores[i] << " ";
    }
    std::cout << std::endl;

    // Size of array (in bytes)
    std::cout << "Total size in bytes: " << sizeof(scores) << std::endl;
    std::cout << "Number of elements: " << sizeof(scores) / sizeof(scores[0]) << std::endl;

    return 0;
}
