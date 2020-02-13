//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_BESTFIT_H
#define INC_20S_3353_PA01_BESTFIT_H

#include "Allocator.h"
#include "myAllocator.h"

#include <vector>


class BestFit: public Allocator {

public:

    BestFit();
    void* allocateMemory(size_t val);
    void deallocateMemory(void* pointer);
};


#endif //INC_20S_3353_PA01_BESTFIT_H
