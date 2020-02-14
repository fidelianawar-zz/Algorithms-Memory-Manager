//
// Created by Fidelia Nawar on 2/13/20.
//

#ifndef INC_20S_3353_PA01_GLOBALTESTS_H
#define INC_20S_3353_PA01_GLOBALTESTS_H

#include <iostream>
#include "SingletonAllocator.h"
#include "Allocator.h"
#include "myAllocator.h"
#include "GlobalFlag.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::bitset;


void* operator new(size_t val) {

    int x = val % 8;

    if(x == 0){
        void* a = SingletonAllocator::getAllocator()->allocateMemory(val);
        cout << "Overloading new at start address: " << a << endl;
        return a;
    }
    else{
        val = val - (val%8)+8;
        void* a = SingletonAllocator::getAllocator()->allocateMemory(val);
        cout << "Overloading new at start address: " << a << endl;
        return a;
    }
}

void* operator new(size_t val, int x) {
    void* a = SingletonAllocator::getAllocator()->allocateWithVal(val, x);
    cout << a << endl;
    return a;
}

void* operator new[](size_t val){
    int x = val % 8;

    if(x == 0){
        void* a = SingletonAllocator::getAllocator()->allocateMemory(val);
        cout << "Overloading new[] at start address: " << a << endl;
        return a;
    }
    else{
        val = val - (val%8)+8;
        void* a = SingletonAllocator::getAllocator()->allocateMemory(val);
        cout << "Overloading new[] at start address: " << a << endl;
        return a;
    }
}

void operator delete(void* ptr) noexcept {
    SingletonAllocator::getAllocator()->deallocateMemory(ptr);
}

void operator delete[](void* ptr) noexcept {
    SingletonAllocator::getAllocator()->deallocateMemory(ptr);
}

void runSmallTest(){
    int* ptrArray = new int[32];
    delete[] ptrArray;

    char* foo = new char[1000];
    delete(foo);
}


#endif //INC_20S_3353_PA01_GLOBALTESTS_H
