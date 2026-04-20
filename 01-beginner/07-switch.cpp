#include <iostream>

using namespace std;

/**
 * C++ REVISION #7: Switch Statement
 * Efficient multi-way selection based on a single variable.
 */

int main() {
    int day;
    cout << "Enter day number (1-7): ";
    cin >> day;

    switch (day) {
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
        case 7:
            cout << "Weekend" << endl;
            break;
        default:
            cout << "Invalid day" << endl;
            break;
    }

    return 0;
}
