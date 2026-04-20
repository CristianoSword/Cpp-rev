#include <iostream>
#include <string>
#include <memory> // Essential for smart pointers

// Lesson 11: Smart Pointers
// 
// Introduced in C++11, Smart Pointers are wrappers around raw pointers.
// They AUTOMATICALLY manage memory and call 'delete' when they go out of scope.
// Say goodbye to memory leaks!
// 
// 1. std::unique_ptr: Exclusive ownership. Only ONE pointer can own the memory.
// 2. std::shared_ptr: Shared ownership. Multiple pointers can own the memory. It uses 
//    a "reference count". Memory is freed when the count reaches 0.
// 3. std::weak_ptr: Observes a shared_ptr without increasing the reference count.

class Resource {
public:
    std::string data;
    
    Resource(std::string d) : data(d) {
        std::cout << "Resource [" << data << "] ACQUIRED." << std::endl;
    }
    
    ~Resource() {
        std::cout << "Resource [" << data << "] DESTROYED." << std::endl;
    }
    
    void doSomething() {
        std::cout << "Doing something with " << data << std::endl;
    }
};


int main() {
    std::cout << "--- Lesson 11: Smart Pointers ---" << std::endl;

    // ==========================================
    // 1. unique_ptr
    // ==========================================
    std::cout << "\n[1. std::unique_ptr]" << std::endl;
    {
        // Preferred way to create a unique_ptr (make_unique is safer and faster)
        std::unique_ptr<Resource> uniqRes = std::make_unique<Resource>("UniqueData");
        uniqRes->doSomething();
        
        // std::unique_ptr<Resource> p2 = uniqRes; // ERROR! Cannot copy a unique_ptr.
        // std::unique_ptr<Resource> p3 = std::move(uniqRes); // Allowed! Ownership is transferred.
        
    } // 'uniqRes' goes out of scope here. The Resource is destroyed automatically!


    // ==========================================
    // 2. shared_ptr
    // ==========================================
    std::cout << "\n[2. std::shared_ptr]" << std::endl;
    {
        std::shared_ptr<Resource> shared1 = std::make_shared<Resource>("SharedData");
        std::cout << "Reference count after shared1: " << shared1.use_count() << std::endl;
        
        {
            // allowed! Multiple shared_ptrs can point to the same memory
            std::shared_ptr<Resource> shared2 = shared1; 
            std::cout << "Reference count after shared2: " << shared1.use_count() << std::endl;
            shared2->doSomething();
        } // shared2 goes out of scope. Ref count drops to 1, but object is NOT destroyed.
        
        std::cout << "Reference count after shared2 died: " << shared1.use_count() << std::endl;
        
    } // shared1 goes out of scope. Ref count drops to 0. Object IS DESTROYED automatically!


    std::cout << "\nEnd of Main!" << std::endl;
    return 0;
}
