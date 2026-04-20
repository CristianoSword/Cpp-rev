#include <iostream>
#include <vector>
#include <string>

// Lesson 09 (Advanced): Design Patterns in C++
// 
// Design patterns are typical solutions to common problems in software design.
// They are templates designed to give you a reliable architecture.
// We will look at two of the most famous ones: 
// 1. Singleton (Creational): Ensures a class has only one instance.
// 2. Observer (Behavioral): A subscription mechanism to notify multiple objects about events.

// ==========================================
// 1. Singleton Pattern
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
    std::vector<ISubscriber*> subscribers;

public:
    YouTubeChannel(std::string name) : channelName(name) {}

    void subscribe(ISubscriber* sub) {
        subscribers.push_back(sub);
    }

    void uploadVideo(std::string title) {
        std::cout << "\n[" << channelName << "] Uploaded new video: " << title << std::endl;
        std::cout << "Notifying " << subscribers.size() << " subscribers..." << std::endl;
        
        for (auto sub : subscribers) {
            sub->update(title); // Polymorphic call!
        }
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
    
    User alice("Alice");
    User bob("Bob");
    
    myChannel.subscribe(&alice);
    myChannel.subscribe(&bob);
    
    myChannel.uploadVideo("Advanced Templates Explained!");

    return 0;
}
