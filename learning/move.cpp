#include <iostream>
#include <vector>
#include <utility>
#include <chrono>

class Mover {
public:
    int* data;

    // Constructor
    Mover() : data(new int(0)) {}
    
    // Copy Constructor (Deep Copy)
    Mover(const Mover& other) {
        data = new int(*other.data);
    }

    // Move Constructor (Shallow Copy + Transfer)
    Mover(Mover&& other) noexcept {
        data = other.data;
        other.data = nullptr;
    }

    // Destructor
    ~Mover() {
        delete data;
    }
};

int main() {
    const int numObjects = 1000000;
    
    // 1. Setup: Create the initial vector
    std::vector<Mover> original(numObjects);
    std::cout << "Testing with " << numObjects << " objects...\n\n";

    // --- TEST COPY ---
    auto startCopy = std::chrono::high_resolution_clock::now();
    
    std::vector<Mover> copyDest = original; // Triggers Copy Constructor 1 million times
    
    auto endCopy = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> copyTime = endCopy - startCopy;

    // --- TEST MOVE ---
    auto startMove = std::chrono::high_resolution_clock::now();
    
    std::vector<Mover> moveDest = std::move(original); // Just swaps internal pointers
    
    auto endMove = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> moveTime = endMove - startMove;

    // --- RESULTS ---
    std::cout << "------------------------------------------\n";
    std::cout << "COPY TIME: " << copyTime.count() << " ms\n";
    std::cout << "MOVE TIME: " << moveTime.count() << " ms\n";
    std::cout << "------------------------------------------\n";
    
    if (moveTime.count() > 0) {
        std::cout << "Move was " << (copyTime.count() / moveTime.count()) << "x faster!\n";
    }

    return 0;
}