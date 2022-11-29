#include <stdlib.h>
#include <stdio.h>


int isReg(char *reg);
int isLabel(char *label);
int isImm_5(char *imm);
int isImm_16(char *imm);
int isoperator(const char *operator);
void checkproto(void);
