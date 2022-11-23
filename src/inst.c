#include <ctype.h>
#include <string.h>

#include "inst.h"

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
