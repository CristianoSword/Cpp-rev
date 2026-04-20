#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // Essential for std::function

// Lesson 14: Lambdas and std::function
// 
// Lambdas (introduced in C++11) are "anonymous inline functions".
// They are incredibly useful for short snippets of code, especially as 
// arguments for STL algorithms like std::sort or std::find_if.
// 
// Syntax: [capture_list](parameters) -> return_type { body }

// A function that takes another function as a parameter!
// std::function<return_type(parameter_types)>
void executeOperation(int a, int b, std::function<int(int, int)> op) {
    std::cout << "Result of operation: " << op(a, b) << std::endl;
}

int main() {
    std::cout << "--- Lesson 14: Lambdas & std::function ---" << std::endl;

    // ==========================================
    // 1. Basic Lambda
    // ==========================================
    std::cout << "\n[1. Basic Lambda]" << std::endl;
    // We can store a lambda in an 'auto' variable
    auto sayHello = []() {
        std::cout << "Hello from a Lambda function!" << std::endl;
    };
    sayHello(); // Calling it

    auto add = [](int x, int y) {
        return x + y;
    };
    std::cout << "5 + 3 = " << add(5, 3) << std::endl;


    // ==========================================
    // 2. The Capture List []
    // ==========================================
    // The capture list defines what variables from the SURROUNDING SCOPE
    // the lambda is allowed to use.
    // [ ]  : Captures nothing.
    // [=]  : Captures everything by VALUE (read-only copy).
    // [&]  : Captures everything by REFERENCE (can modify original variables).
    // [x, &y]: Captures x by value, and y by reference.
    std::cout << "\n[2. Capture List]" << std::endl;
    
    int multiplier = 10;
    int counter = 0;

    auto multiplyAndCount = [multiplier, &counter](int value) {
        counter++; // Valid! 'counter' is captured by reference.
        // multiplier++; // ERROR! 'multiplier' is captured by value (read-only).
        return value * multiplier;
    };

    std::cout << "10 * 5 = " << multiplyAndCount(5) << std::endl;
    std::cout << "Times called: " << counter << std::endl;


    // ==========================================
    // 3. Lambdas in STL Algorithms
    // ==========================================
    std::cout << "\n[3. Lambdas in STL Algorithms]" << std::endl;
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // Counting how many EVEN numbers are in the vector
    int evenCount = std::count_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });
    std::cout << "There are " << evenCount << " even numbers." << std::endl;


    // ==========================================
    // 4. std::function (Passing functions around)
    // ==========================================
    std::cout << "\n[4. std::function]" << std::endl;
    
    // Passing our 'add' lambda
    executeOperation(10, 20, add);
    
    // Passing a new lambda directly inline
    executeOperation(50, 10, [](int a, int b) {
        return a - b;
    });

    return 0;
}
