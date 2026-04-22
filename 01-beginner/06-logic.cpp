#include <iostream>

/**
 * C++ REVISION #6: Selection (if/else)
 * Controlling the flow of the program with conditions.
 */

int main() {
    int score;
    std::cout << "Enter your score (0-100): ";
    std::cin >> score;

    if (score >= 90) {
        std::cout << "Grade: A" << '\n';
    }
    else if (score >= 70) {
        std::cout << "Grade: B" << '\n';
    }
    else if (score >= 50) {
        std::cout << "Grade: C" << '\n';
    }
    else {
        std::cout << "Grade: F" << '\n';
    }

    // Logical AND (&&), OR (||), NOT (!)
    if (score >= 50 && score <= 100) {
        std::cout << "You passed!" << '\n';
    }

    return 0;
}
