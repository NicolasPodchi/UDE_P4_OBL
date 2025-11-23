#include "Boolean.h"

void cargaBool (Boolean &b)
{
    char c;
    printf("Ingrese (V)erdadero o (F)also: ");
    fflush(stdin);
    scanf("%c",&c);
    switch(c)
    {
    case 'V':
    case 'v':
        b = TRUE;
        break;
    case 'F':
    case 'f':
        b= FALSE;
    }
}

void printBool (Boolean b)
{
    if(b==TRUE)
        printf("True");
    else
        printf("False");
}
