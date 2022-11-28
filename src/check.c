#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "inst.h"
#include "check.h"


int
isReg(char *reg) {

    if(*reg =='$'){
        //printf("is a reg\n");
        for(int i=0; i<=31; i++){
            if(strcmp(*reg,regs[i].s))
                return 1;
            else
                return 0;

        }

    }else {
       return 0;
    }

    return 1;

}

int
isLabel(char *label){

    if(isalpha(*label) !=0){

    }
}













