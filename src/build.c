#include <stdio.h>
#include <stdlib.h>

#include "build.h"
#include "inst.h"

void
build_addi(Inst *inst, char build[9])
{
	int hexa;

	hexa = inst->argv[3] + (inst->argv[1]<<16) + (inst->argv[2]<<21) + (oplst[inst->argv[0]].opcode<<26);
	snprintf(build, 9, "%08x", hexa);

}

void
build_add(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (0<<6) + (inst->argv[1]<<11) + (inst->argv[3]<<16) + (inst->argv[2]<<21) + (0<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_sub(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (0<<6) + (inst->argv[1]<<11) + (inst->argv[3]<<16) + (inst->argv[2]<<21) + (0<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_div(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (0<<6) + (inst->argv[2]<<16) + (inst->argv[1]<<21) + (0<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_mfhi(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (0<<6) + (inst->argv[1]<<11) + (0<<16) + (0<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_mflo(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (0<<6) + (inst->argv[1]<<11) + (0<<16) + (0<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_mult(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (0<<6) + (inst->argv[2]<<16) + (inst->argv[1]<<21) + (0<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_and(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (0<<6) + (inst->argv[1]<<11) + (inst->argv[3]<<16) + (inst->argv[2]<<21) + (0<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_beq(Inst *inst, char build[9])
{
	int hexa;

	hexa = inst->argv[3] + (inst->argv[2]<<16) + (inst->argv[1]<<21) + (oplst[inst->argv[0]].opcode<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_bgtz(Inst *inst, char build[9])
{
	int hexa;

	hexa = inst->argv[3] + (0<<16) + (inst->argv[1]<<21) + (oplst[inst->argv[0]].opcode<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_blez(Inst *inst, char build[9])
{
	int hexa;

	hexa = inst->argv[3] + (0<<16) + (inst->argv[1]<<21) + (oplst[inst->argv[0]].opcode<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_bne(Inst *inst, char build[9])
{
	int hexa;

	hexa = inst->argv[3] + (inst->argv[2]<<16) + (inst->argv[1]<<21) + (oplst[inst->argv[0]].opcode<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_j(Inst *inst, char build[9])
{
	int hexa;

	hexa = inst->argv[1] + (oplst[inst->argv[0]].opcode<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_jal(Inst *inst, char build[9])
{
	int hexa;

	hexa = inst->argv[1] + (oplst[inst->argv[0]].opcode<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_jar(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (0<<6) + (0<<11) + (inst->argv[1]<<21) + (0<<26);
	snprintf(build, 9, "%08x", hexa);
}

void
build_lui(Inst *inst, char build[9])
{
	int hexa;

	hexa = inst->argv[2] + (inst->argv[1]<<16) + (0<<21) + (oplst[inst->argv[0]].opcode<<26);
	snprintf(build, 9, "%08x", hexa);

}

void
build_lw(Inst *inst, char build[9])
{
	int hexa;

	hexa = inst->argv[2] + (inst->argv[1]<<16) + (inst->argv[3]<<21) + (oplst[inst->argv[0]].opcode<<26);
	snprintf(build, 9, "%08x", hexa);

}

void
build_nop(Inst *inst, char build[9])
{
	int hexa;

	hexa = 0 + (oplst[inst->argv[0]].opcode<<26);
	snprintf(build, 9, "%08x", hexa);

}

void
build_or(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (0<<6) + (inst->argv[1]<<11) + (inst->argv[3]<<16) + (inst->argv[3]<<21) + (0<<26);
	snprintf(build, 9, "%08x", hexa);

}

void
build_rotr(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (inst->argv[3]<<6) + (inst->argv[1]<<11) + (inst->argv[2]<<16) + (1<<21) + (0<<22) +(0<<26);
	snprintf(build, 9, "%08x", hexa);

}

void
build_sll(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (inst->argv[3]<<6) + (inst->argv[1]<<11) + (inst->argv[2]<<16) + (0<<21) +(0<<26);
	snprintf(build, 9, "%08x", hexa);

}

void
build_slt(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (0<<6) + (inst->argv[1]<<11) + (inst->argv[3]<<16) + (inst->argv[2]<<21) + (0<<26);
	snprintf(build, 9, "%08x", hexa);

}

void
build_srl(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (inst->argv[3]<<6) + (inst->argv[1]<<11) + (inst->argv[2]<<16) + (0<<21) + (0<<22) +(0<<26);
	snprintf(build, 9, "%08x", hexa);

}

void
build_sw(Inst *inst, char build[9])
{
	int hexa;

	hexa = inst->argv[2] + (inst->argv[1]<<16) + (inst->argv[3]<<21) + (oplst[inst->argv[0]].opcode<<26);
	snprintf(build, 9, "%08x", hexa);

}

void
build_xor(Inst *inst, char build[9])
{
	int hexa;

	hexa = oplst[inst->argv[0]].opcode + (0<<6) + (inst->argv[1]<<11) + (inst->argv[3]<<16) + (inst->argv[2]<<21) + (0<<26);
	snprintf(build, 9, "%08x", hexa);

}