//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_FIRSTFIT_H
#define INC_20S_3353_PA01_FIRSTFIT_H

#include "Allocator.h"
#include <iostream>
#include <list>
#include <iterator>
#include <vector>

class FirstFit: public Allocator{
public:

    void * mem{};
    void* checkMemory(void*& startingAddrress,int sizeOfBlock,void*& nextAddressStart,void*& nextAddressEnd);

    FirstFit();

    void* allocateMemory(size_t val) {

        cout  << std::endl << "INSIDE FIRSTFIT.H allocateMemory" << std::endl << std::endl;
        void *a;
        return a;
    }


    void deallocate(void* pointer){
        if(pointer){
            pointer = nullptr;
            free(pointer);
        }
    }


//        void* startingAddress = aStart;
//        int pushSize = allocateSize % 8;
//        if(pushSize != 0){
//            allocateSize = (allocateSize / 8) + 1;
//        }
//
//        allocateSize = allocateSize / 8;

//        if(startingAddress == mem){
//            //Allocator::offsetSpace->push_back(0,allocateSize);
//        }
//
//        cout << "the start address is: " << startingAddress << std::endl;


    void firstFit(int blockSize[], int m, int processSize[], int n);


};


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




#endif //INC_20S_3353_PA01_FIRSTFIT_H
