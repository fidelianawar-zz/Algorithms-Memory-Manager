//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_ALLOCATOR_H
#define INC_20S_3353_PA01_ALLOCATOR_H
#include <iostream>
#include <fstream>

class Allocator {

private:

    void * mem{};
    std::string allocatorName;

public:

    Allocator(){
        allocatorName = "Bob the Printer";
        std::cout << "Constructing Printer Object: " << allocatorName << std::endl;
    }

    explicit Allocator(const std::string& n) {
        allocatorName = n;
        std::cout << "Constructing Printer Object: " << allocatorName << std::endl;
    }
    virtual void* allocateMemory(int size_t = 0) = 0;



};


#endif //INC_20S_3353_PA01_ALLOCATOR_H
