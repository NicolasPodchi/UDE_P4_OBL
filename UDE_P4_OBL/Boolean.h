#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED
#include <stdio.h>

typedef enum {FALSE, TRUE} Boolean;

void cargaBool (Boolean &b);

void printBool (Boolean b);

#endif // BOOLEAN_H_INCLUDED
