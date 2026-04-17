#include <iostream>

using namespace std;

/**
 * C++ REVISION #10: Functions
 * Organizing code into reusable blocks.
 */

// Function Declaration (Prototype)
int add(int a, int b);
void greet(string name);

int main() {
    greet("Cristiano");

    int result = add(15, 30);
    cout << "15 + 30 = " << result << endl;

    return 0;
}

// Function Definition
int add(int a, int b) {
    return a + b;
}

void greet(string name) {
    cout << "Welcome to the C++ Guide, " << name << "!" << endl;
}
