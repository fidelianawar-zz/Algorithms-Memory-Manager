//
// Created by Fidelia Nawar on 1/30/20.
//

#ifndef INC_20S_3353_PA01_ALGONEW_H
#define INC_20S_3353_PA01_ALGONEW_H


class algoNew {
    void* operator new(size_t val);
    void* operator new[](size_t val);
    void operator delete(void* ptr) noexcept;
    void operator delete[](void* ptr) noexcept;
};


#endif //INC_20S_3353_PA01_ALGONEW_H
