//
// Created by Fidelia Nawar on 1/30/20.
//

#include <iostream>
#include "algoNew.h"

using std::cout;
using std::endl;

void* operator new(size_t val) {
    cout << "Global new operator.  Allocating " << val << " bytes." << endl;
    return malloc(val);
}

void* operator new[](size_t val){
    cout << "Global new[] operator.  Allocating " << val << " bytes." << endl;
    return malloc(val);
}

void operator delete(void* ptr) noexcept {
    cout << "Global delete operator. Deallocating..." << endl;
    free(ptr);
}
void operator delete[](void* ptr) noexcept {
    cout << "Global delete[] operator. Deallocating..." << endl;
    free(ptr);
}
