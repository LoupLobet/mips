#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "inst.h"
#include "check.h"

/*
 * Cette fonction verifie si une chaine est un registre valide
 * c'est-à-dire si elle commence par '$' si oui la fonction verifie s'il est
 * dans le tableau des registres.
 * La fonction retourne 1 si reg est un registre et 0 si non
 */
int
isReg(char *reg) {

    if(reg[0] =='$'){
        for(int i=0; i<REGNB; i++){
            if(!strcmp(reg,regs[i].s)){
                return 1;
            }
        }

    }
    return 0;
}

/*
 * Cette fonction verifie si une chaine est un label valide
 * c'est-à-dire si elle commence pas par un chiffre et contient
 * des caractères alphanumeriques.
 * Elle retourne 1 si oui et 0 si non
 */
int
isLabel(char *label){

    int n;
    n = strlen(label);
    int j=0;
    if (!isdigit(label[0])){
        for(int i=1; i<n; i++){
            if(isalnum(label[i])){
                j++;
            }else{
                j =0;
                return 0;
            }
        }
    }
    if(j!=0){
        return 1;
    }
    return 0;
}

/*Cette fonction verifie si une chaine (op) est une operation valide
 *et si elle est dans le tableau des operations qui le compilateur
 *doit couvrir
 *
 */
int
isop(char *op){

    if(!isdigit(op[0]) || strlen(op) > 4)
        for(int i=0; i<OPNB; i++){
            if(strcmp(op,oplst[i].name) == 0){
                return 1;
            }
        }
 return 0;
}

/*Cette fonction verifie si un immediat est codable sur 5 bits
 *
 */

int
isImm_5(char *imm){
    int n;
    n = estrtol(imm,10);
    if ((n & 31) == n){
            return 1;
        }

    return 0;
}

/*Cette fonction verifie si un immediat est codable sur 16 bits
 *
 */

int
isImm_16(char *imm){
    int n;
    n = estrtol(imm,10);

    if ((n & 65535) == n){
            return 1;
        }
    return 0;
}











