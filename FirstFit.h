//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_FIRSTFIT_H
#define INC_20S_3353_PA01_FIRSTFIT_H

#include "Allocator.h"

class FirstFit: public Allocator{
    void* allocateMemory(int);
    void firstFit(int blockSize[], int m, int processSize[], int n);
};


#endif //INC_20S_3353_PA01_FIRSTFIT_H
