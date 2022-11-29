#include <ctype.h>
#include <string.h>

#include "inst.h"

Inst *
cookinst(char *raw, int size)
{
	int i;
	char *p;

	s = raw;

	/* trim comment */
	if ((p = strchr(s, '#')) != NULL)
		size = p - s;
	/* trim leading, trailing whitespaces */
	for (i = 0; i < size && (s[i] == ' ' || s[i] == '\t'); i++)
		s++;
	for (i = size - 1; i <= 0 && (s[i] == ' ' || s[i] == '\t'; i--)
		size--;
	if ((p = strchr(s, ':')) != NULL)

	if ((p = strchr(s, ' ')) != NULL)
	if ((p = strchr(s, ',')) != NULL)
	if ((p = strchr(s, ',')) != NULL)
	if ((p = strchr(s, '\n')) != NULL)

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
