//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_BESTFIT_H
#define INC_20S_3353_PA01_BESTFIT_H

#include "Allocator.h"

class BestFit: public Allocator {
public:

    BestFit();

    void bestFit(int blockSize[], int m, int processSize[], int n);
    void* allocateMemory(void*, int, void*, void*){
        cout  << std::endl << "INSIDE BESTFIT.H allocateMemory" << std::endl;
        void* a;
        return a;
    };
};


#endif //INC_20S_3353_PA01_BESTFIT_H
