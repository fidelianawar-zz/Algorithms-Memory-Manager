//
// Created by Fidelia Nawar on 2/3/20.
//

#ifndef INC_20S_3353_PA01_WORSTFIT_H
#define INC_20S_3353_PA01_WORSTFIT_H

#include "Allocator.h"

/*
 * Worst fit is the opposite of BestFit where, rather than trying to find the
 * closest sized block of memory to allocate, we simply try to find the largest
 * sized available block of memory within main memory.
 */

class WorstFit: public Allocator {
public:

    WorstFit();

    void* allocateMemory(size_t val);

    void deallocateMemory(void* pointer);

};

#endif //INC_20S_3353_PA01_WORSTFIT_H
