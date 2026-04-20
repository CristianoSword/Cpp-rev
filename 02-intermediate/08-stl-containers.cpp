#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

// Lesson 08: STL (Standard Template Library) - Containers
// 
// The STL provides ready-to-use, highly optimized data structures (Containers).
// Instead of writing arrays and linked lists from scratch, we use STL to save time.
// 
// Most common containers:
// 1. std::vector : Dynamic array that grows automatically. Best for general use.
// 2. std::map    : Key-value pairs (like dictionaries). Keys are unique and sorted.
// 3. std::set    : Collection of unique elements, automatically sorted.

int main() {
    std::cout << "--- Lesson 08: STL Containers (vector, map, set) ---" << std::endl;

    // ==========================================
    // 1. std::vector
    // ==========================================
    std::cout << "\n[1. std::vector - Dynamic Array]" << std::endl;
    std::vector<int> numbers;
    
    // Inserting elements
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    std::cout << "Vector size: " << numbers.size() << std::endl;
    
    // Iterating with modern range-based for loop
    std::cout << "Elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Accessing elements
    std::cout << "First element: " << numbers[0] << std::endl;
    // .at() is safer because it throws an exception if out of bounds
    std::cout << "Second element (safer): " << numbers.at(1) << std::endl;


    // ==========================================
    // 2. std::map
    // ==========================================
    std::cout << "\n[2. std::map - Key-Value Pairs]" << std::endl;
    // Map of <Name, Age>
    std::map<std::string, int> ages;

    // Inserting elements
    ages["Arthur"] = 25;
    ages["Zoe"] = 19;
    ages["Bob"] = 30;

    // Note that the iteration automatically sorts by the KEY alphabetically!
    for (const auto& pair : ages) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }

    // Checking if a key exists using .find()
    if (ages.find("Arthur") != ages.end()) {
        std::cout << "Arthur is in the map!" << std::endl;
    }


    // ==========================================
    // 3. std::set
    // ==========================================
    std::cout << "\n[3. std::set - Unique elements]" << std::endl;
    std::set<std::string> inventory;

    // Inserting elements
    inventory.insert("Sword");
    inventory.insert("Shield");
    inventory.insert("Potion");
    
    // Trying to insert a duplicate (it will be ignored silently)
    inventory.insert("Sword"); 

    // Note that elements are automatically sorted alphabetically
    std::cout << "Inventory contains " << inventory.size() << " unique items:" << std::endl;
    for (const std::string& item : inventory) {
        std::cout << "- " << item << std::endl;
    }

    // Removing an element
    inventory.erase("Shield");
    std::cout << "After removing Shield, size is: " << inventory.size() << std::endl;

    return 0;
}
