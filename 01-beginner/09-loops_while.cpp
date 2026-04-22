#include <iostream>

/**
 * C++ REVISION #9: While and Do-While Loops
 * Repeating actions based on a boolean condition.
 */

int main() {
    int count = 5;

    // while: check condition first
    std::cout << "While loop countdown: ";
    while (count > 0) {
        std::cout << count << " ";
        count--;
    }
    std::cout << std::endl;

    // do-while: execute once, then check condition
    int choice;
    do {
        std::cout << "\nEnter 0 to exit: ";
        std::cin >> choice;
    } while (choice != 0);

    std::cout << "Exited successfully." << std::endl;

    return 0;
}
