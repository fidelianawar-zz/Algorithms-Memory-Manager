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

Allocator::Allocator() {
    mem = malloc(256*1024*1024);
    cout << "Allocating at address " << mem << std::endl;
};

Allocator::Allocator(const std::string& n) {
    mem = malloc(256);
    allocatorName = n;
    std::cout << "Constructing Allocator Object: " << allocatorName << std::endl;
}

Allocator::~Allocator(){
    free(mem);
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

void * Allocator::getAddress() {
    return mem;
}

void Allocator::wordBoundary() {
    //cout << getAddress() % 8 << endl;
}