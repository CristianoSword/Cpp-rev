#include <iostream>

// Lesson 06: Operator Overloading
// 
// C++ allows us to redefine the behavior of built-in operators (like +, -, ==, <<)
// for our custom classes. This makes math or logical operations intuitive.
// 
// Syntax: return_type operator[symbol](arguments)

class Vector2D {
private:
    float x;
    float y;

public:
    // Constructors
    Vector2D() : x(0), y(0) {}
    Vector2D(float posX, float posY) : x(posX), y(posY) {}

    // Overloading the '+' operator
    // Allows us to do: vector3 = vector1 + vector2
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(this->x + other.x, this->y + other.y);
    }

    // Overloading the '==' operator for comparison
    bool operator==(const Vector2D& other) const {
        return (this->x == other.x && this->y == other.y);
    }

    // Overloading the '<<' operator for easy printing with std::cout
    // Realize this is marked as a 'friend' function because '<<' involves
    // std::ostream on the left side, not our class itself.
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os; // We return the stream so we can chain: cout << v1 << v2;
    }
};

int main() {
    std::cout << "--- Lesson 06: Operator Overloading ---" << std::endl;

    Vector2D pos1(10.5f, 5.0f);
    Vector2D pos2(2.0f, -1.0f);

    // Using the overloaded '+' operator
    Vector2D result = pos1 + pos2;

    // Using the overloaded '<<' operator
    std::cout << "Position 1: " << pos1 << std::endl;
    std::cout << "Position 2: " << pos2 << std::endl;
    std::cout << "Result of P1 + P2: " << result << std::endl;

    // Using the overloaded '==' operator
    Vector2D pos3(10.5f, 5.0f);
    std::cout << "\nIs pos1 equal to pos2? " << (pos1 == pos2 ? "Yes" : "No") << std::endl;
    std::cout << "Is pos1 equal to pos3? " << (pos1 == pos3 ? "Yes" : "No") << std::endl;

    return 0;
}
