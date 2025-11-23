#include"Socio.h"

Socio::Socio (long int cedula, String nombre, String domicilio, float cuota, Entrenador entrenador): Persona(cedula, nombre)
{
    domicilio=domicilio;
    cuotaBase=cuota;
    entrenador=entrenador;
}

float Socio ::  getCuota()
{
    return cuotaBase;
}

String  Socio :: getDomicilio()
{
    return domicilio;
}

Entrenador * Socio :: getEntrenador()
{
    return entrenador;
}

float Socio ::  calcularCuotaTotal(int mes)
{
    return 0;
}

void Socio :: mostrar()
{
}
