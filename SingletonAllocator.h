
#include <string>
#include "Allocator.h"
#include "FirstFit.h"
#include "BestFit.h"
#include "WorstFit.h"
#include "GlobalFlag.h"

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
                cout << "inside flag FirstFit" << endl;
                void* p = malloc(sizeof(FirstFit));
                Allocator * a = new (p) FirstFit();
                allocator = a;
            }
            else if(flag == 'B'){
                void* p = malloc(sizeof(BestFit));
                Allocator * a = new (p) BestFit();
                allocator = a;
            }
            else if(flag == 'W'){
                void* p = malloc(sizeof(WorstFit));
                Allocator * a = new (p) WorstFit();
                allocator = a;
            }
        }
        return allocator;

    }
};

Allocator* SingletonAllocator::allocator = nullptr;