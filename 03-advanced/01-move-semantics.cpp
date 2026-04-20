#include <iostream>
#include <string>
#include <vector>

// Lesson 01 (Advanced): Move Semantics and Rvalue References
// 
// In C++11, move semantics were introduced to optimize performance.
// Instead of copying heavy objects (like large strings or vectors), we "steal" 
// or "move" their resources if the source object is temporary and about to die anyway.
// 
// - lvalue: An object that occupies an identifiable location in memory (e.g., variables).
// - rvalue (&&): A temporary value that does not persist (e.g., literal numbers, temporary function returns).
// - std::move: Casts an lvalue to an rvalue reference, telling the compiler "you can steal my data!".

class HeavyData {
private:
    int* data;
    size_t size;

public:
    // 1. Regular Constructor
    HeavyData(size_t s) : size(s) {
        std::cout << "[Constructor] Allocating " << size << " ints." << std::endl;
        data = new int[size];
    }

    // 2. Destructor
    ~HeavyData() {
        if (data != nullptr) {
            std::cout << "[Destructor] Freeing memory." << std::endl;
            delete[] data;
        } else {
            std::cout << "[Destructor] Nothing to free (was moved)." << std::endl;
        }
    }

    // 3. Copy Constructor (Deep Copy - SLOW)
    // Takes an lvalue reference (const Type&)
    HeavyData(const HeavyData& other) : size(other.size) {
        std::cout << "[Copy Constructor] DEEP COPYING data. This is slow!" << std::endl;
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // 4. Move Constructor (Resource Stealing - FAST)
    // Takes an rvalue reference (Type&&)
    HeavyData(HeavyData&& other) noexcept : size(other.size) {
        std::cout << "[Move Constructor] STEALING data. This is fast!" << std::endl;
        
        // Steal the pointer
        data = other.data; 
        
        // Neutralize the source so its destructor doesn't free the memory we just stole!
        other.data = nullptr; 
        other.size = 0;
    }
};

int main() {
    std::cout << "--- Lesson 01: Move Semantics ---" << std::endl;

    std::cout << "\n1. Creating obj1..." << std::endl;
    HeavyData obj1(1000);

    std::cout << "\n2. Creating obj2 via COPY... (obj1 must remain intact)" << std::endl;
    HeavyData obj2(obj1); // Calls Copy Constructor

    std::cout << "\n3. Creating obj3 via MOVE... (we don't need obj1 anymore)" << std::endl;
    // std::move does NOT move anything itself. It's just a cast that tells the compiler:
    // "Treat obj1 as a temporary (rvalue) so its resources can be stolen".
    HeavyData obj3(std::move(obj1)); // Calls Move Constructor

    std::cout << "\n--- Exiting scope ---" << std::endl;
    return 0;
}
