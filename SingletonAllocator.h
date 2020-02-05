
#include <string>
#include "Allocator.h"

class SingletonAllocator {
private:

    static Allocator* allocator;
    SingletonAllocator() = default;

public:

    static Allocator* getAllocator() {
        if(allocator == nullptr){
            allocator = new Allocator();
        }
        return allocator;

    }
};

Allocator* SingletonAllocator::allocator = nullptr;