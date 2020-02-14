//
// Created by Fidelia Nawar on 2/13/20.
//

#ifndef INC_20S_3353_PA01_GLOBALTESTS_H
#define INC_20S_3353_PA01_GLOBALTESTS_H

#include <iostream>
#include <time.h>
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

    //checking to see if word boundary is matched
    int x = val % 8;

    if(x == 0){
        void* a = SingletonAllocator::getAllocator()->allocateMemory(val);
        cout << "Overloading new at start address: " << a << endl;
        return a;
    }
    else{
        //changing to allocate memory up to the boundary
        val = val - (val%8)+8;
        void* a = SingletonAllocator::getAllocator()->allocateMemory(val);
        cout << "Overloading new at start address: " << a << endl;
        return a;
    }
}

//overloaded new operator with a value
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
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "SMOL stress test" << endl;
    int* ptrArray = new int[32];
    delete[] ptrArray;

    char* arr = new char[1000];
    delete[] arr;

    int* large = new int(2305293);
    delete large;
    cout << "----------------------------------------------------------------------------------" << endl;
}

void runMediumTest(){
//    vector<int>* newVec = new vector<int>{10, 3, 5, 3562, 24590};
//    delete newVec;

    time_t t;
    time(&t);
    srand((unsigned int) t);


}


#endif //INC_20S_3353_PA01_GLOBALTESTS_H
