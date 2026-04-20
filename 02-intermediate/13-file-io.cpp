#include <iostream>
#include <fstream> // Essential for File I/O
#include <string>
#include <vector>

// Lesson 13: File I/O (Input/Output)
// 
// You can read from and write to computer files using fstream.
// 
// 1. std::ofstream (Output File Stream): Used to write to a file.
// 2. std::ifstream (Input File Stream): Used to read from a file.
// 3. std::fstream: Can handle both reading and writing.

void writeToFile(const std::string& filename) {
    // Open a file for writing. If it doesn't exist, it will be created.
    // If it exists, it will be overwritten by default. 
    // (You can append using std::ios::app)
    std::ofstream outFile(filename);

    // Always check if the file opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    std::cout << "\nWriting to " << filename << "..." << std::endl;
    outFile << "--- C++ Save Data ---" << "\n";
    outFile << "PlayerName: Arthur" << "\n";
    outFile << "Level: 25" << "\n";
    outFile << "Gold: 1540" << "\n";

    // Good practice: close the file when done.
    // (Though the destructor of ofstream will do this automatically via RAII)
    outFile.close(); 
    std::cout << "Data saved successfully!" << std::endl;
}

void readFromFile(const std::string& filename) {
    // Open a file for reading
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for reading: " << filename << std::endl;
        return;
    }

    std::cout << "\nReading from " << filename << ":" << std::endl;
    
    std::string line;
    // Read the file line by line until the end
    while (std::getline(inFile, line)) {
        std::cout << "> " << line << std::endl;
    }

    inFile.close();
}


int main() {
    std::cout << "--- Lesson 13: File I/O ---" << std::endl;

    std::string filename = "savegame.txt";

    // 1. Writing data to the disk
    writeToFile(filename);

    // 2. Reading the data back from the disk
    readFromFile(filename);

    return 0;
}
