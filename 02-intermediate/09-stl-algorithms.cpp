#include <iostream>
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
    std::cout << std::endl;
}

int main() {
    std::cout << "--- Lesson 09: STL Algorithms ---" << std::endl;

    std::vector<int> numbers = { 42, 10, 73, 5, 100, 21, 5 };
    printVector("Original", numbers);

    // ==========================================
    // 1. std::sort
    // ==========================================
    std::cout << "\n[1. std::sort]" << std::endl;
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
    std::cout << "\n[2. std::find & std::count]" << std::endl;
    
    // Finding an element
    int target = 73;
    auto it = std::find(numbers.begin(), numbers.end(), target);
    
    if (it != numbers.end()) {
        std::cout << "Found " << target << "!" << std::endl;
    } else {
        std::cout << target << " not found." << std::endl;
    }

    // Counting occurrences
    int countFives = std::count(numbers.begin(), numbers.end(), 5);
    std::cout << "Number 5 appears " << countFives << " times." << std::endl;


    // ==========================================
    // 3. std::transform & std::accumulate
    // ==========================================
    std::cout << "\n[3. std::transform & std::accumulate]" << std::endl;

    std::vector<int> doubledScores(numbers.size());
    // Transform applies an operation to every element
    std::transform(numbers.begin(), numbers.end(), doubledScores.begin(), [](int n) {
        return n * 2;
    });
    printVector("Doubled values", doubledScores);

    // Accumulate sums up all elements (requires <numeric>)
    // Starting value of sum is 0
    int totalSum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum of original elements: " << totalSum << std::endl;


    // ==========================================
    // 4. std::remove_if
    // ==========================================
    std::cout << "\n[4. std::remove_if (Erase-Remove idiom)]" << std::endl;
    // Removes elements that match a condition (e.g., remove odd numbers)
    // Note: remove_if just shifts elements. You MUST call erase to resize the vector.
    numbers.erase(
        std::remove_if(numbers.begin(), numbers.end(), [](int n){ return n % 2 != 0; }),
        numbers.end()
    );
    printVector("Only even numbers left", numbers);

    return 0;
}
