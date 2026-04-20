#include <iostream>
#include <string>

// Lesson 02: Constructors and Destructors
// 
// In OOP, how does an object come to life? And how does it die?
// 
// - Constructor: A special method called AUTOMATICALLY when the object is instantiated.
//   It's used to initialize attributes and set up the object's initial state.
//   It has the EXACT same name as the class and NO return type.
// 
// - Destructor: A special method called AUTOMATICALLY when the object is destroyed
//   (e.g., when it goes out of scope). Used to clean up resources (memory, files).
//   It has the name of the class preceded by a tilde (~).

class Character {
public: // Public attributes for simplicity
    std::string name;
    int health;
    int level;

    // 1. Default Constructor (No parameters)
    // If you don't define ANY constructor, C++ provides a default one.
    Character() {
        name = "Unknown NPC";
        health = 100;
        level = 1;
        std::cout << "[Constructor] A new nameless character spawned in the world!" << std::endl;
    }

    // 2. Parameterized Constructor
    // Allowed via "Method Overloading".
    Character(std::string charName, int charHealth, int charLevel) {
        name = charName;
        health = charHealth;
        level = charLevel;
        std::cout << "[Constructor] Character " << name << " entered the game!" << std::endl;
    }

    // 3. Destructor
    // It takes no arguments and cannot be overloaded (only one per class).
    ~Character() {
        std::cout << "[Destructor] Character " << name << " was destroyed and left the memory." << std::endl;
    }

    void showStats() {
        std::cout << "-> Stats: " << name << " | HP: " << health << " | Lvl: " << level << std::endl;
    }
};

int main() {
    std::cout << "--- Lesson 02: Constructors and Destructors ---" << std::endl;

    // Scope block to demonstrate the Destructor in action
    {
        std::cout << "\n--- Entering local scope ---" << std::endl;
        
        // This will call the Default Constructor
        Character guard; 
        guard.showStats();

        // This will call the Parameterized Constructor
        Character hero("Arthur", 250, 10);
        hero.showStats();
        
        std::cout << "--- Leaving local scope ---" << std::endl;
    } // Here, 'guard' and 'hero' go out of scope. Their destructors will be called automatically!

    std::cout << "\nBack in main! Local characters are dead." << std::endl;

    return 0; // End of program
}
