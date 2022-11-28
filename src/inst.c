#include <ctype.h>
#include <string.h>

#include "inst.h"

Inst *
cookinst(char *raw)
{
	char *argv[3]
	Inst *inst;
	char *p;
	int argc;
	int i;
	int space;

	/* trim comment */
	for (i = 0; raw[i] != '\0'; i++) {
		if(raw[i] == '#')
			raw[i] = '\0';
	}
	for (i = 0; raw[i] != '\0'; i++) {
		if (raw[i] == ' ')
			continue;
		if (raw[i] == ',') {
		}

	}
}

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
