
#include <string>
#include "Allocator.h"

class Singleton {
private:

    static Allocator* allocator;
    Singleton() = default;

public:

    static Allocator* getAllocator() {
        if(allocator == nullptr)
            allocator = new Allocator("NotBob");

        return theManager;
    }
};

Allocator* Singleton::allocator = nullptr;