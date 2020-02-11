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

using std::cout;

class Allocator {

    size_t size = 256 * 1024 * 1024;
protected:
    struct storedValues{
        void* memAddress;
        size_t vectorSize;
    };

    struct freeBlock{
        void* startAddress;
        size_t size;
        freeBlock* next;
    };

    freeBlock* freeList;
    //std::vector <int, Allocator> storedVector;
    std::vector<storedValues> storedVector;

    void * mem{};
    std::string allocatorName;

public:



    Allocator();
    ~Allocator();
    explicit Allocator(const std::string& n);

    virtual void* allocateArray(size_t);
    virtual void* allocate(size_t);
    virtual void* allocateWithVal(size_t val, int x);
    virtual void deallocate(void*) noexcept;
    virtual void deallocateArray(void*) noexcept;

    virtual void* allocateMemory(void*, int, void*, void*) = 0;
    //virtual void free(void*) = 0;

};

//Allocator::freeBlock* freeList;
//Allocator::storedValues storedVector;

#endif //INC_20S_3353_PA01_ALLOCATOR_H
