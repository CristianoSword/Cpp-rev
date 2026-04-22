#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Essential for STL algorithms
#include <numeric>   // Essential for std::accumulate

// Lesson 09: STL - Algorithms
//
// STL algorithms are a set of functions designed to be used on ranges of elements.
// They operate heavily on iterators (e.g., vec.begin(), vec.end()).
// Why use them? They are heavily optimized, peer-reviewed, and prevent bugs
// associated with manual "for" loops.

void printVector(const std::string& prefix, const std::vector<int>& vec) {
    std::cout << prefix << ": ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << '\n';
}

int main() {
    std::cout << "--- Lesson 09: STL Algorithms ---" << '\n';

    std::vector<int> numbers = { 42, 10, 73, 5, 100, 21, 5 };
    printVector("Original", numbers);

    // ==========================================
    // 1. std::sort
    // ==========================================
    std::cout << "\n[1. std::sort]" << '\n';
    // Sorts the range in ascending order.
    std::sort(numbers.begin(), numbers.end());
    printVector("Sorted ascending", numbers);

    // Sorts the range in descending order using a lambda function
    // (Lambdas will be covered deeply later, think of it as a quick inline function)
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });
    printVector("Sorted descending", numbers);


    // ==========================================
    // 2. std::find and std::count
    // ==========================================
    std::cout << "\n[2. std::find & std::count]" << '\n';

    // Finding an element
    int target = 73;
    auto it = std::find(numbers.begin(), numbers.end(), target);

    if (it != numbers.end()) {
        std::cout << "Found " << target << "!" << '\n';
    } else {
        std::cout << target << " not found." << '\n';
    }

    // Counting occurrences
    int countFives = std::count(numbers.begin(), numbers.end(), 5);
    std::cout << "Number 5 appears " << countFives << " times." << '\n';


    // ==========================================
    // 3. std::transform & std::accumulate
    // ==========================================
    std::cout << "\n[3. std::transform & std::accumulate]" << '\n';

    std::vector<int> doubledScores(numbers.size());
    // Transform applies an operation to every element
    std::transform(numbers.begin(), numbers.end(), doubledScores.begin(), [](int n) {
        return n * 2;
    });
    printVector("Doubled values", doubledScores);

    // Accumulate sums up all elements (requires <numeric>)
    // Starting value of sum is 0
    int totalSum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum of original elements: " << totalSum << '\n';


    // ==========================================
    // 4. std::erase_if (C++20)
    // ==========================================
    std::cout << "\n[4. std::erase_if - removes odd numbers in one call]" << '\n';
    // std::erase_if (C++20) replaces the classic erase-remove_if idiom:
    //   v.erase(std::remove_if(v.begin(), v.end(), pred), v.end());
    std::erase_if(numbers, [](int n) { return n % 2 != 0; });
    printVector("Only even numbers left", numbers);

    return 0;
}
