#include "Becado.h"

Becado:: Becado (long int ci, String nombre, String domicilio, float cuota, Entrenador ent, int porcentaje, Fecha fechaOtorgada): Socio(ci,nombre,domicilio,cuota,ent)
{
    porcentaje=porcentaje;
    fechaOtorgada=fechaOtorgada;
}

int Becado ::  getPorcentaje ()
{
    return porcentaje;
}

Fecha Becado ::  getFechaOtorgada()
{
    return fechaOtorgada;
}

String Becado :: tipoSocio()
{
    String tipo("becado");
    return tipo;
}
