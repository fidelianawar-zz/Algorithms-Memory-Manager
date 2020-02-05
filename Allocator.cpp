//
// Created by Fidelia Nawar on 1/30/20.
//
#include <iostream>
#include "Allocator.h"
#include "BestFit.h"
#include "WorstFit.h"
#include "FirstFit.h"

using std::cout;
using std::endl;
using std::string;
using std::exception;

Allocator::Allocator(){
    allocatorName = "Bob the Allocator";
    std::cout << "Constructing Allocator Object: " << allocatorName << std::endl;
}

Allocator::Allocator(const std::string& n) {
    allocatorName = n;
    std::cout << "Constructing Allocator Object: " << allocatorName << std::endl;
}