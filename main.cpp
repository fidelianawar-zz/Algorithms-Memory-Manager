#include <iostream>
#include "Point.h"
#include "SpecialPoint.h"
using std::cout;
using std::cin;
using std::endl;

void* operator new(size_t val) {
    cout << "MY NEW OPERATOR.  Allocating " << val << " bytes." << endl;

    void *storage = malloc(val);
    if(NULL == storage) {
        throw "allocation fail : no free memory";
    }
    cout << "size = " << val << ", address returned is = " << storage << endl;
    return storage;
}

void* operator new[](size_t val){
    cout << "MY NEW[] OPERATOR.  Allocating " << val << " bytes." << endl;
    void *p;
    p =  malloc(val);
    if(!p)
    {
        throw "allocation fail : no free memory";
    }
    cout << "size = " << val << ", address returned is = " << p << endl;
    return p;
}

void* operator new(size_t val, int x) {
    cout << "MY NEW OPERATOR WITH VAL.  Allocating " << val << " bytes." << endl;

    void *storage = malloc(val);
    if(storage != nullptr) {
        *static_cast<int*>(storage) = x;
    }
    cout << "size = " << val << ", address returned is = " << storage << endl;
    return storage;
}


void operator delete(void* ptr) noexcept {
    cout << "MY DELETE OPERATOR. Deallocating..." << endl;
    if(ptr){
        free(ptr);
    }
}
void operator delete[](void* ptr) noexcept {
    cout << "MY DELETE[] OPERATOR. Deallocating..." << endl;
    if(ptr){
        free(ptr);
    }
}

int main() {
    cout << "Global new." << endl;
    int* ptr01 = new int;
    delete ptr01;

    cout << endl << "Global new[]" << endl;
    int* ptrArray = new int[5];
    delete ptrArray;

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
