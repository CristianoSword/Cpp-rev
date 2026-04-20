#include <iostream>
#include <string>

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
    void eat() {
        std::cout << "This animal is eating..." << std::endl;
    }

    void sleep() {
        std::cout << "Zzzzz..." << std::endl;
    }
};

// Derived Class (Child)
// Syntax: class Child : public Parent
class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(std::string dogBreed) : breed(dogBreed) {
        species = "Canine"; // Inherited protected member
    }

    void bark() {
        std::cout << "Woof! Woof! I am a " << breed << "." << std::endl;
    }

    void showSpecies() {
        std::cout << "Species: " << species << std::endl;
    }
};

// Another Derived Class
class Cat : public Animal {
public:
    void meow() {
        std::cout << "Meow! Feed me, human." << std::endl;
    }
};

int main() {
    std::cout << "--- Lesson 04: Inheritance ---" << std::endl;

    std::cout << "\n--- Testing Dog ---" << std::endl;
    Dog myDog("Golden Retriever");
    myDog.eat();   // Inherited from Animal
    myDog.sleep(); // Inherited from Animal
    myDog.bark();  // Unique to Dog
    myDog.showSpecies();

    std::cout << "\n--- Testing Cat ---" << std::endl;
    Cat myCat;
    myCat.eat();   // Inherited from Animal
    myCat.meow();  // Unique to Cat
    // myCat.bark(); // ERROR: Cat doesn't have bark()

    return 0;
}
