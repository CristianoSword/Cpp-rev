#include <iostream>
#include <limits>

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

    // do-while: execute once, then check condition.
    // If the user types something that is not an integer, std::cin sets failbit
    // and the bad input stays in the buffer, causing an infinite loop.
    // We must clear the state and discard the rest of the line.
    int choice;
    do {
        std::cout << "\nEnter 0 to exit: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please enter an integer." << std::endl;
            choice = -1; // anything != 0 keeps the loop alive
        }
    } while (choice != 0);

    std::cout << "Exited successfully." << std::endl;

    return 0;
}
