#include <iostream>
#include <vector>
#include <string>
#include <chrono>

// Lesson 11 (Advanced): Optimization and Profiling
// 
// C++ is fast by default, but you can easily make it slow if you don't understand
// memory allocation and copying.
// 
// Common Anti-Patterns:
// 1. Passing large objects by value instead of by const reference.
// 2. Returning large objects by value (though Return Value Optimization [RVO] mitigates this).
// 3. Dynamic memory allocation inside tight loops.
// 
// We will use std::chrono to "profile" a bad function vs a good function.

class HeavyData {
public:
    std::string text;
    std::vector<int> numbers;
    
    // Simulating a heavy constructor
    HeavyData() {
        text = "This is a very long string that we don't want to copy multiple times.";
        for (int i = 0; i < 10000; i++) {
            numbers.push_back(i);
        }
    }
    
    // Copy Constructor - Adding a print to show when a copy happens
    HeavyData(const HeavyData& other) : text(other.text), numbers(other.numbers) {
        // std::cout << "[WARNING] A deep copy was made!" << std::endl;
    }
};

// ==========================================
// BAD PRACTICE: Pass by Value
// ==========================================
// 'data' is COPIED. A whole new vector and string are allocated and copied in memory.
int processBad(HeavyData data) {
    return data.numbers.size();
}

// ==========================================
// GOOD PRACTICE: Pass by Const Reference
// ==========================================
// 'data' is passed as a pointer under the hood. NO COPY IS MADE.
// 'const' guarantees we won't modify the original object.
int processGood(const HeavyData& data) {
    return data.numbers.size();
}


int main() {
    std::cout << "--- Lesson 11: Optimization and Profiling ---" << std::endl;
    
    std::cout << "\nCreating heavy data object..." << std::endl;
    HeavyData myData;

    int iterations = 1000;
    std::cout << "\nRunning " << iterations << " iterations..." << std::endl;

    // --- Profiling BAD practice ---
    auto startBad = std::chrono::high_resolution_clock::now();
    
    long dummySum1 = 0;
    for (int i = 0; i < iterations; i++) {
        dummySum1 += processBad(myData); // Causes 1000 DEEP COPIES!
    }
    
    auto endBad = std::chrono::high_resolution_clock::now();
    auto durationBad = std::chrono::duration_cast<std::chrono::milliseconds>(endBad - startBad);

    // --- Profiling GOOD practice ---
    auto startGood = std::chrono::high_resolution_clock::now();
    
    long dummySum2 = 0;
    for (int i = 0; i < iterations; i++) {
        dummySum2 += processGood(myData); // 0 Copies made. Fast pointer pass.
    }
    
    auto endGood = std::chrono::high_resolution_clock::now();
    auto durationGood = std::chrono::duration_cast<std::chrono::microseconds>(endGood - startGood);

    // --- Results ---
    std::cout << "\n--- Results ---" << std::endl;
    std::cout << "Bad (Pass by Value): " << durationBad.count() << " milliseconds." << std::endl;
    std::cout << "Good (Pass by Ref) : " << durationGood.count() << " MICROSECONDS! (Much faster)" << std::endl;

    return 0;
}
