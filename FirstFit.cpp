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
    cout << "inside FirstFit constructor" << endl;
}

//FirstFit::FirstFit():Allocator(){
//    //mem = malloc(256*1024*1024);
//    cout << "Inside FirstFit constructor at address " << mem << std::endl;
//}











//FirstFit::FirstFit(int block_size[], int total_blocks, int process_size[], int total_process) {
//    int allocation[total_process];
//    memset(allocation, -1, sizeof(allocation));
//    //this for loop wll pick eact process and allocate a first fit block to it
//    for (int i = 0; i < total_process; i++) {
//        for (int j = 0; j < total_blocks; j++) {
//            if (block_size[j] >= process_size[i]) {
//                allocation[i] = j;
//                block_size[j] -= process_size[i];
//                break;
//            }
//        }
//    }
//    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
//    for (int i = 0; i < total_process; i++) {
//        cout << " " << i+1 << "\t\t" << process_size[i] << "\t\t";
//        if (allocation[i] != -1)
//            cout << allocation[i] + 1;
//        else
//            cout << "Not Allocated";
//        cout << endl;
//    }
//}




// Function to allocate memory to
// blocks as per First fit algorithm
//void firstFit(int blockSize[], int m, int processSize[], int n){
//
//    int allocation[n];
//
//    // Initially no block is assigned to any process
//    memset(allocation, -1, sizeof(allocation));
//
//    // pick each process and find suitable blocks
//    // according to its size ad assign to it
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (blockSize[j] >= processSize[i])
//            {
//                // allocate block j to p[i] process
//                allocation[i] = j;
//
//                // Reduce available memory in this block.
//                blockSize[j] -= processSize[i];
//
//                break;
//            }
//        }
//    }
//
//    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
//    for (int i = 0; i < n; i++)
//    {
//        cout << " " << i+1 << "\t\t"
//             << processSize[i] << "\t\t";
//        if (allocation[i] != -1)
//            cout << allocation[i] + 1;
//        else
//            cout << "Not Allocated";
//        cout << endl;
//    }
//}