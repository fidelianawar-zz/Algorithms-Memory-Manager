//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_ALLOCATOR_H
#define INC_20S_3353_PA01_ALLOCATOR_H

#include "myAllocator.h"
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
using std::pair;
using std::list;

class Allocator {

protected:

    void * mem;
    size_t size = 256 * 1024 * 1024;

    bitset<256*1024*1024/8> freeMem;
    vector<std::pair<int,int>, myAllocator<pair<int,int>>> bookKeeper;

    std::string allocatorName;

public:
    Allocator() {
        mem = malloc(256*1024*1024);
        cout << "Allocating at address: " << mem << std::endl << std::endl;
    };

    virtual ~Allocator() {};

    //if you wanted to allocate directly with object
    virtual void* allocateWithVal(size_t val, int x){
        void *storage = mem;
        cout << "NEW W/ VAL. Allocating " << val << " bytes." << std::endl;
        if(storage != nullptr) {
            *static_cast<int*>(storage) = x;
        }
        cout << "size = " << val << ", address returned is = " << storage << std::endl;
        return storage;
    }

    virtual void* allocateMemory(size_t val) = 0;
    virtual void deallocateMemory(void* pointer) = 0;

};


#endif //INC_20S_3353_PA01_ALLOCATOR_H
