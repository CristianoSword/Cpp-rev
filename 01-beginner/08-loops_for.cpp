#include <iostream>

/**
 * C++ REVISION #8: For Loops
 * Repeating actions for a fixed number of times.
 */

int main() {
    std::cout << "Counting from 1 to 10:" << std::endl;

    for (int i = 1; i <= 10; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Nested for loop (Multiplication Table for 2)
    std::cout << "Multiplication Table for 2:" << std::endl;
    for (int j = 1; j <= 10; j++) {
        std::cout << "2 x " << j << " = " << 2 * j << std::endl;
    }

    return 0;
}
