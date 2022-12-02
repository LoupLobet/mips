#ifndef _BUILD_H_
#define _BUILD_H_

#include "inst.h"

void	 build_xor(Inst *, char [9]);
void	 build_sw(Inst *, char [9]);
void	 build_srl(Inst *, char [9]);
void	 build_slt(Inst *, char [9]);
void	 build_sll(Inst *, char [9]);
void	 build_rotr(Inst *, char [9]);
void	 build_or(Inst *, char [9]);
void	 build_nop(Inst *, char [9]);
void	 build_lw(Inst *, char [9]);
void	 build_lui(Inst *, char [9]);
void	 build_jar(Inst *, char [9]);
void	 build_jal(Inst *, char [9]);
void	 build_j(Inst *, char [9]);
void	 build_bne(Inst *, char [9]);
void	 build_blez(Inst *, char [9]);
void	 build_bgtz(Inst *, char [9]);
void	 build_beq(Inst *, char [9]);
void	 build_and(Inst *, char [9]);
void	 build_addi(Inst *, char [9]);
void	 build_add(Inst *, char [9]);
void	 build_sub(Inst *, char [9]);
void	 build_div(Inst *, char [9]);
void	 build_mfhi(Inst *, char [9]);
void	 build_mflo(Inst *, char [9]);
void	 build_mult(Inst *, char [9]);

#endif
