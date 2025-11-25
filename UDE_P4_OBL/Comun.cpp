#include "Comun.h"

Comun :: Comun (long int ci, String nombre, String domicilio, float cuota, Entrenador * ent, float cuotaExtra): Socio(ci,nombre,domicilio,cuota,ent)
{
    extra=cuotaExtra;
}

Comun :: Comun (long int ci, String nombre, String domicilio, float cuota, float cuotaExtra): Socio(ci,nombre,domicilio,cuota)
{
    extra=cuotaExtra;
}

float Comun ::  getExtra ()
{
    return extra;
}

String Comun :: tipoSocio()
{
    String tipo("comun");
    return tipo;
}

float Comun :: calcularCuotaTotal(int)
{
    return 0;
}

void Comun :: mostrar()
{
    Socio :: mostrar();

    printf("Cuota Extra: %f", extra);
}
