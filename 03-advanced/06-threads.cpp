#include <iostream>
#include <thread> // Essential for std::thread
#include <chrono> // Essential for time delays

// Lesson 06 (Advanced): Concurrency with std::thread
// 
// Concurrency allows multiple tasks to run at the same time (in parallel).
// C++11 introduced a native threading library.
// 
// When you create a std::thread, it starts running immediately.
// VERY IMPORTANT:
// Before the thread variable goes out of scope, you MUST either:
// 1. .join() it (wait for it to finish)
// 2. .detach() it (let it run independently in the background)
// If you do neither, the program will crash (std::terminate is called)!

void downloadFile(std::string filename) {
    std::cout << "[Thread " << std::this_thread::get_id() << "] Starting download of: " << filename << std::endl;
    
    // Simulate a long operation (e.g., downloading) by putting the thread to sleep
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    std::cout << "[Thread " << std::this_thread::get_id() << "] Finished downloading: " << filename << std::endl;
}

int main() {
    std::cout << "--- Lesson 06: Concurrency with std::thread ---" << std::endl;
    std::cout << "[Main Thread " << std::this_thread::get_id() << "] Program started." << std::endl;

    // Creating three separate threads. They will start running immediately!
    std::thread t1(downloadFile, "GTA_6_Leak.mp4");
    std::thread t2(downloadFile, "Cat_Video.gif");
    std::thread t3(downloadFile, "Homework.pdf");

    std::cout << "[Main Thread] Threads dispatched. Main thread is doing other work..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[Main Thread] Main thread finished its independent work." << std::endl;

    // Waiting for all threads to finish before closing the main program
    std::cout << "[Main Thread] Waiting for background threads to finish binding (join)..." << std::endl;
    t1.join();
    t2.join();
    t3.join();

    std::cout << "[Main Thread] All threads completed. Program exiting cleanly." << std::endl;

    return 0;
}
