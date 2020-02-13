//
// Created by Fidelia Nawar on 1/30/20.
//

#include "FirstFit.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using namespace std;

FirstFit::FirstFit():Allocator(){
   cout << "making fit first object" << endl;
}

void* FirstFit::allocateMemory(size_t val) {

    //vector<pair<int,size_t>> bookList;
    bitset<256*1024*1024/8> freeMem;

    int offset;

    int numBlocks = val / 8;

    bool flag = false;

    cout << "inside FirstFit Allocate Memory. val is : " << val << endl;
    cout << "size of freeMem is: " << freeMem.size() << endl;

    for (int i = 0; i < freeMem.size(); i++) {
        //empty block
        if (freeMem[i] == 0) {
            //if numBlocks word size is greater than 1
            if (numBlocks > 1) {
                //iteratate through numBlocks
                for (int j = i; j < numBlocks; j++) {
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

}

void FirstFit::deallocate(void* pointer){
    //linear search through vecor to find pointer address and delete
    if(pointer){
        pointer = nullptr;
        free(pointer);
    }
}