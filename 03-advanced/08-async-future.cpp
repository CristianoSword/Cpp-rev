#include <iostream>
#include <thread>
#include <future> // Essential for std::async and std::future
#include <chrono>

// Lesson 08 (Advanced): Concurrency using std::async and std::future
// 
// While std::thread is great, retrieving a RETURN VALUE from a thread is clunky
// (you usually have to pass references and use locks).
// 
// std::async is a higher-level abstraction. It spawns a task (usually in a new thread)
// and returns a std::future object. 
// A std::future represents a value that will be available sometime in the "future".
// When you call future.get(), it BLOCKS the current thread until the value is ready.

// A simulation of an expensive calculation (e.g., querying a DB or complex math)
int calculateLifeAnswer() {
    std::cout << "[Background] Thinking hard for 3 seconds..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "[Background] Aha! Got it." << std::endl;
    return 42;
}

int main() {
    std::cout << "--- Lesson 08: std::async and std::future ---" << std::endl;

    // 1. Launching an asynchronous task.
    // std::launch::async ensures it runs in a separate thread.
    // std::launch::deferred would mean "lazy evaluation" (only runs when .get() is called).
    std::cout << "[Main] Requesting the answer. It will calculate in the background." << std::endl;
    std::future<int> answerFuture = std::async(std::launch::async, calculateLifeAnswer);

    // 2. Main thread can do other things while the background thread is busy!
    std::cout << "[Main] I am not blocked! Doing other GUI work..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "[Main] Still doing other work..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 3. Retrieving the result.
    // This will BLOCK the main thread if the background thread hasn't finished yet.
    std::cout << "[Main] Okay, now I really need the answer. Calling get() and blocking..." << std::endl;
    
    // get() can only be called ONCE per future. It extracts the value.
    int finalAnswer = answerFuture.get(); 

    std::cout << "[Main] The answer is: " << finalAnswer << std::endl;

    return 0;
}
