#include <iostream>
#include "Point.h"
#include "SpecialPoint.h"
#include "SingletonAllocator.h"
using std::cout;
using std::cin;
using std::endl;

void* operator new(size_t val) {
    void* a = SingletonAllocator::getAllocator()->allocate(val);
    cout << a << endl;
    return a;
}

void* operator new(size_t val, int x) {
    void* a = SingletonAllocator::getAllocator()->allocateWithVal(val, x);
    cout << a << endl;
    return a;
}

void* operator new[](size_t val){
    void* a = SingletonAllocator::getAllocator()->allocateArray(val);
    cout << a << endl;
    return a;
}

void operator delete(void* ptr) noexcept {
    SingletonAllocator::getAllocator()->deallocate(ptr);
}
void operator delete[](void* ptr) noexcept {
    SingletonAllocator::getAllocator()->deallocate(ptr);
}

int main() {
    cout << "Global new." << endl;
    int* ptr01 = new int;
    delete ptr01;

//    cout << endl << "Global new[]" << endl;
//    int* ptrArray = new int[5];
//    delete ptrArray;

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

    return 0;
}
