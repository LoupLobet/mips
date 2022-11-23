#include <stdlib.h>
#include <stdio.h>

typedef union {
	char *s;
	int n;
} Arg;

typedef struct {
	char *s;
	int n;
	char *(*hexa)(char [3]);
	int (*run)(char [3]);
} Op;

int	 strtoop(char *);

enum {
	VOID = 1 << 1,
	REG  = 1 << 2,
	IMM  = 1 << 3,
	BASE = 1 << 4,
	LABEL = 1 << 5,
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

const Op oplst[OPNB] = {
	[ADD]  = { "ADD",  0x20, NULL, NULL },
	[ADDI] = { "ADDI", 0x08, NULL, NULL },
	[AND]  = { "AND",  0x24, NULL, NULL },
	[BEQ]  = { "BEQ",  0x04, NULL, NULL },
	[BGTZ] = { "BGTZ", 0x07, NULL, NULL },
	[BLEZ] = { "BLEZ", 0x06, NULL, NULL },
	[BNE]  = { "BNE",  0x04, NULL, NULL },
	[DIV]  = { "DIV",  0x1a, NULL, NULL },
	[J]    = { "J",    0x02, NULL, NULL },
	[JAL]  = { "JAL",  0x03, NULL, NULL },
	[JR]   = { "JR",   0x08, NULL, NULL },
	[LUI]  = { "LUI",  0x0f, NULL, NULL },
	[LW]   = { "LW",   0x23, NULL, NULL },
	[MFHI] = { "MFHI", 0x10, NULL, NULL },
	[MFLO] = { "MFLO", 0x10, NULL, NULL },
	[MULT] = { "MULT", 0x18, NULL, NULL },
	[NOP]  = { "NOP",  0x00, NULL, NULL },
	[OR]   = { "OR",   0x25, NULL, NULL },
	[ROTR] = { "ROTR", 0x02, NULL, NULL },
	[SLL]  = { "SLL",  0x00, NULL, NULL },
	[SLT]  = { "SLT",  0x2a, NULL, NULL },
	[SRL]  = { "SRL",  0x02, NULL, NULL },
	[SUB]  = { "SUB",  0x22, NULL, NULL },
	[SW]   = { "SW",   0x2b, NULL, NULL },
	[XOR]  = { "XOR",  0x26, NULL, NULL },
};

const int protos[OPNB][3] = {
	[ADD]  = { REG, REG, REG },
	[ADDI] = { REG, REG, IMM },
	[AND]  = { REG, REG, REG },
	[BEQ]  = { REG, REG, IMM|LABEL },
	[BGTZ] = { REG, REG, IMM|LABEL },
	[BLEZ] = { REG, REG, IMM|LABEL },
	[BNE]  = { REG, REG, IMM|LABEL },
	[DIV]  = { REG, REG, VOID },
	[J]    = {  },
	[JAL]  = {  },
	[JR]   = {  },
	[LUI]  = { REG, IMM, VOID },
	[LW]   = { REG, BASE },
	[MFHI] = {  },
	[MFLO] = {  },
	[MULT] = {  },
	[NOP]  = {  },
	[OR]   = {  },
	[ROTR] = {  },
	[SLL]  = {  },
	[SLT]  = {  },
	[SRL]  = {  },
	[SUB]  = {  },
	[SW]   = {  },
	[XOR]  = {  },
}
