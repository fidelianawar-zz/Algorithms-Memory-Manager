
#include <string>
#include "Allocator.h"
#include "FirstFit.h"
#include "BestFit.h"
#include "WorstFit.h"
#include "GlobalFlag.h"
#include "GlobalTests.h"

using namespace std;
extern char flag;

class SingletonAllocator {
private:

    static Allocator* allocator;
    SingletonAllocator() = default;

public:

    static Allocator* getAllocator() {
        if(allocator == nullptr){
            if(flag == 'F'){
                void* p = malloc(sizeof(FirstFit));
                allocator = new (p) FirstFit();
            }
            else if(flag == 'B'){
                void* p = malloc(sizeof(BestFit));
                allocator = new (p) BestFit();
            }
            else if(flag == 'W'){
                void* p = malloc(sizeof(WorstFit));
                allocator = new (p) WorstFit();

            }
        }
        return allocator;
    }
};

Allocator* SingletonAllocator::allocator = nullptr;