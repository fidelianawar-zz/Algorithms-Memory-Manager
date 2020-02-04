//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_ALLOCATOR_H
#define INC_20S_3353_PA01_ALLOCATOR_H

#include "Singleton.h"
using std::cout;
using std::endl;
using std::string;

class Allocator {

private:

    void * mem{};
    string allocatorName;


public:

    explicit Allocator(const std::string& n);

    virtual void* giveMemory(int size_t = 0) = 0;

    void* operator new(size_t val);
    void* operator new[](size_t val);
    void operator delete(void* ptr, size_t) noexcept;
    void operator delete[](void* ptr,  size_t) noexcept;


};


#endif //INC_20S_3353_PA01_ALLOCATOR_H
