#include "Socios.h"

void Socios :: destruirArbol (Nodo * &a)
{
    if(a!=NULL)
    {
        destruirArbol(a->hIzq);
        destruirArbol(a->hDer);
        delete a->info;
        delete a;
        a = NULL;
    }
}

Boolean Socios :: perteneceArbol (Nodo * a, long int ci)
{
    Boolean encontre = FALSE;
    while (!encontre && a != NULL)
    {
        long int cedula = a->info ->getCedula();
        if( cedula== ci)
            encontre = TRUE;
        else
        {
            if(ci < cedula)
                a = a->hIzq;
            else
                a = a->hDer;
        }
    }
    return encontre;
}

void Socios :: insertarEnArbol (Nodo * &a, Socio * s)
{
    if(a==NULL)
    {
        a = new Nodo;
        a -> info = s;
        a ->hIzq = NULL;
        a -> hDer = NULL;
    }
    else
    {
        if(s -> getCedula() < a->info->getCedula())
            insertarEnArbol(a->hIzq,s);
        else
            insertarEnArbol(a->hDer,s);
    }
}

Socio * Socios :: obtenerEnArbol (Nodo * a, long int ci)
{
    while (a->info->getCedula() != ci)
    {
        if(ci < a->info->getCedula())
            a = a -> hIzq;
        else
            a = a->hDer;
    }
    return a->info;
}

void Socios :: cargarIterador (Nodo * a, IterPersonas &iter)
{
    if(a!=NULL)
    {
        cargarIterador(a->hIzq,iter);
        iter.insertar(a->info);
        cargarIterador(a->hDer, iter);
    }
}

Socios :: Socios ()
{
    ABB = NULL;

}

Socios :: ~Socios ()
{
    destruirArbol(ABB);
}

Boolean Socios :: member (long int ci)
{
    return perteneceArbol(ABB, ci);
}

void Socios :: Insert(Socio * s)
{
    insertarEnArbol(ABB,s);

}

Socio * Socios ::  Find (long int ci)
{
    return obtenerEnArbol(ABB, ci);

}

void Socios :: listarSocios (IterPersonas &iter)
{
    cargarIterador(ABB, iter);

}
