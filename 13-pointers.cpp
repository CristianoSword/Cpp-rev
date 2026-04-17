#include <iostream>

using namespace std;

/**
 * C++ REVISION #13: Pointers and References
 * Understanding memory addresses and direct memory access.
 */

int main() {
    int value = 42;
    
    // Reference: an alias for an existing variable
    int &ref = value; 
    ref = 100; // Changes 'value' to 100
    
    cout << "Value via reference: " << ref << endl;
    cout << "Original value: " << value << endl;

    // Pointer: a variable that stores a memory address
    int *ptr = &value; // & is the address-of operator

    cout << "\nMemory Address: " << ptr << endl;
    cout << "Value via pointer (dereferencing): " << *ptr << endl;

    // Modifying value via pointer
    *ptr = 500;
    cout << "New value: " << value << endl;

    return 0;
}
