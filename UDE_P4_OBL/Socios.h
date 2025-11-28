#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

#include "Socio.h"
#include "IterPersonas.h"
#include "Becado.h"

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
    void cargarIterador (Nodo *, IterPersonas &);
    float CuotasTotalesEnArbol(Nodo * , int);
    Socio * socioMayorCuotaEnArbol (Nodo * , int);
    int cuantosBecadosDesdeFecha(Nodo *, Fecha);

public:
    Socios();
    ~Socios();
    Boolean member (long int);
    void Insert(Socio *);
    Socio * Find (long int);
    Boolean Empty ();
    void listarSocios (IterPersonas &);
    float montoTotalCuotasMes (int);

    //Precondicion: Debe existir al menos un socio
    Socio * socioCuotaMayor(int);

    int contarBecadosPorFecha(Fecha);
};

#endif // SOCIOS_H_INCLUDED
