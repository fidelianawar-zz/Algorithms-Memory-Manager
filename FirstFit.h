//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_FIRSTFIT_H
#define INC_20S_3353_PA01_FIRSTFIT_H

#include "Allocator.h"

class FirstFit: public Allocator{

    typedef struct
    {
        int num_chars;
        char string[];
    }

    myString;

    myString * alloc_my_string(char *src)
    {
        myString * p = NULL;
        int numChars = strlen(src) + 1;

        p = static_cast<myString *>(malloc(numChars + sizeof(myString)));
        if (p)
        {
            p->num_chars = numChars;
            strcpy(p->string, src);
        }
        return p;
    }

    void* allocateMemory(int);
    void firstFit(int blockSize[], int m, int processSize[], int n);
};


#endif //INC_20S_3353_PA01_FIRSTFIT_H
