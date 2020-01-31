//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_FIRSTFIT_H
#define INC_20S_3353_PA01_FIRSTFIT_H

#include "Allocator.h"

class FirstFit: public Allocator{
    void* giveMemory(int size_t = 0);
};


#endif //INC_20S_3353_PA01_FIRSTFIT_H
