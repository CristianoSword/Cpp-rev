#include <iostream>

/**
 * C++ REVISION #1: Hello World
 * The starting point of any C++ program.
 */

int main() {
    // std::cout is used to print text to the console.
    // '\n' inserts a newline. Prefer it over std::endl, which also flushes
    // the buffer and is usually unnecessary (and slower).
    std::cout << "Hello, C++ Revision!" << '\n';

    return 0;
}
