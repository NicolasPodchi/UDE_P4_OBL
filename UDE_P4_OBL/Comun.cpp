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

float Comun :: calcularCuotaTotal(int mes)
{
    float cuotaTotal=getCuota();

    if (this->extra<=cuotaTotal*0.25)
        cuotaTotal=cuotaTotal+extra/2;
    else
    {
        if(extra<= cuotaTotal*0.75)
            cuotaTotal=cuotaTotal+extra;
        else
            cuotaTotal=cuotaTotal+extra*1.25;
    }

    if (mes==1||mes==2)
    {
        cuotaTotal=cuotaTotal*0.80;
    }

    return cuotaTotal;
}

void Comun :: mostrar()
{
    Socio :: mostrar();

    printf("Cuota Extra: %.2f", extra);
}
