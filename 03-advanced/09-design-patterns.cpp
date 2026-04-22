#include <iostream>
#include <vector>
#include <string>
#include <memory>

// Lesson 09 (Advanced): Design Patterns in C++
// 
// Design patterns are typical solutions to common problems in software design.
// They are templates designed to give you a reliable architecture.
// We will look at two of the most famous ones: 
// 1. Singleton (Creational): Ensures a class has only one instance.
// 2. Observer (Behavioral): A subscription mechanism to notify multiple objects about events.

// ==========================================
// 1. Singleton Pattern
// Note: In modern C++, Singleton is often considered an anti-pattern because
// it hides dependencies and makes unit testing difficult. Dependency Injection
// is generally preferred. However, it is still important to know.
// ==========================================
class DatabaseConnection {
private:
    // Private constructor so nobody can create an instance directly!
    DatabaseConnection() {
        std::cout << "[Singleton] Initializing the heavy Database Connection..." << std::endl;
    }

public:
    // Delete copy constructor and assignment operator to prevent cloning
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;

    // The ONLY way to get the instance
    static DatabaseConnection& getInstance() {
        // Static local variable is initialized ONCE and thread-safe in C++11+
        static DatabaseConnection instance; 
        return instance;
    }

    void query(const std::string& sql) {
        std::cout << "[Database] Executing: " << sql << std::endl;
    }
};


// ==========================================
// 2. Observer Pattern
// ==========================================

// The "Subscriber" interface
class ISubscriber {
public:
    virtual void update(const std::string& videoTitle) = 0;
    virtual ~ISubscriber() = default;
};

// Concrete Subscriber
class User : public ISubscriber {
private:
    std::string name;
public:
    User(std::string n) : name(n) {}
    void update(const std::string& videoTitle) override {
        std::cout << "Hey " << name << ", a new video was uploaded: " << videoTitle << "!" << std::endl;
    }
};

// The "Publisher" (Subject)
class YouTubeChannel {
private:
    std::string channelName;
    // Use weak_ptr to avoid cyclic references and dangling pointers
    std::vector<std::weak_ptr<ISubscriber>> subscribers;

public:
    YouTubeChannel(std::string name) : channelName(name) {}

    void subscribe(std::shared_ptr<ISubscriber> sub) {
        subscribers.push_back(sub);
    }

    void uploadVideo(std::string title) {
        std::cout << "\n[" << channelName << "] Uploaded new video: " << title << std::endl;
        
        // Clean up expired weak_ptrs while notifying active ones
        int activeCount = 0;
        for (auto it = subscribers.begin(); it != subscribers.end(); ) {
            if (auto spt = it->lock()) {
                spt->update(title); // Polymorphic call!
                activeCount++;
                ++it;
            } else {
                it = subscribers.erase(it); // Remove dead subscribers
            }
        }
        std::cout << "Notified " << activeCount << " active subscribers." << std::endl;
    }
};

int main() {
    std::cout << "--- Lesson 09: Design Patterns ---" << std::endl;

    // --- Singleton ---
    std::cout << "\n[1. Singleton Testing]" << std::endl;
    // DatabaseConnection db; // ERROR! Constructor is private.
    DatabaseConnection& db1 = DatabaseConnection::getInstance();
    db1.query("SELECT * FROM users");
    
    DatabaseConnection& db2 = DatabaseConnection::getInstance(); // Will NOT re-initialize
    db2.query("UPDATE stats SET level=2");

    std::cout << "Are db1 and db2 the exact same memory object? " 
              << (&db1 == &db2 ? "YES" : "NO") << std::endl;


    // --- Observer ---
    std::cout << "\n[2. Observer Testing]" << std::endl;
    YouTubeChannel myChannel("Cpp Masters");
    
    // Using shared_ptr instead of raw pointers for automatic memory management
    auto alice = std::make_shared<User>("Alice");
    
    {
        auto bob = std::make_shared<User>("Bob");
        myChannel.subscribe(alice);
        myChannel.subscribe(bob);
        
        std::cout << "-> Uploading video while Bob is active scope:" << std::endl;
        myChannel.uploadVideo("Advanced Templates Explained!");
    } // bob goes out of scope here and is automatically destroyed!

    std::cout << "\n-> Uploading video after Bob left (his weak_ptr expired):" << std::endl;
    myChannel.uploadVideo("Smart Pointers in Depth!");

    return 0;
}
