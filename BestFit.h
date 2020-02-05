//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_BESTFIT_H
#define INC_20S_3353_PA01_BESTFIT_H

#include "Allocator.h"

class BestFit: public Allocator {
    void bestFit(int blockSize[], int m, int processSize[], int n);
    void* allocateMemory(int);
};


#endif //INC_20S_3353_PA01_BESTFIT_H
