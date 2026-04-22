#include <iostream>
#include <memory>
#include <vector>

// Lesson 05: Polymorphism and Virtual Functions
//
// Polymorphism ("Many Forms") allows objects of different classes to be treated
// as objects of a common base class.
//
// Key concepts:
// 1. Virtual Functions: Declared in the base class (using 'virtual') to be
//    redefined (overridden) in derived classes.
// 2. Dynamic Binding: The specific function to call is determined at RUNTIME
//    based on the actual object type, not the pointer/reference type.
// 3. Abstract Class: A class with at least one "Pure Virtual Function" (= 0).
//    You cannot instantiate an abstract class.

// Base Class (Abstract)
class Shape {
public:
    // Pure virtual function
    virtual void draw() const = 0;

    // Virtual destructor is ESSENTIAL when using polymorphism!
    // It ensures that derived destructors are called when deleting via base pointer.
    virtual ~Shape() {
        std::cout << "[Destructor] Shape destroyed." << '\n';
    }
};

class Circle : public Shape {
public:
    // 'override' keyword (C++11) ensures you are actually overriding a virtual function
    void draw() const override {
        std::cout << "Drawing a Circle (O)" << '\n';
    }
    ~Circle() override {
        std::cout << "[Destructor] Circle destroyed." << '\n';
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Square [ ]" << '\n';
    }
    ~Square() override {
        std::cout << "[Destructor] Square destroyed." << '\n';
    }
};

int main() {
    std::cout << "--- Lesson 05: Polymorphism ---" << '\n';

    // 1. Polymorphism via smart pointers.
    // std::unique_ptr owns the object exclusively and releases it automatically
    // when it goes out of scope. No manual 'new'/'delete' is needed.
    std::unique_ptr<Shape> s1 = std::make_unique<Circle>();
    std::unique_ptr<Shape> s2 = std::make_unique<Square>();

    std::cout << "Calling draw() via Base Pointers:" << '\n';
    s1->draw(); // Calls Circle::draw()
    s2->draw(); // Calls Square::draw()

    // 2. Polymorphism via Collections.
    // A vector of unique_ptr<Shape> owns its elements: they're destroyed
    // automatically when the vector is destroyed.
    std::cout << "\nIterating through a vector of unique_ptr<Shape>:" << '\n';
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::move(s1));
    shapes.push_back(std::move(s2));
    shapes.push_back(std::make_unique<Circle>());

    for (const auto& s : shapes) {
        s->draw();
    }

    // 3. No manual cleanup: destructors are called automatically on scope exit.
    std::cout << "\nLeaving main; destructors will fire automatically..." << '\n';

    return 0;
}
