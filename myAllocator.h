#ifndef MEMTEST_VECTEST_H
#define MEMTEST_VECTEST_H
#include <iostream>
#include <new>

template <class T>
class myAllocator {
public:
    typedef T value_type;

    T* allocate(std::size_t n) {
        return static_cast<T*>(std::malloc(n*sizeof(T)));
    }

    void deallocate(T* p, std::size_t)noexcept {
        std::free(p);
    }

};


#endif //MEMTEST_VECTEST_H