//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_FIRSTFIT_H
#define INC_20S_3353_PA01_FIRSTFIT_H

#include "Allocator.h"
#include "myAllocator.h"
#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <string>
#include <bitset>


/*
 * FirstFit involves the partition allocating the first sufficient
 * free block of space from the top of Main Memory.
 */

class FirstFit: public Allocator {

public:
    FirstFit();
    void *allocateMemory(size_t val);
    void deallocateMemory(void *pointer);
};

#endif //INC_20S_3353_PA01_FIRSTFIT_H
