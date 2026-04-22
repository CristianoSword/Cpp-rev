#include <iostream>
#include <string>

// Lesson 01: OOP - Classes and Objects
//
// In the Object-Oriented Programming (OOP) paradigm, we don't just deal with scattered variables,
// we group data (attributes) and functions (methods) inside a "Class".
//
// The Class works as a blueprint, and the Object is the concrete instance in memory.

// 1. Defining the Class (The "Blueprint")
class Car {
private: // Attributes are private by default in well-designed classes.
    std::string brand;
    std::string model;
    int year{0};
    bool isRunning{false};

public:
    // Constructor: initialize all members via the initializer list.
    Car(std::string carBrand, std::string carModel, int carYear)
        : brand(std::move(carBrand)), model(std::move(carModel)), year(carYear) {}

    // Methods (Behavior/Actions)
    void start() {
        if (!isRunning) {
            isRunning = true;
            std::cout << "The " << brand << " " << model << " (" << year << ") started! Vroom vroom!" << '\n';
        } else {
            std::cout << "The car is already running." << '\n';
        }
    }

    void stop() {
        if (isRunning) {
            isRunning = false;
            std::cout << "The " << brand << " " << model << " stopped." << '\n';
        } else {
            std::cout << "The car is already stopped." << '\n';
        }
    }

    void honk() const {
        std::cout << "Beep beep!" << '\n';
    }
}; // IMPORTANT: The semicolon at the end of the class definition is mandatory in C++.


int main() {
    std::cout << "--- Lesson 01: Classes and Objects ---" << '\n';

    // 2. Instantiating Objects (The "Instance")
    // We create two different objects based on the same Car "blueprint".
    Car myCar("Toyota", "Corolla", 2022);
    Car friendCar("Honda", "Civic", 2020);

    // 3. Calling Methods of the objects
    std::cout << "\nTesting MY CAR:" << '\n';
    myCar.start();
    myCar.honk();
    myCar.stop();

    std::cout << "\nTesting FRIEND'S CAR:" << '\n';
    friendCar.start();

    return 0;
}
