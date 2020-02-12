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

    void* allocateMemory(size_t val){
        cout  << std::endl << "INSIDE BESTFIT.H allocateMemory" << std::endl;
        void* a;
        return a;
    }

    void deallocate(void* pointer){
        if(pointer){
            pointer = nullptr;
            free(pointer);
        }

    }
};


#endif //INC_20S_3353_PA01_BESTFIT_H
