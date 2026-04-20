#include <iostream>
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
        std::cout << "[Destructor] Shape destroyed." << std::endl;
    }
};

class Circle : public Shape {
public:
    // 'override' keyword (C++11) ensures you are actually overriding a virtual function
    void draw() const override {
        std::cout << "Drawing a Circle (O)" << std::endl;
    }
    ~Circle() {
        std::cout << "[Destructor] Circle destroyed." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Square [ ]" << std::endl;
    }
    ~Square() {
        std::cout << "[Destructor] Square destroyed." << std::endl;
    }
};

int main() {
    std::cout << "--- Lesson 05: Polymorphism ---" << std::endl;

    // 1. Polymorphism via Pointers
    // A pointer of type Shape* can point to any object inherited from Shape.
    Shape* s1 = new Circle();
    Shape* s2 = new Square();

    std::cout << "Calling draw() via Base Pointers:" << std::endl;
    s1->draw(); // Calls Circle::draw()
    s2->draw(); // Calls Square::draw()

    // 2. Polymorphism via Collections
    std::cout << "\nIterating through a vector of Shape*:" << std::endl;
    std::vector<Shape*> shapes;
    shapes.push_back(s1);
    shapes.push_back(s2);
    shapes.push_back(new Circle());

    for (const auto& s : shapes) {
        s->draw();
    }

    // 3. Memory Cleanup
    std::cout << "\nCleaning up memory..." << std::endl;
    // Because the destructor is virtual, 'delete s' will call the 
    // correct derived destructor (Circle/Square) first.
    for (auto s : shapes) {
        delete s;
    }

    return 0;
}
