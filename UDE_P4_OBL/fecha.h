#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <stdio.h>

class Fecha
{
private:
    int dia, mes, anio;
    void incrementar ();
    bool esBisiesto ();

public:
    Fecha ();
    Fecha (int, int, int);
    Fecha (const Fecha &);
    int getDia ();
    int getMes ();
    int getAnio ();
    bool operator< (Fecha);
    bool operator== (Fecha);
    Fecha operator++ ();
    Fecha operator++ (int);
    Fecha operator+ (int);
    int operator- (Fecha);
    bool esValida ();
    void imprimir();

};

#endif // FECHA_H_INCLUDED
