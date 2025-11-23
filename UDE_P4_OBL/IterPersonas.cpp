#include "IterPersonas.h"

IterPersonas :: IterPersonas()
{
    prim = NULL;
    ult = NULL;
    actual = NULL;
}

void IterPersonas ::insertar (Persona * p)
{
    Nodo * nuevo = new Nodo;
    nuevo -> info = p;
    nuevo -> sig = NULL;
    if(prim == NULL)
    {
        prim = nuevo;
        actual = nuevo;
        ult = nuevo;
    }
    else
    {
        ult -> sig = nuevo;
        ult = nuevo;
    }
}

Boolean IterPersonas :: hayMasPersonas()
{
    Boolean result = FALSE;

    if(actual != NULL)
    {
        result = TRUE;
    }
    return result;
}

Persona * IterPersonas :: proximaPersona()
{
    Persona * resu = actual->info;
    actual = actual -> sig;
    return resu;
}

IterPersonas :: ~IterPersonas ()
{
    Nodo * aux = prim;
    while(aux != NULL)
    {
        prim = prim->sig;
        delete aux;
        aux = prim;
    }
}
