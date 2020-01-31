#include <iostream>
#include "algoNew.h"
#include "Point.h"
#include "SpecialPoint.h"
using std::cout;
using std::cin;
using std::endl;


int main() {
    cout << "Global new." << endl;
    int* ptr01 = new int;
    delete ptr01;

    cout << endl << "Specialized new." << endl;
    Point* p = new Point(2, 3, 4);
    delete p;

    cout << endl << "Specialized new array." << endl;
    Point* pArr = new Point[5] {{1, 2, 3}, {2, 3, 4}};
    delete[] pArr;

    cout << endl;
    cout << "Inherited SpecialPoint" << endl;
    SpecialPoint* sp = new SpecialPoint(1, 2, 3, red);
    delete sp;

    return 0;
}
