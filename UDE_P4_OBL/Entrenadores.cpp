#include "Entrenadores.h"

Entrenadores :: Entrenadores()
{
    for(int i = 0; i < B ; i++)
    {
        crearLista(Hash[i]);
    }
}

Entrenadores :: ~Entrenadores()
{
    for(int i =0 ; i < B ; i++)
    {
        destruirLista(Hash[i]);
    }
}

int Entrenadores :: dispersion (long int cedula)
{
    return cedula % B;
}

void Entrenadores :: crearLista(Nodo * &L)
{
    L = NULL;
}

Boolean Entrenadores :: perteneceLista (Nodo * l, long int clave)
{
    Boolean encontre = FALSE;

    while(!encontre && l!=NULL)
    {

        if(clave == l->e.getCedula())
            encontre = TRUE;
        else
            l=l->sig;
    }
    return encontre;
}

void Entrenadores :: insFront (Nodo * &l, Entrenador e)
{
    Nodo * nuevo = new Nodo;
    nuevo->e = e;
    nuevo->sig = l;
    l = nuevo;
}

Entrenador * Entrenadores :: obtenerEnLista(Nodo * l, long int clave)
{
    while(l->e.getCedula()!=clave)
        l=l->sig;
    return &l->e;
}

void Entrenadores :: borrarEnLista (Nodo * &l, int clave)
{
    Nodo * aux = l;
    if(aux->e.getCedula() == clave)
    {
        l=l->sig;
        delete aux;
    }
    else
    {
        while(aux->sig->e.getCedula()!=clave)
            aux=aux->sig;
        Nodo * aux2 = aux->sig;
        aux->sig = aux->sig->sig;
        delete aux2;
    }
}

void Entrenadores :: destruirLista(Nodo * &L)
{
    Nodo * aux = L;
    while (aux != NULL)
    {
        L = aux->sig;
        delete aux;
        aux = L;
    }
    L = aux;
}

Boolean Entrenadores :: member (long int ci)
{
    int cubeta = dispersion(ci);
    return perteneceLista(Hash[cubeta], ci);
}

//Precondición: el elemento a insertar no es miembro del diccionario.
void Entrenadores::Insert (Entrenador e)
{
    long int clave = e.getCedula();
    int cubeta = dispersion(clave);
    insFront(Hash[cubeta], e);
}

//Precondición: el elemento es miembro del diccionario.
Entrenador * Entrenadores :: Find (long int ci)
{
    int cubeta = dispersion(ci);
    return obtenerEnLista(Hash[cubeta], ci);
}

//Precondición: el elemento es miembro del diccionario.
void Entrenadores :: Delete (long int ci)
{
    int cubeta = dispersion(ci);
    borrarEnLista(Hash[cubeta], ci);
}

void Entrenadores :: cargarIteradorLista (Nodo * l, IterPersonas &iter)
{
    while(l!=NULL)
    {
        iter.insertar(&l->e);
        l = l->sig;
    }
}

void Entrenadores :: listarEntrenadores(IterPersonas &iter)
{
    for(int i = 0; i < B; i++)
    {
        cargarIteradorLista(Hash[i], iter);
    }
}

void Entrenadores::ChequearAnioYPromedio (Nodo * l, int anio, float &suma, int &cant)
{
    while (l!=NULL)
    {
        if (l->e.getAnio()>=anio)
        {
            cant++;
            suma=suma+ l->e.getSalario();
        }
        l=l->sig;
    }

}

void Entrenadores::recorrerEntrenadorAnioYpromedio(int anio, int &cant, float &prom)
{
    for (int i = 0; i < B; i++)
    {
        ChequearAnioYPromedio(Hash[i], anio, prom, cant);
    }
    prom = prom/cant;
}
