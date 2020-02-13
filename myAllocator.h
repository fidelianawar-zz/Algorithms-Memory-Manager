#ifndef MEMTEST_VECTEST_H
#define MEMTEST_VECTEST_H
#include <iostream>
#include <new>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

template <class T>
class myAllocator {
public:
    typedef T value_type;
    T* allocate(std::size_t n);
    void deallocate(T* p, std::size_t)noexcept;
};


#endif //MEMTEST_VECTEST_H