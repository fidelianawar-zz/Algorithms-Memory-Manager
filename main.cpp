#include <iostream>
#include "Point.h"
#include "SpecialPoint.h"
using std::cout;
using std::cin;
using std::endl;

void* operator new(size_t val) {
    cout << "Global new operator.  Allocating " << val << " bytes." << endl;
//    return malloc(val);
    void *storage = malloc(val);
    if(NULL == storage) {
        throw "allocation fail : no free memory";
    }
    cout << "size = " << val << ", address returned is = " << storage << endl;
    return storage;
}

void* operator new[](size_t val){
    cout << "Global new[] operator.  Allocating " << val << " bytes." << endl;
    void *p;
    p =  malloc(val);
    if(!p)
    {
        throw "allocation fail : no free memory";
    }
    return p;
}

void operator delete(void* ptr, size_t val) noexcept {
    cout << "Global delete operator. Deallocating..." << endl;
    if(ptr){
        free(ptr);
    }
}
void operator delete[](void* ptr, size_t val) noexcept {
    cout << "Global delete[] operator. Deallocating..." << endl;
    if(ptr){
        free(ptr);
    }
}

int main() {
    cout << "Global new." << endl;
    int* ptr01 = new int;
    delete ptr01;

    cout << endl << "Specialized new." << endl;
    Point* p = new Point(2, 3, 4);
    delete p;

    cout << endl << "Specialized new array." << endl;
    Point* pArr = new Point[5] {{1, 2, 3}, {2, 3, 4}};
    delete[] pArr;

    cout << endl;
    cout << "Inherited SpecialPoint" << endl;
    SpecialPoint* sp = new SpecialPoint(1, 2, 3, red);
    delete sp;

    return 0;
}
