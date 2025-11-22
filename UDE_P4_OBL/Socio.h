#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED
#include "Entrenador.h"
class Socio: public Persona
{
private:
    float CuotaBase;
    String Domicilio;
    Entrenador EntrenadorAsignado;
public:
    Socio (long int, String, String, float, Entrenador);
    String getDomicilio();
    Entrenador getEntrenador();
    virtual float getCuota();
    virtual String tipoSocio() = 0;


};
#endif // SOCIO_H_INCLUDED
