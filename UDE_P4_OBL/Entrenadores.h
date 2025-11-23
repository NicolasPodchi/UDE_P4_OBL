#ifndef ENTRENADORES_H_INCLUDED
#define ENTRENADORES_H_INCLUDED
#include "Entrenador.h"
#include "IterPersonas.h"

const int B = 30;/*Cantidad de entrenadores*/

class Entrenadores
{
private:
    struct Nodo
    {
        Entrenador e;
        Nodo * sig;
    };

    Nodo * Hash[B];

    int dispersion(long int);

    void crearLista(Nodo * &L);

    Boolean perteneceLista (Nodo *, long int);

    void insFront (Nodo * &, Entrenador);

    Entrenador obtenerEnLista(Nodo *, long int);

    void borrarEnLista (Nodo * &l, int clave);

    void destruirLista(Nodo * &);
public:
    Entrenadores();

    ~Entrenadores();

    Boolean member(long int);

    //Precondición: el elemento a insertar no es miembro del diccionario.
    void Insert(Entrenador);

    //Precondición: el elemento es miembro del diccionario.
    Entrenador Find(long int);

    //Precondición: el elemento es miembro del diccionario.
    void Delete(long int);
};

#endif // ENTRENADORES_H_INCLUDED
