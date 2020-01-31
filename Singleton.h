//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_SINGLETON_H
#define INC_20S_3353_PA01_SINGLETON_H

#include <iostream>
#include "Allocator.h"

class Singleton {

private:
    Allocator obj;
    static Allocator getAllocator();
    static Singleton *instance;
    int data;

    // Private constructor so that no objects can be created.
    Singleton() {
        data = 0;
    }

public:

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton & operator=(Singleton &&) = delete;

    static Singleton *getInstance() {
        if (!instance)
            instance = new Singleton;
        return instance;
    }

    int getData() {
        return this -> data;
    }

    void setData(int data) {
        this -> data = data;
    }
};

#endif //INC_20S_3353_PA01_SINGLETON_H
