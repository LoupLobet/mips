#include <ctype.h>
#include <string.h>

#include "build.h"
#include "check.h"
#include "inst.h"
#include "util.h"

const Op oplst[OPNB] = {
	       /*  NAME    HEXA  BUILD 			RUN     PROTOTYPE          */
	[ADD]  = { "ADD",  0x20, build_add,		NULL, { REG,  REG,   REG } },
	[ADDI] = { "ADDI", 0x08, build_addi,	NULL, { REG,  REG,   IMM16 } },
	[AND]  = { "AND",  0x24, build_add, 	NULL, { REG,  REG,   REG } },
	[BEQ]  = { "BEQ",  0x04, build_beq, 	NULL, { REG,  REG,   IMM16 } },
	[BGTZ] = { "BGTZ", 0x07, build_bgtz, 	NULL, { REG,  REG,   IMM16 } },
	[BLEZ] = { "BLEZ", 0x06, build_blez, 	NULL, { REG,  REG,   IMM16 } },
	[BNE]  = { "BNE",  0x04, build_bne, 	NULL, { REG,  REG,   IMM16 } },
	[DIV]  = { "DIV",  0x1a, build_div, 	NULL, { REG,  REG,   VOID } },
	[J]    = { "J",    0x02, build_j, 		NULL, { TARG, VOID,  VOID } },
	[JAL]  = { "JAL",  0x03, build_jal, 	NULL, { TARG, VOID,  VOID } },
	[JR]   = { "JR",   0x08, build_jar,		NULL, { REG,  VOID,  VOID } },
	[LUI]  = { "LUI",  0x0f, build_lui, 	NULL, { REG,  IMM16, VOID } },
	[LW]   = { "LW",   0x23, build_lw, 		NULL, { REG,  IMM16, REG } },
	[MFHI] = { "MFHI", 0x10, build_mfhi, 	NULL, { REG,  VOID,  VOID } },
	[MFLO] = { "MFLO", 0x12, build_mflo, 	NULL, { REG,  VOID,  VOID } },
	[MULT] = { "MULT", 0x18, build_mult, 	NULL, { REG,  REG,   VOID } },
	[NOP]  = { "NOP",  0x00, build_nop, 	NULL, { VOID, VOID,  VOID } },
	[OR]   = { "OR",   0x25, build_or, 		NULL, { REG,  REG,   REG } },
	[ROTR] = { "ROTR", 0x02, build_rotr, 	NULL, { REG,  REG,   IMM5 } },
	[SLL]  = { "SLL",  0x00, build_sll, 	NULL, { REG,  REG,   IMM5 } },
	[SLT]  = { "SLT",  0x2a, build_slt, 	NULL, { REG,  REG,   REG } },
	[SRL]  = { "SRL",  0x02, build_srl, 	NULL, { REG,  REG,   REG } },
	[SUB]  = { "SUB",  0x22, build_sub, 	NULL, { REG,  REG,   REG } },
	[SW]   = { "SW",   0x2b, build_sw, 		NULL, { REG,  IMM16, REG } },
	[XOR]  = { "XOR",  0x26, build_xor, 	NULL, { REG,  REG,   REG } },
};

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

Inst *
parseinst(char *raw)
{
	Inst *inst = NULL;
	char *argv[4];
	char *s;
	char *p;
	int argc;
	int i;


	s = emalloc(strlen(raw) + 1);
	p = s;
	strcpy(p, raw);
	rmcomment(p);
	/* remove leading spaces */
	for (i = 0; s[i] != '\0' && isspace(s[i]); i++)
		p++;
	if (formatraw(p)) {
		free(s);
		return NULL;
	}
	rmspaces(p);

	argc = 0;
	for (i = 0; p[i] != '\0'; i++) {
		if (p[i] == ',' || p [i] == '\n') {
			argv[argc] = emalloc(i + 1);
			strncpy(argv[argc], p, i);
			argc++;
			p += i + 1;
			i = -1; /* makes i == 0 in the next loop iteration */
		}
	}
	free(s);

	/* verify prototype and create Inst */
	inst = emalloc(sizeof(Inst));
	if (argc) {
		if ((inst->argv[0] = strtoop(*argv)) == -1) {
			for (i = 0; i < argc; i++)
				free(argv[i]);
			free(inst);
			return NULL;
		}
		for (i = 0; i < (int) (sizeof(oplst[inst->argv[0]].proto) / sizeof(int)); i++) {
			switch (oplst[inst->argv[0]].proto[i]) {
			case VOID:
				if (argc > i + 1) {
					for (i = 0; i < argc; i++)
						free(argv[i]);
					free(inst);
					return NULL;
				}
				break;
			case IMM5:
				inst->argv[i + 1] = estrtol(argv[i + 1], 10);
				if (!isimm5(inst->argv[i + 1])) {
					for (i = 0; i < argc; i++)
						free(argv[i]);
					free(inst);
					return NULL;
				}
				break;
			case IMM16:
				inst->argv[i + 1] = estrtol(argv[i + 1], 10);
				if (!isimm16(inst->argv[i + 1])) {
					for (i = 0; i < argc; i++)
						free(argv[i]);
					free(inst);
					return NULL;
				}
				break;
			case REG:
				if ((inst->argv[i + 1] = strtoreg(argv[i + 1])) == -1) {
					for (i = 0; i < argc; i++)
						free(argv[i]);
					free(inst);
					return NULL;
				}
				break;
			case TARG:
				inst->argv[i + 1] = estrtol(argv[i + 1], 10);
				if (!istarget(inst->argv[i + 1])) {
					for (i = 0; i < argc; i++)
						free(argv[i]);
					free(inst);
					return NULL;
				}
			default:
				error ("invalid prototype in source code");
			}
		}
	}
	inst->argc = argc;

	for (i = 0; i < argc; i++)
		free(argv[i]);

	return inst;
}

int
formatraw(char *s)
{
	int i;
	int missmatch;

	/*
	 * Insert a ',' before first arg to have a "OP,ARG,ARG,ARG"
	 * format, instead of a "OP ARG,ARG,ARG", for easy parsing.
	 */
	for (i = 0; s[i] != '\0' && !isspace(s[i]); i++);
	if (s[i] != '\0')
		s[i] = ',';

	/* transform "base(offset)" into "base,offset " for easy parsing */
	missmatch = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == '(') {
			s[i] = ',';
			missmatch = 1;
		}
		if (s[i] == ')') {
			s[i] = ' ';
			missmatch = 0;
		}
	}
	return missmatch;
}

void
rmcomment(char *s)
{
	int i;

	for (i = 0; s[i] != '\0' ; i++) {
		if (s[i] == '#') {
			s[i] = '\n';
			s[i + 1] = '\0';
		}
	}
}

void
rmspaces(char *s)
{
	char *p = s;

	do {
		while (isspace(*p) && *p != '\n')
			++p;
	} while ((*s++ = *p++));
}

int
strtoop(char *s)
{
	int i;

	for (i = 0; i < OPNB; i++) {
		if (!strcmp(oplst[i].name, s))
			return i;
	}
	return -1;
}

int
strtoreg(char *s)
{
	int i;

	for (i = 0; i  < REGNB; i++) {
		if (!strcmp(regs[i].name, s))
			return i;
	}
	return -1;
}

