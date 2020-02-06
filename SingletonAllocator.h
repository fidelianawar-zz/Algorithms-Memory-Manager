
#include <string>
#include "Allocator.h"

class SingletonAllocator {
private:

    static Allocator* allocator;
    SingletonAllocator() = default;

public:

    static Allocator* getAllocator() {
        if(allocator == nullptr){

            void* p = malloc(sizeof(Allocator));
            Allocator * a = new (p) Allocator();
            allocator = a;
        }
        return allocator;

    }
};

Allocator* SingletonAllocator::allocator = nullptr;