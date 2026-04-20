#include <iostream>
#include <string>

// Lesson 03: Encapsulation
// 
// Encapsulation is the concept of bundling data and methods that operate on that data
// within a single unit (class), AND restricting direct access to some of the object's components.
// 
// Why hide internal state? 
// 1. Data Integrity: Prevents outside code from setting invalid values (e.g., negative balance).
// 2. Abstraction: The outside world doesn't need to know HOW it works, just WHAT it does.

class BankAccount {
private: 
    // Private attributes: ONLY methods inside BankAccount can access/modify these directly.
    std::string ownerName;
    double balance;

public:
    // Public methods: The "interface" to interact with the private data.

    // Constructor
    BankAccount(std::string name, double initialBalance) {
        ownerName = name;
        // Basic validation during initialization
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            std::cout << "Warning: Initial balance cannot be negative. Set to 0." << std::endl;
        }
    }

    // Getters: To READ the private data
    std::string getOwnerName() {
        return ownerName;
    }

    double getBalance() {
        return balance;
    }

    // Setters / Business Logic Methods: To WRITE/MODIFY the private data safely
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Successfully deposited $" << amount << std::endl;
        } else {
            std::cout << "Deposit amount must be positive!" << std::endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Successfully withdrew $" << amount << std::endl;
            return true; // Success
        } else {
            std::cout << "Withdraw failed: Insufficient funds or invalid amount!" << std::endl;
            return false; // Failure
        }
    }
};

int main() {
    std::cout << "--- Lesson 03: Encapsulation ---" << std::endl;

    BankAccount myAccount("John Doe", 100.0);

    // This will cause a COMPILATION ERROR if uncommented because 'balance' is private!
    // myAccount.balance = -9999; 
    // myAccount.ownerName = "Hacker";

    // We MUST use the public interface
    std::cout << "Account Owner: " << myAccount.getOwnerName() << std::endl;
    std::cout << "Current Balance: $" << myAccount.getBalance() << std::endl;

    std::cout << "\nAttempting transactions..." << std::endl;
    // Authorized modification via methods
    myAccount.deposit(50.0);
    myAccount.withdraw(200.0); // Fails safely!
    myAccount.withdraw(30.0);

    std::cout << "\nFinal Balance: $" << myAccount.getBalance() << std::endl;

    return 0;
}
