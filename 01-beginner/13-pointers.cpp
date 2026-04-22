#include <iostream>

/**
 * C++ REVISION #13: Pointers and References
 * Understanding memory addresses and direct memory access.
 */

int main() {
    int value = 42;

    // Reference: an alias for an existing variable
    int &ref = value;
    ref = 100; // Changes 'value' to 100

    std::cout << "Value via reference: " << ref << '\n';
    std::cout << "Original value: " << value << '\n';

    // Pointer: a variable that stores a memory address
    int *ptr = &value; // & is the address-of operator

    std::cout << "\nMemory Address: " << ptr << '\n';
    std::cout << "Value via pointer (dereferencing): " << *ptr << '\n';

    // Modifying value via pointer
    *ptr = 500;
    std::cout << "New value: " << value << '\n';

    return 0;
}
