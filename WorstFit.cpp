//
// Created by Fidelia Nawar on 2/3/20.
//

#include "WorstFit.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using namespace std;

WorstFit::WorstFit(){
    cout << std::endl << "INSIDE WORST FIT CONSTRUCTOR" << std::endl;
}

void* WorstFit::allocateMemory(size_t val) {
    cout  << std::endl << "INSIDE WORSTFIT.H allocateMemory" << std::endl;
    void* a;
    return a;
}

void WorstFit::deallocate(void* pointer){
    if(pointer){
        pointer = nullptr;
        free(pointer);
    }

}
