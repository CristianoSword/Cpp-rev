// Lesson 13 (Advanced): Modules (C++20)
// 
// For 40 years, C++ used #include to copy-paste header files into source files.
// This made compilation EXTREMELY slow (e.g., #include <windows.h> copies 100k lines of code).
// 
// C++20 introduced Modules. Instead of text copy-pasting, Modules compile into 
// binary interfaces. They are faster, cleaner, and stop macro leakages.
// 
// NOTE: Compiler support for Modules is still maturing. You usually need special
// flags like `-fmodules-ts` (GCC) or `/std:c++20` (MSVC) to compile this natively.

/* 
// ==========================================
// File: math_module.cpp
// ==========================================
export module math_module; // Declares this file as a module

// Only 'export'ed functions are visible from the outside
export int add(int a, int b) {
    return a + b;
}

// This function is completely hidden (no 'export' keyword)
int secretHelper(int x) {
    return x * 2;
}

// ==========================================
// File: main.cpp
// ==========================================
import <iostream>;      // Importing the standard library (C++20 style)
import math_module;     // Importing our custom module

int main() {
    std::cout << "--- Lesson 13: C++20 Modules ---" << std::endl;
    
    // We can use the exported function freely
    std::cout << "5 + 5 = " << add(5, 5) << std::endl;
    
    // std::cout << secretHelper(10); // ERROR! secretHelper is not exported.

    return 0;
}
*/

// For the sake of this repository compiling seamlessly on all setups,
// we provide a dummy main using legacy includes to simulate the lesson.
#include <iostream>

int main() {
    std::cout << "--- Lesson 13: C++20 Modules ---" << std::endl;
    std::cout << "\nModules replace heavy #includes with 'export module X;' and 'import X;'." << std::endl;
    std::cout << "Check the source code of this file to see the actual syntax!" << std::endl;
    return 0;
}
