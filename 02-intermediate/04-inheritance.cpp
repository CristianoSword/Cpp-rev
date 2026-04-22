#include <iostream>
#include <string>
#include <utility>

// Lesson 04: Inheritance
//
// Inheritance allows us to create new classes (Derived/Child) based on
// existing classes (Base/Parent).
//
// Benefits:
// 1. Code Reusability: Child classes inherit attributes and methods from the Parent.
// 2. Specialization: Child classes can add new features or modify inherited ones.

// Base Class (Parent)
class Animal {
protected:
    // 'protected' means it's private to the outside world,
    // but accessible by child classes.
    std::string species;

public:
    Animal() = default;
    explicit Animal(std::string animalSpecies) : species(std::move(animalSpecies)) {}

    // Virtual destructor: required whenever a class is intended to be used
    // polymorphically (even if we are not deleting via base pointer here,
    // it's the safe default for base classes).
    virtual ~Animal() = default;

    void eat() const {
        std::cout << "This animal is eating..." << '\n';
    }

    void sleep() const {
        std::cout << "Zzzzz..." << '\n';
    }
};

// Derived Class (Child)
// Syntax: class Child : public Parent
class Dog : public Animal {
private:
    std::string breed;

public:
    // Explicitly initialize the Animal base class via its constructor.
    explicit Dog(std::string dogBreed)
        : Animal("Canine"), breed(std::move(dogBreed)) {}

    void bark() const {
        std::cout << "Woof! Woof! I am a " << breed << "." << '\n';
    }

    void showSpecies() const {
        std::cout << "Species: " << species << '\n';
    }
};

// Another Derived Class
class Cat : public Animal {
public:
    Cat() : Animal("Feline") {}

    void meow() const {
        std::cout << "Meow! Feed me, human." << '\n';
    }
};

int main() {
    std::cout << "--- Lesson 04: Inheritance ---" << '\n';

    std::cout << "\n--- Testing Dog ---" << '\n';
    Dog myDog("Golden Retriever");
    myDog.eat();   // Inherited from Animal
    myDog.sleep(); // Inherited from Animal
    myDog.bark();  // Unique to Dog
    myDog.showSpecies();

    std::cout << "\n--- Testing Cat ---" << '\n';
    Cat myCat;
    myCat.eat();   // Inherited from Animal
    myCat.meow();  // Unique to Cat
    // myCat.bark(); // ERROR: Cat doesn't have bark()

    return 0;
}
