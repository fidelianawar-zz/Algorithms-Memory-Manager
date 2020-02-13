//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_FIRSTFIT_H
#define INC_20S_3353_PA01_FIRSTFIT_H

#include "Allocator.h"
#include "myAllocator.h"
#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <string>
#include <bitset>

class FirstFit: public Allocator {
public:

    FirstFit();

    void *allocateMemory(size_t val);
    void deallocate(void *pointer);

};
    /*
        if ((val + OFFset) > freeMem.size()) {
            cout << "out of bounds";
        }

        int counter = 0;

        while (counter != val) {
            if (freeMem[track] == 0) {
                track++;
                counter++;
            }
            else {
                while (freeMem[track] == 1) {
                    OFFset++;
                }
                track = track + OFFset;
                counter = 0;
            }
        }

        for(int i = 0; i < val; i++){
            freeMem[track] = 1;
        }
        for(int i = 0; i < freeMem.size(); i++){
            cout << freeMem[i] << " ";
        }

        return ptr;
    }
        //tracker.size() = val;
        //startAddress =

//        int* x = new int[5];
//        void* startAddy = x; //return beg of mem block
//        void* endAddy = startAddy;

        //offsetSpace->push_back()


*/




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


//initial address of malloc

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
