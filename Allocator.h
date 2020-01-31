//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_ALLOCATOR_H
#define INC_20S_3353_PA01_ALLOCATOR_H


class Allocator {
private:
    void * mem;
public:
    virtual void* giveMemory(int size_t = 0);
    static Allocator getAllocator();
};


#endif //INC_20S_3353_PA01_ALLOCATOR_H
