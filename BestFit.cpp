//
// Created by Fidelia Nawar on 1/30/20.
//

#include "BestFit.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using namespace std;

BestFit::BestFit():Allocator(){
    cout << "inside BestFit constructor";
}

//BestFit::BestFit():Allocator(){
//    //mem = malloc(256*1024*1024);
//   // cout << "Inside FirstFit constructor at address " << mem << std::endl;
//}

//adapated from Geeksforgeeks.com
//https://www.geeksforgeeks.org/program-best-fit-algorithm-memory-management/

// Function to allocate memory to blocks as per Best fit
// algorithm
void bestFit(int blockSize[], int m, int processSize[], int n)
{

    int allocation[n];

    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i=0; i<n; i++)
    {
        // Find the best fit block for current process
        int bestIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }

        // If we could find a block for current process
        if (bestIdx != -1)
        {
            // allocate block j to p[i] process
            allocation[i] = bestIdx;

            // Reduce available memory in this block.
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}