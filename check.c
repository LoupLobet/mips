#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "util.h"
#include "inst.h"
#include "check.h"

/*
 * Cette fonction verifie si un immediat est codable sur 5 bits
 */
int
isimm5(int *n)
{
   return ((n & 31) == n);
}

/*
 * Cette fonction verifie si un immediat est codable sur 16 bits
 */
int
isimm16(int n)
{
    return ((n & 65535) == n);
}

int
istarget(inh n)
{

}