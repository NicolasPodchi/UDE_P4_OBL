#ifndef COMUN_H_INCLUDED
#define COMUN_H_INCLUDED
#include "Socio.h"

class Comun: public Socio
{
private:
    float extra;

public:
    Comun ();
    Comun (long int, String, String, float, Entrenador *, float);
    Comun (long int, String, String, float, float);
    float getExtra ();
    String tipoSocio();

    float calcularCuotaTotal(int);
    void mostrar();
};
#endif // COMUN_H_INCLUDED
