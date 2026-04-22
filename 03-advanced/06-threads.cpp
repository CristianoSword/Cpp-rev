#include <iostream>
#include <thread> // Essential for std::thread
#include <chrono> // Essential for time delays

// Lesson 06 (Advanced): Concurrency with std::thread and std::jthread
// 
// Concurrency allows multiple tasks to run at the same time (in parallel).
// C++11 introduced a native threading library (std::thread).
// C++20 introduced std::jthread which automatically joins on destruction.
// 
// When you create a thread, it starts running immediately.
// With legacy std::thread, you MUST .join() or .detach() before destruction.
// With std::jthread (C++20), it automatically joins when it goes out of scope,
// preventing crashes (std::terminate) and reducing boilerplate.

void downloadFile(std::string filename) {
    std::cout << "[Thread " << std::this_thread::get_id() << "] Starting download of: " << filename << std::endl;
    
    // Simulate a long operation (e.g., downloading) by putting the thread to sleep
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    std::cout << "[Thread " << std::this_thread::get_id() << "] Finished downloading: " << filename << std::endl;
}

int main() {
    std::cout << "--- Lesson 06: Concurrency with std::jthread ---" << std::endl;
    std::cout << "[Main Thread " << std::this_thread::get_id() << "] Program started." << std::endl;

    // Creating three separate threads. They will start running immediately!
    std::jthread t1(downloadFile, "GTA_6_Leak.mp4");
    std::jthread t2(downloadFile, "Cat_Video.gif");
    std::jthread t3(downloadFile, "Homework.pdf");

    std::cout << "[Main Thread] Threads dispatched. Main thread is doing other work..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[Main Thread] Main thread finished its independent work." << std::endl;

    // Waiting for all threads to finish before closing the main program
    std::cout << "[Main Thread] Using std::jthread, so they will automatically join when main() ends!" << std::endl;

    std::cout << "[Main Thread] All threads completed. Program exiting cleanly." << std::endl;

    return 0;
}
