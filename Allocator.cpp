//
// Created by Fidelia Nawar on 1/30/20.
//
#include <iostream>
#include "Allocator.h"
#include "BestFit.h"
#include "WorstFit.h"
#include "FirstFit.h"

using std::cout;
using std::endl;
using std::string;
using std::exception;

Allocator::Allocator(const std::string& n) {
    mem = malloc(256);
    allocatorName = n;
    std::cout << "Constructing Allocator Object: " << allocatorName << std::endl;
}

void* Allocator::allocate(size_t val) {
    cout << "MY NEW OPERATOR.  Allocating " << val << " bytes." << endl;

    //void *storage = malloc(256);
    void *storage = mem;
    if(NULL == storage) {
        throw "allocation fail : no free memory";
    }
    cout << "size = " << 256 << ", address returned is = " << storage << endl;
    return storage;
}

void* Allocator::allocateWithVal(size_t val, int x){
    void *storage = mem;
    cout << "MY NEW OPERATOR WITH VAL.  Allocating " << val << " bytes." << endl;

    //void *storage = malloc(val);
    if(storage != nullptr) {
        *static_cast<int*>(storage) = x;
    }
    cout << "size = " << val << ", address returned is = " << storage << endl;
    return storage;
}

void* Allocator::allocateArray(size_t val){
    cout << "MY NEW[] OPERATOR.  Allocating " << val << " bytes." << endl;
    void *p = mem;
    //p =  malloc(val);
    if(!p)
    {
        throw "allocation fail : no free memory";
    }
    cout << "size = " << val << ", address returned is = " << p << endl;
    return p;
}


void Allocator::deallocate(void* ptr) noexcept{
    cout << "MY DELETE OPERATOR. Deallocating..." << endl;
    if(ptr){
        free(ptr);
    }

}
void Allocator::deallocateArray(void* ptr) noexcept{
    cout << "MY DELETE[] OPERATOR. Deallocating..." << endl;
    if(ptr){
        free(ptr);
    }
}