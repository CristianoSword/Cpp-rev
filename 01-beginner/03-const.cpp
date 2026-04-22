#include <iostream>

/**
 * C++ REVISION #3: Constants
 * Using const and constexpr to define immutable values.
 */

int main() {
    // const: value cannot be changed after initialization
    const double PI = 3.14159;

    // constexpr: value evaluated at compile time
    constexpr int MAX_LEVEL = 100;

    std::cout << "Value of PI: " << PI << '\n';
    std::cout << "Max Level: " << MAX_LEVEL << '\n';

    // Uncommenting the next line would cause a compiler error:
    // PI = 3.14;

    return 0;
}
