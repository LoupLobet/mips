#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "inst.h"
#include "check.h"


int
isReg(char *reg) {

    if(reg[0] =='$'){
        for(int i=0; i<31; i++){
            if(strcmp(reg,regs[i].s) == 0){
                return 1;
            }
        }

    }
    return 0;
}

int
isLabel(char *label){

    int n = strlen(label);

    if (isdigit(label[0]) != 0){
    }else{
        if(label[n-1]==':'){
            return 1;
        }
    }
    return 0;
}

int
isoperator(const char *operator){
    //to uppercase operator

    if(isdigit(operator[0]) || strlen(operator) > 4){
    }else {
        for(int i=0; i<25; i++){
            if(strcmp(operator,oplst[i].name) == 0){
                return 1;
            }
        }
    }
 return 0;
}

int
isImm_5(char *imm){
    int n = atoi(imm);

    if(isdigit(*imm)!=0){
        if ((n & 31) == n){
            return 1;
        }
    }
    return 0;
}

int
isImm_16(char *imm){
    int n = atoi(imm);

    if(isdigit(n)!= 0){
        printf("is a digit\n");
        if ((n & 65535) == n){
            printf("yes\n");
            return 1;
        }
    }
    printf("aii\n");
    return 0;
}











