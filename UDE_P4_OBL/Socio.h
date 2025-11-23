#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED
#include "Entrenador.h"

class Socio: public Persona
{
private:
    float cuotaBase;
    String domicilio;
    Entrenador entrenador;

public:
    Socio (long int, String, String, float, Entrenador);
    float getCuota();
    String getDomicilio();
    Entrenador getEntrenador();
    virtual String tipoSocio() = 0;

    virtual float calcularCuotaTotal(int);
    void mostrar();
};

#endif // SOCIO_H_INCLUDED
