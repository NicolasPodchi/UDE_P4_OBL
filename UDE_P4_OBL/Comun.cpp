#include "Comun.h"

Comun :: Comun (long int ci, String nombre, String domicilio, float cuota, Entrenador ent, float extra): Socio(ci,nombre,domicilio,cuota,ent)
{
    extra=extra;
}

Comun :: Comun (long int ci, String nombre, String domicilio, float cuota, float extra): Socio(ci,nombre,domicilio,cuota)
{
    extra=extra;
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
}
