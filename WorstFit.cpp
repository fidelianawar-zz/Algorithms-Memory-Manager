//
// Created by Fidelia Nawar on 2/3/20.
//

#include "WorstFit.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using namespace std;

WorstFit::WorstFit(){
    cout << "Creating your WorstFit object!" << endl;
}

void* WorstFit::allocateMemory(size_t val) {

    vector<pair <int, int>, myAllocator<std::pair<int, int>>> babyBook;
    pair<int,int> bestSize;

    int numBlocks = val/8;
    int offset;

    for(unsigned int i = 0; i < freeMem.size(); i++){
        if(freeMem[i] == 0){
            offset = i;
            numBlocks = 1;
            for(unsigned int y = i + 1; y < freeMem.size(); y++){
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

    for(unsigned int i = 0; i < babyBook.size(); i++){
        if(babyBook[i].second == numBlocks){
            offset = babyBook[i].first;
        }
        else if(babyBook[i].second < numBlocks){
            if(babyBook[i].second > bestSize.second){
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

void WorstFit::deallocateMemory(void* pointer){
    cout << "inside WF deallocate";
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
