//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_POINT_H
#define INC_20S_3353_PA01_POINT_H

#include <cstddef>
#include <iostream>
#include "OverloadOps.h"

using std::cout;
using std::endl;
using std::cin;

class Point {
protected:
    unsigned int x, y, z;
public:
    Point (unsigned int xval = 0, unsigned int yval = 0, unsigned int zval = 0):
            x(xval), y(yval), z(zval) {
        cout << "Initializing Point Object with [" << x << ", "
             << y << ", " << z << "]." << endl;
    }

    ~Point () {
        cout << "Executing Point destructor" << endl;
    }

//    void* operator new(size_t numBytes) {
//        cout << "Allocating Point with new: " << numBytes << " bytes." << endl;
//        return malloc(numBytes);
//        //return ::new Point;
//
//    }

    void * operator new(size_t size)
    {
        // try to allocate size bytes
//        void* ptr = new char[size];
//        cout << "size = " << size << ", address returned is = " << ptr << endl;
//        return ptr;

        void *storage = malloc(size);
        if(NULL == storage) {
            throw "allocation fail : no free memory";
        }
        cout << "size = " << size << ", address returned is = " << storage << endl;
        return storage;
    }

    void operator delete(void* ptr) {
        cout << "De-allocating Point with delete." << endl;
        free(ptr);
    }

    void* operator new[](size_t numBytes) {
        cout << "Allocating Point Array with new[]: " << numBytes << " bytes." << endl;
        return malloc(numBytes);
    }

    void operator delete[] (void* ptr) {
        cout << "De-allocating Point array with delete." << endl;
        free(ptr);
    }

};

#endif //INC_20S_3353_PA01_POINT_H
