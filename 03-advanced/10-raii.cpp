#include <iostream>
#include <string>
#include <stdexcept>

// Lesson 10 (Advanced): RAII (Resource Acquisition Is Initialization)
// 
// RAII is arguably the most important idiom in modern C++.
// What it means:
// 1. Resource Acquisition (opening a file, locking a mutex, allocating memory)
//    must happen in the CONSTRUCTOR of an object.
// 2. Resource Release (closing the file, unlocking, freeing memory)
//    must happen in the DESTRUCTOR.
// 
// Why?
// Because the C++ compiler GUARANTEES that the destructor of a local 
// stack object is called when the object goes out of scope, EVEN IF AN EXCEPTION IS THROWN.
// This prevents memory leaks and deadlocks automatically.

// ==========================================
// A custom RAII Wrapper for a simulated "File Handle"
// ==========================================
class SimulatedFile {
private:
    std::string filename;
    bool isOpen;

public:
    // Resource Acquisition -> Initialization
    SimulatedFile(const std::string& name) : filename(name) {
        std::cout << "[RAII] Opening file: " << filename << std::endl;
        isOpen = true;
    }

    // Resource Release -> Destruction
    ~SimulatedFile() {
        if (isOpen) {
            std::cout << "[RAII] Closing file: " << filename << std::endl;
            isOpen = false;
        }
    }

    void writeData(const std::string& data) {
        if (!isOpen) throw std::runtime_error("File is not open!");
        std::cout << "[File] Writing data: " << data << std::endl;
    }
};

void dangerousFunction() {
    // 1. The resource is acquired
    SimulatedFile myFile("config.ini");
    
    myFile.writeData("SettingX=10");

    // 2. BOOM! An unexpected error happens!
    std::cout << "\n[System] Oh no! A critical error occurred inside dangerousFunction!" << std::endl;
    throw std::runtime_error("Unexpected failure!");

    // This line will never run
    myFile.writeData("SettingY=20");

    // We never reached the end of the function. If we had to manually call myFile.close(),
    // we would have a resource leak right now.
}

int main() {
    std::cout << "--- Lesson 10: RAII In Depth ---" << std::endl;

    try {
        dangerousFunction();
    } 
    catch (const std::exception& e) {
        std::cout << "\n[Catch Block] Caught exception: " << e.what() << std::endl;
        std::cout << "[Catch Block] But notice how the file was cleanly closed right before we got here! That's RAII!" << std::endl;
    }

    return 0;
}
