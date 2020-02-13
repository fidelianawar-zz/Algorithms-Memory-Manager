//
// Created by Fidelia Nawar on 2/13/20.
//
#include "myAllocator.h"

template <class T>
T* myAllocator<T>::allocate(std::size_t n)  {
    return static_cast<T*>(std::malloc( n*sizeof(T)));
}

template <class T>
void myAllocator<T>::deallocate(T* p, std::size_t)noexcept  {
    std::free(p);
}