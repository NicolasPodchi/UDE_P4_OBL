#include "Becado.h"

Becado:: Becado (long int ci, String nombre, String domicilio, float cuota, Entrenador * ent, int porc, Fecha fechaOtorg): Socio(ci,nombre,domicilio,cuota,ent)
{
    porcentaje=porc;
    fechaOtorgada=fechaOtorg;
}

Becado:: Becado (long int ci, String nombre, String domicilio, float cuota, int porc, Fecha fechaOtorg): Socio(ci,nombre,domicilio,cuota)
{
    porcentaje=porc;
    fechaOtorgada=fechaOtorg;
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

float Becado :: calcularCuotaTotal(int mes)
{
    float cuotaTotal=getCuota();
    if ( Fecha(28, 2, 2025) < fechaOtorgada )
        cuotaTotal=cuotaTotal*(1-(porcentaje/100.0));
    else
        cuotaTotal = cuotaTotal*(1 - ((porcentaje/2)/100.0));

    if  (mes==1||mes==2)
        cuotaTotal=cuotaTotal*0.70;

    return cuotaTotal;
}

void Becado :: mostrar()
{
    Socio :: mostrar();

    printf("Porcentaje Beca: %d", porcentaje);
    printf(" | ");

    printf("Fecha Otorgada: ");
    fechaOtorgada.imprimir();
}
