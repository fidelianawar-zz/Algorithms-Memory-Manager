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
    cout << "Creating your BestFit object!" << endl;
}

void* BestFit::allocateMemory(size_t val){

    //baby bookkeeper to keep track of memory within larger bookkeeper
    vector<pair <int, int>, myAllocator<std::pair<int, int>>> babyBook;
    pair<int,int> bestSize;

    unsigned int numBlocks = val/8;
    unsigned int offset;

    //looking for start of free memory
    for(unsigned int i = 0; i < freeMem.size(); i++){
        if(freeMem[i] == 0){
            offset = i;
            numBlocks = 1; //keep track of offset
            for(unsigned int y = i + 1; y < freeMem.size(); y++){
                if(freeMem[y] == 0){
                    //incremet number of blocks
                    numBlocks++;
                }
                else{
                    break;
                }
            }
            //push back the offset and number of blocks after offset
            babyBook.push_back((std::make_pair(offset, numBlocks)));
            continue;
        }
    }

    //trying to find closest block of memory allocated
    for(unsigned int i = 0; i < babyBook.size(); i++){
        if((unsigned(babyBook[i].second)) == numBlocks){
            offset = babyBook[i].first;
        }
        //if found block is larger than needed, find the best "smallest" size
        else if(unsigned(babyBook[i].second) > numBlocks){
            if(babyBook[i].second < bestSize.second){
                bestSize = babyBook[i];
            }
            else{
                continue;
            }
        }
    }

    //assign offset to push back
    offset = bestSize.first;
    bookKeeper.push_back(std::make_pair(offset,numBlocks));

    //returning address that will be deallocated later
    void* returnAddress = static_cast<char*>(mem) + offset;
    return returnAddress;
}

//all deallocateMemory algs are the same
void BestFit::deallocateMemory(void* pointer){
    cout << "inside BF deallocate";
    unsigned int offsetIndex;
    unsigned int blocks;

    //find the pointer address in bookKeeper
    for(unsigned int i = 0; i < bookKeeper.size(); i++){
        int tempOffset = 0;
        tempOffset = bookKeeper[i].first;
        if(static_cast<char*>(mem) + tempOffset*8 == pointer){
            offsetIndex = tempOffset;
            blocks = bookKeeper[i].second;
        }
    }

    //change bytes back to "free" (0 value)
    for(unsigned int i = offsetIndex; i < blocks; i ++){
        freeMem[i] = 0;
    }
}