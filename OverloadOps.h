//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_OVERLOADOPS_H
#define INC_20S_3353_PA01_OVERLOADOPS_H


class OverloadOps {
    void* operator new(size_t val);
    void* operator new[](size_t val);
    void operator delete(void* ptr, size_t) noexcept;
    void operator delete[](void* ptr,  size_t) noexcept;
};


#endif //INC_20S_3353_PA01_OVERLOADOPS_H
