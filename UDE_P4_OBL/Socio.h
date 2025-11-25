#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#pragma once
#include "Entrenador.h"

class Socio: public Persona
{
private:
    float cuotaBase;
    String domicilio;
    Entrenador * entrenador;

public:
    virtual ~Socio();
    Socio (long int, String, String, float, Entrenador *);
    Socio (long int, String, String, float);
    float getCuota();
    String getDomicilio();
    Entrenador * getEntrenador();
    void setEntrenador(Entrenador *);
    virtual String tipoSocio() = 0;

    virtual float calcularCuotaTotal(int);
    void mostrarBasico();
    void mostrar();
};

#endif // SOCIO_H_INCLUDED
