#include <iostream>
#include <string>

/**
 * C++ REVISION #10: Functions
 * Organizing code into reusable blocks.
 */

// Function Declaration (Prototype)
int add(int a, int b);
void greet(std::string name);

int main() {
    greet("Cristiano");

    int result = add(15, 30);
    std::cout << "15 + 30 = " << result << std::endl;

    return 0;
}

// Function Definition
int add(int a, int b) {
    return a + b;
}

void greet(std::string name) {
    std::cout << "Welcome to the C++ Guide, " << name << "!" << std::endl;
}
