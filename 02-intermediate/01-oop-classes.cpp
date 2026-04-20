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
public: // Access modifier (public: accessible from outside the class)
    // Attributes (Data/State)
    std::string brand;
    std::string model;
    int year;
    bool isRunning;

    // Methods (Behavior/Actions)
    void start() {
        if (!isRunning) {
            isRunning = true;
            std::cout << "The " << brand << " " << model << " (" << year << ") started! Vroom vroom!" << std::endl;
        } else {
            std::cout << "The car is already running." << std::endl;
        }
    }

    void stop() {
        if (isRunning) {
            isRunning = false;
            std::cout << "The " << brand << " " << model << " stopped." << std::endl;
        } else {
            std::cout << "The car is already stopped." << std::endl;
        }
    }

    void honk() {
        std::cout << "Beep beep!" << std::endl;
    }
}; // IMPORTANT: The semicolon at the end of the class definition is mandatory in C++.


int main() {
    std::cout << "--- Lesson 01: Classes and Objects ---" << std::endl;

    // 2. Instantiating Objects (The "Instance")
    // We create two different objects based on the same Car "blueprint".
    
    Car myCar;
    // Accessing the attributes of the myCar object using the dot (.) operator
    myCar.brand = "Toyota";
    myCar.model = "Corolla";
    myCar.year = 2022;
    myCar.isRunning = false;

    Car friendCar;
    friendCar.brand = "Honda";
    friendCar.model = "Civic";
    friendCar.year = 2020;
    friendCar.isRunning = false;

    // 3. Calling Methods of the objects
    std::cout << "\nTesting MY CAR:" << std::endl;
    myCar.start();
    myCar.honk();
    myCar.stop();

    std::cout << "\nTesting FRIEND'S CAR:" << std::endl;
    friendCar.start();

    return 0;
}
