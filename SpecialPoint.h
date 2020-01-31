//
// Created by Fidelia Nawar on 1/30/20.
//


#ifndef INC_20S_3353_PA01_SPECIALPOINT_H
#define INC_20S_3353_PA01_SPECIALPOINT_H

#include "Point.h"

enum Color {none, red, green, blue, purple};
class SpecialPoint : public Point {
protected:
    Color pointColor;

public:
    SpecialPoint (int x, int y, int z, Color p):Point(x, y, z), pointColor(p) {
        cout << "SpecialPoint Constructor" << endl;
    }


};

#endif //INC_20S_3353_PA01_SPECIALPOINT_H
