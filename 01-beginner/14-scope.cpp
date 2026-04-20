#include <iostream>

using namespace std;

/**
 * C++ REVISION #14: Scope and Lifetime
 * Global vs Local variables and static storage duration.
 */

// Global Variable: Accessible throughout the entire file
int globalCount = 0;

void increment() {
    // Static Variable: Keeps its value between function calls
    static int staticCount = 0;
    
    // Local Variable: Destroyed when function finishes
    int localCount = 0;

    globalCount++;
    staticCount++;
    localCount++;

    cout << "Global: " << globalCount << " | Static: " << staticCount << " | Local: " << localCount << endl;
}

int main() {
    cout << "Scope demonstration:" << endl;
    increment();
    increment();
    increment();

    // localCount is not accessible here
    // cout << localCount; // ERROR

    return 0;
}
