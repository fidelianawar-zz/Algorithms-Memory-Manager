//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_ALLOCATOR_H
#define INC_20S_3353_PA01_ALLOCATOR_H

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <bitset>
#include <new>

using std::string;
using std::cout;
using std::vector;
using std::bitset;

class Allocator {



protected:

    void * mem;
    size_t size = 256 * 1024 * 1024;

    std::string allocatorName;

    bitset<256*1024*1024> memoryBitSetVector;

    vector<int, int>* offsetSpace;

//    struct storedValues{
//        void* memAddress;
//        size_t vectorSize;
//    };
//
//    struct freeBlock{
//        void* startAddress;
//        size_t size;
//        freeBlock* next;
//    };
//
//    freeBlock* freeList;
//    //std::vector <int, Allocator> storedVector;
//    std::vector<storedValues> storedVector;



public:

    Allocator() {

        mem = malloc(256*1024*1024/8);
        cout << "Inside Allocator constructor at address " << mem << std::endl;
    };

    virtual ~Allocator() {};
    //explicit Allocator(const std::string& n);


    //virtual void* allocate(size_t);
    virtual void* allocateWithVal(size_t val, int x){
        void *storage = mem;
        cout << "NEW W/ VAL. Allocating " << val << " bytes." << std::endl;
        if(storage != nullptr) {
            *static_cast<int*>(storage) = x;
        }
        cout << "size = " << val << ", address returned is = " << storage << std::endl;
        return storage;
    }
    //virtual void deallocate(void*) noexcept;
    //virtual void deallocateArray(void*) noexcept;

    virtual void* allocateMemory(size_t val) = 0;
    virtual void deallocate(void* pointer) = 0;

};

//Allocator::freeBlock* freeList;
//Allocator::storedValues storedVector;

#endif //INC_20S_3353_PA01_ALLOCATOR_H
