#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED
#include "Socio.h"
#include "IterPersonas.h"

class Socios
{
private:
    struct Nodo
    {
        Socio * info;
        Nodo * hIzq;
        Nodo * hDer;
    };
    Nodo * ABB;

    void destruirArbol (Nodo * &);
    Boolean perteneceArbol (Nodo *, long int);
    void insertarEnArbol (Nodo * &, Socio *);
    Socio * obtenerEnArbol (Nodo *, long int);
    void cargarIterador (Nodo *, IterPersonas&);

public:
    Socios();
    ~Socios();
    Boolean member (long int);
    void Insert(Socio *);
    Socio * Find (long int);
    void listarSocios (IterPersonas &);
};

#endif // SOCIOS_H_INCLUDED
