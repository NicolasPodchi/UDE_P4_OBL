#include"Socio.h"

Socio::Socio (long int cedula, String nombre, String domicilio, float cuota, Entrenador * entrenadorAsignado): Persona(cedula, nombre)
{
    domicilio=domicilio;
    cuotaBase=cuota;
    entrenador=entrenadorAsignado;
}

Socio::Socio (long int cedula, String nombre, String domicilioSocio, float cuota): Persona(cedula, nombre)
{
    domicilio=domicilioSocio;
    cuotaBase=cuota;
    entrenador=NULL;
}

Socio::~Socio()
{
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

void Socio :: setEntrenador(Entrenador * entrenadorAsignar)
{
    this -> entrenador = entrenadorAsignar;
}

float Socio ::  calcularCuotaTotal(int mes)
{
    return 0;
}

void Socio :: mostrarBasico()
{
    Persona :: mostrar();

    printf("Tipo: ");
    tipoSocio().print();
}

void Socio :: mostrar()
{
    Persona :: mostrar();

    printf("Domicilio: ");
    domicilio.print();
    printf(" | ");

    printf("Cuota Base: %f", cuotaBase);
    printf(" | ");

    printf("Entrenador: ");
    entrenador -> mostrar();
    printf(" | ");
}
