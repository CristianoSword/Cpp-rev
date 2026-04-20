#include <iostream>
#include <string>

// Lesson 10: Memory Management (new and delete)
// 
// In C++, you can allocate memory in two places:
// 1. Stack: Automatic memory. Variables are destroyed when they go out of scope. Fast.
// 2. Heap (Free Store): Dynamic memory. You control when it's allocated AND when it's freed.
// 
// NEVER FORGET: Every 'new' MUST have a corresponding 'delete'.
// If you lose the pointer to the memory but didn't delete it, you get a MEMORY LEAK.

class Monster {
public:
    std::string name;
    
    Monster(std::string n) : name(n) {
        std::cout << "Monster '" << name << "' created." << std::endl;
    }
    
    ~Monster() {
        std::cout << "Monster '" << name << "' destroyed." << std::endl;
    }
    
    void roar() {
        std::cout << name << " roars: ROAAAAAR!" << std::endl;
    }
};

void createInStack() {
    std::cout << "\n--- Stack Allocation ---" << std::endl;
    // Allocated on the stack. Destroyed automatically when function ends.
    Monster goblin("Stack Goblin"); 
    goblin.roar();
}

void createInHeap() {
    std::cout << "\n--- Heap Allocation ---" << std::endl;
    
    // Allocated on the heap using 'new'.
    // 'new' returns a POINTER to the allocated memory.
    Monster* dragon = new Monster("Heap Dragon");
    dragon->roar();
    
    // We MUST free the memory manually using 'delete'.
    // If we forgot this line, the Dragon would stay in memory forever (Memory Leak)!
    delete dragon; 
}

void createArrayInHeap() {
    std::cout << "\n--- Array Allocation on Heap ---" << std::endl;
    
    // Allocating an array of ints on the heap
    int size = 5;
    int* numbers = new int[size];
    
    for (int i = 0; i < size; i++) {
        numbers[i] = i * 10;
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    // To delete an array allocated with 'new[]', we MUST use 'delete[]'
    delete[] numbers;
    std::cout << "Array memory freed." << std::endl;
}


int main() {
    std::cout << "--- Lesson 10: Memory Management ---" << std::endl;

    createInStack();
    createInHeap();
    createArrayInHeap();

    std::cout << "\nEnd of Main!" << std::endl;

    return 0;
}
