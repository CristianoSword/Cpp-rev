#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

// Lesson 15: Final Intermediate Project - Simple CRUD System
// 
// Combining everything: Classes, Encapsulation, STL Vectors & Algorithms, 
// Exceptions, and Lambdas to create a basic CLI Student Management System.
// C (Create), R (Read), U (Update), D (Delete).

class Student {
private:
    int id;
    std::string name;
    double grade;

public:
    Student(int studentId, std::string studentName, double studentGrade) 
        : id(studentId), name(studentName), grade(studentGrade) {
        if (grade < 0.0 || grade > 10.0) {
            throw std::invalid_argument("Grade must be between 0.0 and 10.0");
        }
    }

    int getId() const { return id; }
    std::string getName() const { return name; }
    double getGrade() const { return grade; }

    void setGrade(double newGrade) {
        if (newGrade < 0.0 || newGrade > 10.0) {
            throw std::invalid_argument("Grade must be between 0.0 and 10.0");
        }
        grade = newGrade;
    }

    void display() const {
        std::cout << "[ID: " << id << "] " << name << " - Grade: " << grade << std::endl;
    }
};

class StudentManager {
private:
    std::vector<Student> db;

public:
    // Create
    void addStudent(int id, const std::string& name, double grade) {
        // Check if ID already exists using STL and Lambda
        auto it = std::find_if(db.begin(), db.end(), [id](const Student& s) {
            return s.getId() == id;
        });

        if (it != db.end()) {
            throw std::runtime_error("Student with this ID already exists!");
        }

        db.emplace_back(id, name, grade);
        std::cout << "Student added successfully." << std::endl;
    }

    // Read
    void listStudents() const {
        if (db.empty()) {
            std::cout << "Database is empty." << std::endl;
            return;
        }

        std::cout << "\n--- Student List ---" << std::endl;
        for (const auto& student : db) {
            student.display();
        }
    }

    // Update
    void updateGrade(int id, double newGrade) {
        auto it = std::find_if(db.begin(), db.end(), [id](const Student& s) {
            return s.getId() == id;
        });

        if (it == db.end()) {
            throw std::runtime_error("Student not found!");
        }

        it->setGrade(newGrade);
        std::cout << "Grade updated successfully." << std::endl;
    }

    // Delete
    void deleteStudent(int id) {
        auto it = std::remove_if(db.begin(), db.end(), [id](const Student& s) {
            return s.getId() == id;
        });

        if (it == db.end()) {
            throw std::runtime_error("Student not found!");
        }

        db.erase(it, db.end()); // Erase-Remove Idiom
        std::cout << "Student deleted successfully." << std::endl;
    }
};

int main() {
    std::cout << "--- Lesson 15: Student CRUD System ---" << std::endl;

    StudentManager manager;

    try {
        // C: Create
        manager.addStudent(101, "Arthur Pendragon", 9.5);
        manager.addStudent(102, "Zoe Smith", 8.0);
        
        // This will throw (invalid grade)
        // manager.addStudent(103, "Hacker", 11.0); 

        // R: Read
        manager.listStudents();

        // U: Update
        std::cout << "\nUpdating Zoe's grade..." << std::endl;
        manager.updateGrade(102, 9.0);
        manager.listStudents();

        // D: Delete
        std::cout << "\nDeleting Arthur..." << std::endl;
        manager.deleteStudent(101);
        manager.listStudents();
        
        // This will throw (Student not found)
        // manager.deleteStudent(999);

    } catch (const std::exception& e) {
        std::cout << "[ERROR]: " << e.what() << std::endl;
    }

    return 0;
}
