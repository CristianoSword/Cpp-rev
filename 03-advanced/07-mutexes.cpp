#include <iostream>
#include <thread>
#include <vector>
#include <mutex> // Essential for std::mutex

// Lesson 07 (Advanced): Concurrency: Mutexes and Race Conditions
// 
// When multiple threads try to read from AND write to the same shared memory
// at the exact same time, you get a RACE CONDITION. The result becomes unpredictable.
// 
// Solution: Mutex (Mutual Exclusion).
// A Mutex acts like a "lock" on a bathroom door. Only one thread can enter the 
// critical section at a time. The others must wait outside until it's unlocked.

class BankAccount {
private:
    int balance;
    std::mutex mtx; // The lock that protects 'balance'

public:
    BankAccount() : balance(0) {}

    // Without mutex: Threads will overwrite each other's changes!
    void depositUnsafe(int amount) {
        // Simulating some delay that makes race conditions more likely
        int current = balance;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        balance = current + amount; 
    }

    // With mutex: Safe and synchronized!
    void depositSafe(int amount) {
        // ALWAYS use lock_guard instead of mtx.lock() and mtx.unlock() manually.
        // It uses RAII to automatically unlock when the function ends (even if an exception happens!)
        std::lock_guard<std::mutex> lock(mtx);
        
        int current = balance;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        balance = current + amount; 
    } // lock is automatically destroyed and mutex is unlocked here.

    int getBalance() const {
        return balance;
    }
};

int main() {
    std::cout << "--- Lesson 07: Mutexes and Race Conditions ---" << std::endl;

    BankAccount account;

    // We will launch 100 threads, each depositing $10
    // The expected final balance should be exactly 1000
    int expectedBalance = 100 * 10;
    std::vector<std::thread> threads;

    std::cout << "\nStarting 100 concurrent threads..." << std::endl;
    for (int i = 0; i < 100; i++) {
        // Try changing 'depositSafe' to 'depositUnsafe' below, and see the balance break!
        threads.push_back(std::thread(&BankAccount::depositSafe, &account, 10));
    }

    // Wait for all to finish
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Expected Balance: $" << expectedBalance << std::endl;
    std::cout << "Actual Balance:   $" << account.getBalance() << std::endl;

    if (account.getBalance() == expectedBalance) {
        std::cout << "SUCCESS! The mutex protected the transactions perfectly." << std::endl;
    } else {
        std::cout << "FAILURE! A Race Condition occurred!" << std::endl;
    }

    return 0;
}
