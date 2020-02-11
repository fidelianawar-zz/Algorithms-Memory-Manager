//
// Created by Fidelia Nawar on 2/3/20.
//

#ifndef INC_20S_3353_PA01_WORSTFIT_H
#define INC_20S_3353_PA01_WORSTFIT_H

#include "Allocator.h"

class WorstFit: public Allocator {
    void worstFit(int blockSize[], int m, int processSize[], int n);
    void* allocateMemory(void*, int, void*, void*){
        cout << std::endl << "INSIDE WORSTFIT.H allocateMemory" << std::endl;
    }
};


#endif //INC_20S_3353_PA01_WORSTFIT_H
