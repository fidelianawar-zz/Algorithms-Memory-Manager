//
// Created by fidelia Nawar on 1/30/20.
//

#include "FirstFit.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using namespace std;

FirstFit::FirstFit():Allocator(){
   cout << "Making First Fit Object" << endl;
}

void* FirstFit::allocateMemory(size_t val) {

    unsigned int offset;
    unsigned int numBlocks = val / 8;
    bool flag = false;

    cout << "inside FirstFit Allocate Memory. val is : " << val << endl;
    cout << "size of freeMem is: " << freeMem.size() << endl;

    for (unsigned int i = 0; i < freeMem.size(); i++) {
        //empty block
        if (freeMem[i] == 0) {
            //if numBlocks word size is greater than 1
            if (numBlocks > 1) {
                //iteratate through numBlocks
                for (unsigned int j = i; j < numBlocks; j++) {
                    if (freeMem[j] == 1) {
                        flag = true;
                        break;
                    }
                }
                if(flag == true){
                    flag = false;
                    continue;
                }
                else{
                    offset = i;
                    break;
                }
            }
        }
        else{
            continue;
        }
        offset = i;
        break;
    }

    bookKeeper.push_back(std::make_pair(offset, numBlocks));

    cout << bookKeeper.size() << endl;

    for(unsigned int i = 0; i < bookKeeper.size(); i++) {
        cout << "bookkeeper offset is: " << bookKeeper[i].first << " bookkeeper numBlocks is: " << bookKeeper[i].second << endl;
    }

    void* returnAddress = static_cast<char*>(mem) + offset*8;
    return returnAddress;

}

void FirstFit::deallocateMemory(void* pointer){
    cout << "inside FF deallocate";
    unsigned int offsetIndex;
    unsigned int blocks;

    for(unsigned int i = 0; i < bookKeeper.size(); i++){
        int tempOffset = 0;
        tempOffset = bookKeeper[i].first;
        if(static_cast<char*>(mem) + tempOffset*8 == pointer){
            offsetIndex = tempOffset;
            blocks = bookKeeper[i].second;
        }
    }
    for(unsigned int i = offsetIndex; i < blocks; i ++){
        freeMem[i] = 0;
    }
}