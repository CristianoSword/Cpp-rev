#include <iostream>
#include <vector>

// Lesson 02 (Advanced): The Rule of 3, The Rule of 5, and The Rule of 0
// 
// These rules are guidelines for writing safe classes, especially when managing
// dynamic resources (like raw pointers).
// 
// - Rule of 3 (Pre-C++11): If your class needs a custom:
//   1. Destructor
//   2. Copy Constructor
//   3. Copy Assignment Operator
//   ... then it ALMOST CERTAINLY needs all three.
// 
// - Rule of 5 (C++11 onwards): Adds move semantics to the Rule of 3.
//   If you define any of the 3 above, you should also define:
//   4. Move Constructor
//   5. Move Assignment Operator
// 
// - Rule of 0 (Modern C++): Design your classes so that they DON'T NEED custom
//   destructors or copy/move semantics at all! Use smart pointers (std::unique_ptr)
//   or STL containers (std::vector) to manage resources automatically.

// ==========================================
// Example: Rule of 5 Implementation
// ==========================================
class RuleOfFive {
private:
    int* data;

public:
    // Regular Constructor
    RuleOfFive(int val) {
        data = new int(val);
        std::cout << "Constructor called. Data: " << *data << std::endl;
    }

    // 1. Destructor
    ~RuleOfFive() {
        if (data) {
            std::cout << "Destructor freeing data." << std::endl;
            delete data;
        }
    }

    // 2. Copy Constructor
    RuleOfFive(const RuleOfFive& other) {
        std::cout << "Copy Constructor called." << std::endl;
        data = new int(*(other.data));
    }

    // 3. Copy Assignment Operator
    RuleOfFive& operator=(const RuleOfFive& other) {
        std::cout << "Copy Assignment called." << std::endl;
        if (this != &other) { // Guard against self-assignment: a = a
            delete data; // Free old
            data = new int(*(other.data)); // Copy new
        }
        return *this;
    }

    // 4. Move Constructor
    RuleOfFive(RuleOfFive&& other) noexcept {
        std::cout << "Move Constructor called." << std::endl;
        data = other.data; // Steal
        other.data = nullptr; // Nullify
    }

    // 5. Move Assignment Operator
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {
        std::cout << "Move Assignment called." << std::endl;
        if (this != &other) {
            delete data; // Free old
            data = other.data; // Steal
            other.data = nullptr; // Nullify
        }
        return *this;
    }
};

int main() {
    std::cout << "--- Lesson 02: Rule of 3/5/0 ---" << std::endl;

    std::cout << "\n[Testing Rule of 5 Class]" << std::endl;
    
    RuleOfFive a(100);
    
    std::cout << "---" << std::endl;
    RuleOfFive b = a; // Copy Constructor
    
    std::cout << "---" << std::endl;
    RuleOfFive c(200);
    c = a; // Copy Assignment
    
    std::cout << "---" << std::endl;
    RuleOfFive d = std::move(a); // Move Constructor
    
    std::cout << "---" << std::endl;
    c = std::move(b); // Move Assignment

    std::cout << "\n--- Exiting Scope ---" << std::endl;
    return 0;
}
