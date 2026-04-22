#include <iostream>
#include <string>
#include <utility>

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
    BankAccount(std::string name, double initialBalance)
        : ownerName(std::move(name)), balance(0.0) {
        // Basic validation during initialization
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            std::cout << "Warning: Initial balance cannot be negative. Set to 0." << '\n';
        }
    }

    // Getters: To READ the private data.
    // Return by const-reference to avoid copying the string, and mark the method
    // const so it can be called on const BankAccount instances.
    const std::string& getOwnerName() const {
        return ownerName;
    }

    double getBalance() const {
        return balance;
    }

    // Setters / Business Logic Methods: To WRITE/MODIFY the private data safely
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Successfully deposited $" << amount << '\n';
        } else {
            std::cout << "Deposit amount must be positive!" << '\n';
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Successfully withdrew $" << amount << '\n';
            return true; // Success
        } else {
            std::cout << "Withdraw failed: Insufficient funds or invalid amount!" << '\n';
            return false; // Failure
        }
    }
};

int main() {
    std::cout << "--- Lesson 03: Encapsulation ---" << '\n';

    BankAccount myAccount("John Doe", 100.0);

    // This will cause a COMPILATION ERROR if uncommented because 'balance' is private!
    // myAccount.balance = -9999;
    // myAccount.ownerName = "Hacker";

    // We MUST use the public interface
    std::cout << "Account Owner: " << myAccount.getOwnerName() << '\n';
    std::cout << "Current Balance: $" << myAccount.getBalance() << '\n';

    std::cout << "\nAttempting transactions..." << '\n';
    // Authorized modification via methods
    myAccount.deposit(50.0);
    myAccount.withdraw(200.0); // Fails safely!
    myAccount.withdraw(30.0);

    std::cout << "\nFinal Balance: $" << myAccount.getBalance() << '\n';

    return 0;
}
