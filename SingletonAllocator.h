
#include <string>
#include "Allocator.h"

class SingletonAllocator {
private:

    static Allocator* allocator;
    SingletonAllocator() = default;

public:

    static Allocator* getAllocator() {
        if(allocator == nullptr)
            allocator = new Allocator();
        cout <<"I am in Allocator constructor";
        return allocator;

    }
};

Allocator* SingletonAllocator::allocator = nullptr;