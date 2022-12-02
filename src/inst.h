#ifndef _INST_H_
#define _INST_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int argv[4];
	int argc;
} Inst;

typedef struct {
	char *name;
	unsigned int pc;
	long offset;
} Label;

typedef struct {
	char *name;
	int opcode;
	void (*build)(Inst *, char [9]);
	int (*run)(Inst *);
	int proto[3];
} Op;

typedef struct {
	char *name;
	int val;
} Reg;

int	 formatraw(char *);
int	 strtoop(char *);
int	 strtoreg(char *);
void	 rmcomment(char *);
void	 rmspaces(char *);
Inst	*parseinst(char *);

enum {
	VOID,
	IMM5,
	IMM16,
	REG,
	TARG,
};

enum {
	ADD,
	ADDI,
	AND,
	BEQ,
	BGTZ,
	BLEZ,
	BNE,
	DIV,
	J,
	JAL,
	JR,
	LUI,
	LW,
	MFHI,
	MFLO,
	MULT,
	NOP,
	OR,
	ROTR,
	SLL,
	SLT,
	SRL,
	SUB,
	SW,
	XOR,
	OPNB,
};

enum {
	$0,
	$1,
	$2,
	$3,
	$4,
	$5,
	$6,
	$7,
	$8,
	$9,
	$10,
	$11,
	$12,
	$13,
	$14,
	$15,
	$16,
	$17,
	$18,
	$19,
	$20,
	$21,
	$22,
	$23,
	$24,
	$25,
	$26,
	$27,
	$28,
	$29,
	$30,
	$31,
	REGNB,
};

enum {
	$zero = $0,
	$at = $1,
	$v0 = $2,
	$v1 = $3,
	$a0 = $4,
	$a1 = $5,
	$a2 = $6,
	$a3 = $7,
	$t0 = $8,
	$t1 = $9,
	$t2 = $10,
	$t3 = $11,
	$t4 = $12,
	$t5 = $13,
	$t6 = $14,
	$t7 = $15,
	$s0 = $16,
	$s1 = $17,
	$s2 = $18,
	$s3 = $19,
	$s4 = $20,
	$s5 = $21,
	$s6 = $22,
	$s7 = $23,
	$t8 = $24,
	$t9 = $25,
	$k0 = $26,
	$k1 = $27,
	$gp = $28,
	$sp = $29,
	$fp = $30,
	$ra = $31,
};

extern const Op oplst[OPNB];
extern Reg regs[REGNB];

#endif
