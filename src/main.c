// Projet MIPS 2022-2023
// Auteurs: TUVATALENI_LOBET

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

enum { KEEP_GOING, STEP_BY_STEP };

static void	 automatic(char *, char *, char *, int);
static void	 interactive(void);
static void	 usage(void);

int
main(int argc, char *argv[])
{
	switch (argc) {
	case 1:
		interactive();
		break;
	case 3:
		if (!strcmp(argv[2], "-pas"))
			automatic(argv[1], NULL, NULL, STEP_BY_STEP);
		else
			usage();
		break;
	case 4:
		automatic(argv[1], argv[2], argv[3], KEEP_GOING);
		break;
	default:
		usage();
	}

    printf("Hello émulateur MIPS!\n");

    return 0;
}

static void
automatic(char *file, char *as, char *out, int mode)
{
	FILE *afp, *ofp, *rfp;

	if (mode == KEEP_GOING) {
		if ((afp = fopen(as, "w")) == NULL)
			error("couldn't open file: %s", as);
		if ((ofp = fopen(out, "w")) == NULL)
			error("couldn't open file: %s", out);
	}

	if ((rfp = fopen(file, "r")) == NULL)
		error("couldn't open file: %s", file);


	fclose(rfp);

	if (mode == KEEP_GOING) {
		fclose(afp);
		fclose(ofp);
	}
}

static void
interactive(void)
{

}

static void
usage(void)
{
	fputs("usage: emul-mips [fichier -pas] [fichier asm out]\n", stderr);
	exit(1);
}