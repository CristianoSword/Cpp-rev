#include <iostream>
#include <cstdio> // C standard I/O
#include <cstring> // C strings

// Lesson 12 (Advanced): C Interop (Interoperability)
// 
// C++ is an evolution of C. As such, it can run almost any valid C code.
// This is crucial because many major OS APIs (Windows API, POSIX, Linux Kernel 
// syscalls, Socket APIs) are written purely in C.
// 
// The magic word is: extern "C"
// C++ compilers use "Name Mangling" to support function overloading (changing function
// names internally like 'print_int' or 'print_float'). C compilers do NOT. 
// If you want to link C code with C++, you must tell the C++ compiler to disable 
// Name Mangling for those specific functions.

// ==========================================
// 1. Simulating a C Library Header
// ==========================================
extern "C" {
    // These functions use C linkage. They will NOT be name-mangled.
    // In a real project, this block usually wraps an #include <some_c_lib.h>.
    
    int c_style_add(int a, int b) {
        return a + b;
    }

    void c_style_print(const char* message) {
        // We use printf from C, not std::cout from C++
        printf("[C Library Warning]: %s\n", message);
    }
}

// ==========================================
// 2. C++ Wrappers for C Functions (RAII)
// ==========================================
// C APIs often require manual initialization and destruction.
// Modern C++ wraps these dangerous C APIs inside safe C++ RAII classes.
class SafeCPrinter {
private:
    char* c_string;

public:
    SafeCPrinter(const std::string& cpp_string) {
        std::cout << "[C++] Converting std::string to C char* array..." << std::endl;
        
        // C-style dynamic allocation (malloc/strcpy instead of new/=)
        c_string = (char*)malloc(cpp_string.length() + 1);
        if (c_string) {
            strcpy(c_string, cpp_string.c_str());
        }
    }

    ~SafeCPrinter() {
        std::cout << "[C++] Freeing C char* array safely in Destructor." << std::endl;
        if (c_string) {
            free(c_string); // C-style deallocation
        }
    }

    void printViaC() {
        if (c_string) {
            c_style_print(c_string); // Calling the extern "C" function
        }
    }
};

int main() {
    std::cout << "--- Lesson 12: C Interop (extern \"C\") ---" << std::endl;

    std::cout << "\n[1. Calling Pure C Functions directly]" << std::endl;
    int result = c_style_add(10, 5);
    std::cout << "10 + 5 using C math: " << result << std::endl;
    
    // Calling C printf via our extern "C" function
    c_style_print("System crash imminent!"); 

    std::cout << "\n[2. Bridging C and C++ via Wrappers]" << std::endl;
    {
        SafeCPrinter safe("This string came from C++ but is printed via C!");
        safe.printViaC();
    } // SafeCPrinter goes out of scope here. The C-malloc'd memory is freed automatically via C++.

    return 0;
}
