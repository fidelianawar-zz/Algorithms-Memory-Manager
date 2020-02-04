//
// Created by Fidelia Nawar on 1/30/20.
//

#include <iostream>
#include "OverloadOps.h"

using std::cout;
using std::endl;

void* OverloadOps::operator new(size_t val) {
    cout << "Global new operator.  Allocating " << val << " bytes." << endl;
//    return malloc(val);
    void *storage = malloc(val);
    if(NULL == storage) {
        throw "allocation fail : no free memory";
    }
    cout << "size = " << val << ", address returned is = " << storage << endl;
    return storage;
}

void* OverloadOps::operator new[](size_t val){
    cout << "Global new[] operator.  Allocating " << val << " bytes." << endl;
    void *p;
    p =  malloc(val);
    if(!p)
    {
        throw "allocation fail : no free memory";
    }
    return p;
}

void OverloadOps::operator delete(void* ptr, size_t val) noexcept {
    cout << "Global delete operator. Deallocating..." << endl;
    if(ptr){
        free(ptr);
    }
}
void OverloadOps::operator delete[](void* ptr, size_t val) noexcept {
    cout << "Global delete[] operator. Deallocating..." << endl;
    if(ptr){
        free(ptr);
    }
}

