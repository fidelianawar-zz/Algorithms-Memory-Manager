#include <iostream>
#include "SingletonAllocator.h"
#include "Allocator.h"
#include "myAllocator.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::bitset;

char flag = 'F';

void* operator new(size_t val) {

    int x = val % 8;

    if(x == 0){
        void* a = SingletonAllocator::getAllocator()->allocateMemory(val);
        cout << "here in my overloaded new operator ";
        cout << "start address is: " << a << endl;
        return a;
    }

    else{
        val = val - (val%8)+8;
        return SingletonAllocator::getAllocator()->allocateMemory(val);
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
        cout << "here in my overloaded new operator ";
        cout << "start address is: " << a << endl;
        return a;
    }
    else{
        val = val - (val%8)+8;
        void* a = SingletonAllocator::getAllocator()->allocateMemory(val);
        return a;
    }
}

void operator delete(void* ptr) noexcept {
    SingletonAllocator::getAllocator()->deallocate(ptr);
}
void operator delete[](void* ptr) noexcept {
    SingletonAllocator::getAllocator()->deallocate(ptr);
}

int main() {
//    int* ptr01 = new int;
//    delete ptr01;
//
//    cout << endl;
//
    int* ptrArray = new int[5];
    delete[] ptrArray;

    cout << endl << "end" << endl;

    //mergeEmpty()


    //create array to store block sizes
    int block_size[] = {300, 50, 200, 350, 70};

    //create array to store process sizes
    int process_size[] = {200, 47, 212, 426, 10};

    //variable total_blocks that contain total number of blocks
    int total_blocks = sizeof(block_size) / sizeof(block_size[0]);

    //variable total_process that contain total number of blocks
    int total_process = sizeof(process_size) / sizeof(process_size[0]);

    //calling the function First_fit
    //FirstFit(block_size, total_blocks, process_size, total_process);


    return 0 ;
}


















//    cout << endl << "Specialized new." << endl;
//    Point* p = new Point(2, 3, 4);
//    delete p;
//
//    cout << endl << "Specialized new array." << endl;
//    Point* pArr = new Point[5] {{1, 2, 3}, {2, 3, 4}};
//    delete[] pArr;
//
//    cout << endl;
//    cout << "Inherited SpecialPoint" << endl;
//    SpecialPoint* sp = new SpecialPoint(1, 2, 3, red);
//    delete sp;

//    return 0;

