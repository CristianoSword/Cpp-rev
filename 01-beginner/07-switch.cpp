#include <iostream>

/**
 * C++ REVISION #7: Switch Statement
 * Efficient multi-way selection based on a single variable.
 */

int main() {
    int day;
    std::cout << "Enter day number (1-7): ";
    std::cin >> day;

    switch (day) {
        case 1:
            std::cout << "Monday" << '\n';
            break;
        case 2:
            std::cout << "Tuesday" << '\n';
            break;
        case 3:
            std::cout << "Wednesday" << '\n';
            break;
        case 4:
            std::cout << "Thursday" << '\n';
            break;
        case 5:
            std::cout << "Friday" << '\n';
            break;
        case 6:
        case 7:
            std::cout << "Weekend" << '\n';
            break;
        default:
            std::cout << "Invalid day" << '\n';
            break;
    }

    return 0;
}
