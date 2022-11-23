#include <ctype.h>
#include <string.h>

#include "inst.h"

Label *labels;

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
	[ADD]  = { REG,  REG,   REG },
	[ADDI] = { REG,  REG,   IMM16 },
	[AND]  = { REG,  REG,   REG },
	[BEQ]  = { REG,  REG,   LABEL },
	[BGTZ] = { REG,  REG,   LABEL },
	[BLEZ] = { REG,  REG,   LABEL },
	[BNE]  = { REG,  REG,   LABEL },
	[DIV]  = { REG,  REG,   VOID },
	[J]    = { TARG, VOID,  VOID },
	[JAL]  = { TARG, VOID,  VOID },
	[JR]   = { REG,  VOID,  VOID },
	[LUI]  = { REG,  IMM16, VOID },
	[LW]   = { REG,  IMM16, REG },
	[MFHI] = { REG,  VOID,  VOID },
	[MFLO] = { REG,  VOID,  VOID },
	[MULT] = { REG,  REG,   VOID },
	[NOP]  = { VOID, VOID,  VOID },
	[OR]   = { REG,  REG,   REG },
	[ROTR] = { REG,  REG,   IMM5 },
	[SLL]  = { REG,  REG,   IMM5 },
	[SLT]  = { REG,  REG,   REG },
	[SRL]  = { REG,  REG,   REG },
	[SUB]  = { REG,  REG,   REG },
	[SW]   = { REG,  IMM16, REG },
	[XOR]  = { REG,  REG,   REG },
}

Reg regs[REGNB] = {
	[$0] =  { "$0",  0 },
	[$1] =  { "$1",  0 },
	[$2] =  { "$2",  0 },
	[$3] =  { "$3",  0 },
	[$4] =  { "$4",  0 },
	[$5] =  { "$5",  0 },
	[$6] =  { "$6",  0 },
	[$7] =  { "$7",  0 },
	[$8] =  { "$8",  0 },
	[$9] =  { "$9",  0 },
	[$10] = { "$10", 0 },
	[$11] = { "$11", 0 },
	[$12] = { "$12", 0 },
	[$13] = { "$13", 0 },
	[$14] = { "$14", 0 },
	[$15] = { "$15", 0 },
	[$16] = { "$16", 0 },
	[$17] = { "$17", 0 },
	[$18] = { "$18", 0 },
	[$19] = { "$19", 0 },
	[$20] = { "$20", 0 },
	[$21] = { "$21", 0 },
	[$22] = { "$22", 0 },
	[$23] = { "$23", 0 },
	[$24] = { "$24", 0 },
	[$25] = { "$25", 0 },
	[$26] = { "$26", 0 },
	[$27] = { "$27", 0 },
	[$28] = { "$28", 0 },
	[$29] = { "$29", 0 },
	[$30] = { "$30", 0 },
	[$31] = { "$31", 0 },
};

int
strtoop(char *s)
{
	int i;

	for (i = 0; i < OPNB; i++) {
		if (!strcmp(oplst[i].s, s))
			return i;
	}
	return -1;
}
