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
    std::cout << "--- Lesson 08: STL Containers (vector, map, set) ---" << '\n';

    // ==========================================
    // 1. std::vector
    // ==========================================
    std::cout << "\n[1. std::vector - Dynamic Array]" << '\n';
    std::vector<int> numbers;

    // Inserting elements
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    std::cout << "Vector size: " << numbers.size() << '\n';

    // Iterating with modern range-based for loop
    std::cout << "Elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    // Accessing elements.
    // .at() performs bounds checking and throws std::out_of_range on error,
    // while [] skips the check for speed. Prefer .at() until you need the speed.
    std::cout << "First element: " << numbers.at(0) << '\n';
    std::cout << "Second element: " << numbers.at(1) << '\n';


    // ==========================================
    // 2. std::map
    // ==========================================
    std::cout << "\n[2. std::map - Key-Value Pairs]" << '\n';
    // Map of <Name, Age>
    std::map<std::string, int> ages;

    // Inserting elements
    ages["Arthur"] = 25;
    ages["Zoe"] = 19;
    ages["Bob"] = 30;

    // Note that the iteration automatically sorts by the KEY alphabetically.
    // C++17 structured bindings let us name each half of the pair directly.
    for (const auto& [name, age] : ages) {
        std::cout << name << " is " << age << " years old." << '\n';
    }

    // Checking if a key exists. contains() is C++20 and expresses the intent
    // more clearly than 'find(k) != end()'.
    if (ages.contains("Arthur")) {
        std::cout << "Arthur is in the map!" << '\n';
    }


    // ==========================================
    // 3. std::set
    // ==========================================
    std::cout << "\n[3. std::set - Unique elements]" << '\n';
    std::set<std::string> inventory;

    // Inserting elements
    inventory.insert("Sword");
    inventory.insert("Shield");
    inventory.insert("Potion");

    // Trying to insert a duplicate (it will be ignored silently)
    inventory.insert("Sword");

    // Note that elements are automatically sorted alphabetically
    std::cout << "Inventory contains " << inventory.size() << " unique items:" << '\n';
    for (const std::string& item : inventory) {
        std::cout << "- " << item << '\n';
    }

    // Removing an element
    inventory.erase("Shield");
    std::cout << "After removing Shield, size is: " << inventory.size() << '\n';

    return 0;
}
