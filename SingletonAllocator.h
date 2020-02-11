
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
                int x = 5;
                cout << "inside flag FirstFit" << endl;
                void* p = malloc(sizeof(FirstFit));
                Allocator * a = new (p) FirstFit();
                allocator = a;
                cout << "int x allocator assigned " << &x << endl;
                allocator->allocateMemory(&x, 2, &x+4, &x+8);
            }
            else if(flag == 'B'){
                cout << "I should not reach here";
                void* p = malloc(sizeof(BestFit));
                Allocator * a = new (p) BestFit();
                allocator = a;
            }
            else if(flag == 'W'){
                cout << "I should not reach here";
                void* p = malloc(sizeof(WorstFit));
                Allocator * a = new (p) WorstFit();
                allocator = a;
            }
        }
        return allocator;

    }
};

Allocator* SingletonAllocator::allocator = nullptr;