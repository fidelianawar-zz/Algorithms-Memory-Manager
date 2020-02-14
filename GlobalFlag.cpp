//
// Created by Fidelia Nawar on 2/13/20.
//

#include "GlobalFlag.h"

char flagAssignment(){
    if(flag == 'F'){
        return 'F';
    }
    else if(flag == 'B'){
        return 'B';
    }
    else if(flag == 'W'){
        return 'W';
    }
    return '\0';
}