#include <iostream>
#include "GlobalTests.h"
#include "GlobalFlag.h"
#include "Allocator.h"
#include "myAllocator.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::bitset;

char flag = 'F';

int main() {
    runSmallTest();
    runMediumTest();
    return 0 ;
}


















//    cout << endl << "Specialized new." << endl;
//    Point* p = new Point(2, 3, 4);
//    delete p;
//
//    cout << endl << "Specialized new array." << endl;
//    Point* pArr = new Point[5] {{1, 2, 3}, {2, 3, 4}};
//    delete[] pArr;
//
//    cout << endl;
//    cout << "Inherited SpecialPoint" << endl;
//    SpecialPoint* sp = new SpecialPoint(1, 2, 3, red);
//    delete sp;

//    return 0;

