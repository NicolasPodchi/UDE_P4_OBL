#ifndef BECADO_H_INCLUDED
#define BECADO_H_INCLUDED
#include "Fecha.h"
#include "Socio.h"

class Becado: public Socio
{
private:
    int porcentaje;
    Fecha fechaOtorgada;

public:
    Becado ();
    Becado (long int, String, String, float, Entrenador *, int, Fecha);
    Becado (long int, String, String, float, int, Fecha);
    int getPorcentaje();
    Fecha getFechaOtorgada();
    String tipoSocio();

    float calcularCuotaTotal(int);
    void mostrar();
};

#endif // BECADO_H_INCLUDED
