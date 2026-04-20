#include <iostream>

// Lesson 04 (Advanced): Compile-Time Metaprogramming
// 
// Metaprogramming is writing code that executes DURING COMPILATION, not at runtime.
// This means the compiler itself does the calculations, and the binary only 
// contains the final, pre-calculated result. Zero runtime cost!
// 
// Pre-C++11, this was heavily done using Template Metaprogramming (TMP).
// In modern C++, 'constexpr' is often preferred, but understanding TMP is a rite of passage.

// ==========================================
// 1. Template Metaprogramming: Factorial
// ==========================================

// Generic template: Factorial of N is N * Factorial of N-1
template <int N>
struct Factorial {
    // 'value' is a compile-time constant
    static const int value = N * Factorial<N - 1>::value;
};

// Base case (Template Specialization): Factorial of 0 is 1
template <>
struct Factorial<0> {
    static const int value = 1;
};


// ==========================================
// 2. Template Metaprogramming: Fibonacci
// ==========================================
template <int N>
struct Fibonacci {
    static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<1> {
    static const int value = 1;
};

template <>
struct Fibonacci<0> {
    static const int value = 0;
};

int main() {
    std::cout << "--- Lesson 04: Compile-time Metaprogramming ---" << std::endl;

    std::cout << "\n[1. Factorial using TMP]" << std::endl;
    // The value "120" is hardcoded into the assembly. No multiplication happens at runtime!
    std::cout << "Factorial of 5 is: " << Factorial<5>::value << std::endl;
    std::cout << "Factorial of 7 is: " << Factorial<7>::value << std::endl;

    std::cout << "\n[2. Fibonacci using TMP]" << std::endl;
    // The value "55" is hardcoded into the assembly.
    std::cout << "10th Fibonacci number is: " << Fibonacci<10>::value << std::endl;

    return 0;
}
