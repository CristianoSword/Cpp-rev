#include <iostream>

// Lesson 05 (Advanced): constexpr and consteval
// 
// Introduced in C++11 and improved in C++14/C++20, 'constexpr' replaces the old 
// ugly Template Metaprogramming with normal-looking functions that can run at COMPILE TIME.
// 
// - constexpr: "Might" be evaluated at compile time if given constant arguments. 
//              Otherwise, runs at runtime like a normal function.
// - consteval (C++20): "MUST" be evaluated at compile time. If it can't, it throws a compilation error.

// ==========================================
// 1. constexpr (C++11/C++14)
// ==========================================

// A constexpr function that looks like a totally normal function!
constexpr int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// ==========================================
// 2. consteval (C++20)
// ==========================================

// This function is GUARANTEED to run only during compilation.
// Used for heavy math or parsing strings at compile time to save runtime cost.
consteval int square(int n) {
    return n * n;
}

int main() {
    std::cout << "--- Lesson 05: constexpr & consteval ---" << std::endl;

    // --- Testing constexpr ---
    std::cout << "\n[1. constexpr]" << std::endl;
    
    // Calculated at COMPILE TIME because '5' is a constant
    constexpr int fact5 = factorial(5); 
    std::cout << "Factorial of 5 (compile-time): " << fact5 << std::endl;

    // Calculated at RUNTIME because 'x' is a variable
    int x = 6;
    int factX = factorial(x);
    std::cout << "Factorial of X (runtime): " << factX << std::endl;


    // --- Testing consteval ---
    std::cout << "\n[2. consteval]" << std::endl;
    
    // Success: '10' is a constant, so this runs at compile time
    constexpr int sq10 = square(10);
    std::cout << "Square of 10 (guaranteed compile-time): " << sq10 << std::endl;

    // ERROR! If uncommented, this won't even compile because 'y' is a runtime variable,
    // and 'square' is marked as consteval (compile-time ONLY).
    // int y = 4;
    // int sqY = square(y); 

    return 0;
}
