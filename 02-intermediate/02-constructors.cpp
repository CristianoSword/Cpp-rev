#include <iostream>
#include <string>
#include <utility>

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
private:
    std::string name;
    int health;
    int level;

public:
    // 1. Default Constructor (No parameters)
    // Prefer the member initializer list over assignments in the body:
    // it initializes members directly instead of default-constructing and reassigning.
    Character() : name("Unknown NPC"), health(100), level(1) {
        std::cout << "[Constructor] A new nameless character spawned in the world!" << '\n';
    }

    // 2. Parameterized Constructor
    // Allowed via "Method Overloading".
    Character(std::string charName, int charHealth, int charLevel)
        : name(std::move(charName)), health(charHealth), level(charLevel) {
        std::cout << "[Constructor] Character " << name << " entered the game!" << '\n';
    }

    // 3. Destructor
    // It takes no arguments and cannot be overloaded (only one per class).
    ~Character() {
        std::cout << "[Destructor] Character " << name << " was destroyed and left the memory." << '\n';
    }

    void showStats() const {
        std::cout << "-> Stats: " << name << " | HP: " << health << " | Lvl: " << level << '\n';
    }
};

int main() {
    std::cout << "--- Lesson 02: Constructors and Destructors ---" << '\n';

    // Scope block to demonstrate the Destructor in action
    {
        std::cout << "\n--- Entering local scope ---" << '\n';

        // This will call the Default Constructor
        Character guard;
        guard.showStats();

        // This will call the Parameterized Constructor
        Character hero("Arthur", 250, 10);
        hero.showStats();

        std::cout << "--- Leaving local scope ---" << '\n';
    } // Here, 'guard' and 'hero' go out of scope. Their destructors will be called automatically!

    std::cout << "\nBack in main! Local characters are dead." << '\n';

    return 0; // End of program
}
