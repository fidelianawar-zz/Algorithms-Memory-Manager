//
// Created by Fidelia Nawar on 1/30/20.
//

#include "BestFit.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


BestFit::BestFit():Allocator(){
    cout << "inside BestFit constructor";
}

void* BestFit::allocateMemory(size_t val){

    bitset<256*1024*1024/8> freeMem;
    vector<pair <int, int>, myAllocator<std::pair<int, int>>> babyBook;
    pair<int,int> bestSize;

    int numBlocks = val/8;
    int offset;

    for(int i = 0; i < freeMem.size(); i++){
        if(freeMem[i] == 0){
            offset = i;
            numBlocks = 1;
            for(int y = i + 1; y < freeMem.size(); y++){
                if(freeMem[y] == 0){
                    numBlocks++;
                }
                else{
                    break;
                }
            }
            babyBook.push_back((std::make_pair(offset, numBlocks)));
            continue;
        }
    }

    for(int i = 0; i < babyBook.size(); i++){
        if(babyBook[i].second == numBlocks){
            offset = babyBook[i].first;
        }
        else if(babyBook[i].second > numBlocks){
            if(babyBook[i].second < bestSize.second){
                bestSize = babyBook[i];
            }
            else{
                continue;
            }
        }
    }

    offset = bestSize.first;
    bookKeeper.push_back(std::make_pair(offset,numBlocks));

    void* returnAddress = static_cast<char*>(mem) + offset;
    return returnAddress;
}

void BestFit::deallocateMemory(void* pointer){
    cout << "inside BF deallocate";
    if(pointer){
        pointer = nullptr;
        free(pointer);
    }
}