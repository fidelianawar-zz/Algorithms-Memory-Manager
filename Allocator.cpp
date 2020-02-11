//
// Created by Fidelia Nawar on 1/30/20.
//
#include <iostream>
#include "Allocator.h"

using std::cout;
using std::endl;
using std::string;
using std::exception;

Allocator::Allocator() {

    mem = malloc(256*1024*1024);

    freeList->size = size;
    freeList->next = nullptr;


    cout << "Inside Allocator constructor at address " << mem << std::endl;
};

Allocator::Allocator(const std::string& n) {
    mem = malloc(256);
    allocatorName = n;
    std::cout << "Constructing Allocator Object: " << allocatorName << std::endl;
}

Allocator::~Allocator(){
    free(mem);
    freeList->next = nullptr;
    freeList->size = 0;
    //storedVector.memAddress = 0;
    //storedVector->size = 0;
}

void* Allocator::allocate(size_t val) {
    cout << "NEW. Allocating " << val << " bytes." << endl;

    //void *storage = malloc(256);
    void *storage = mem;
    if(NULL == storage) {
        throw "allocation fail : no free memory";
    }
    cout << "size = " << val << ", address returned is = " << storage << endl;
    return storage;
}

void* Allocator::allocateWithVal(size_t val, int x){

    void *storage = mem;
    cout << "NEW W/ VAL. Allocating " << val << " bytes." << endl;
    if(storage != nullptr) {
        *static_cast<int*>(storage) = x;
    }
    cout << "size = " << val << ", address returned is = " << storage << endl;
    return storage;
}

void* Allocator::allocateArray(size_t val){
    cout << "NEW[]. Allocating " << val << " bytes." << endl;
    void *storage = mem;
    if(NULL == storage) {
        throw "allocation fail : no free memory";
    }
    cout << "size = " << val << ", address returned is = " << storage << endl;
    return storage;
}

void Allocator::deallocate(void* ptr) noexcept{

    cout << "DELETE. Deallocating..." << endl;
    if(ptr){
        free(ptr);
    }

}
void Allocator::deallocateArray(void* ptr) noexcept{
    cout << "DELETE[]. Deallocating..." << endl;
    if(ptr){
        free(ptr);
    }
}

void* Allocator::allocateMemory(void* startingAddress,int sizeOfBlock,void* nextAddressStart,void* nextAddressEnd){
    cout << "In ALLOCATOR.H allocateMemory" << endl;
    void* a;
    return a;
}