//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_FIRSTFIT_H
#define INC_20S_3353_PA01_FIRSTFIT_H

#include "Allocator.h"
#include <iostream>
#include <list>
#include <iterator>

class FirstFit: public Allocator{
public:

    void* checkMemory(void*& startingAddrress,int sizeOfBlock,void*& nextAddressStart,void*& nextAddressEnd);


//    Vehicle<int> vehicle(int,double,string,vehicle_type);
//
//    myString;
//
//    myString * alloc_my_string(char *src)
//    {
//        myString * p = NULL;
//        int numChars = strlen(src) + 1;
//
//        p = static_cast<myString *>(malloc(numChars + sizeof(myString)));
//        if (p)
//        {
//            p->num_chars = numChars;
//            strcpy(p->string, src);
//        }
//        return p;
//    }
//
//        typedef struct
//        {
//
//            int num_chars;
//            char string[];
//        }

    //FirstFit(int*, int, int*, int);

    void* allocateMemory(void*, int, void*, void*) {};
    void firstFit(int blockSize[], int m, int processSize[], int n);
};


#endif //INC_20S_3353_PA01_FIRSTFIT_H
