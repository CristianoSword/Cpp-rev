#include <iostream>
#include <iterator> // for std::size

/**
 * C++ REVISION #11: Arrays
 * Storing multiple values of the same type in a contiguous memory block.
 */

int main() {
    // Array declaration and initialization
    int scores[] = {90, 85, 70, 95, 80};

    // std::size (C++17) gives us the element count safely.
    // Using a hardcoded "5" would silently break if the array size changes.
    const std::size_t count = std::size(scores);

    // Accessing elements (0-indexed)
    std::cout << "First score: " << scores[0] << '\n';
    std::cout << "Last score: " << scores[count - 1] << '\n';

    // Modifying an element
    scores[2] = 75;

    // Iterating through an array
    std::cout << "All scores: ";
    for (std::size_t i = 0; i < count; ++i) {
        std::cout << scores[i] << " ";
    }
    std::cout << '\n';

    // Size of array (in bytes)
    std::cout << "Total size in bytes: " << sizeof(scores) << '\n';
    std::cout << "Number of elements: " << count << '\n';

    return 0;
}
