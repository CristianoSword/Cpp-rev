#include <iostream>

using namespace std;

/**
 * C++ REVISION #6: Selection (if/else)
 * Controlling the flow of the program with conditions.
 */

int main() {
    int score;
    cout << "Enter your score (0-100): ";
    cin >> score;

    if (score >= 90) {
        cout << "Grade: A" << endl;
    } 
    else if (score >= 70) {
        cout << "Grade: B" << endl;
    } 
    else if (score >= 50) {
        cout << "Grade: C" << endl;
    } 
    else {
        cout << "Grade: F" << endl;
    }

    // Logical AND (&&), OR (||), NOT (!)
    if (score >= 50 && score <= 100) {
        cout << "You passed!" << endl;
    }

    return 0;
}
