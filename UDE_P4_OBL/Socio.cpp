
#include"Socio.h"
    Socio::Socio (long int cedula, String nombre, String domicilio, float cuota, Entrenador Ent): Persona(cedula,nombre)
    {
        Domicilio=domicilio;
        CuotaBase=cuota;
        EntrenadorAsignado=Ent;
    }
 float Socio::  getCuota()
{
    return CuotaBase;
}
String  Socio ::getDomicilio()
{
    return Domicilio;
}
Entrenador Socio :: getEntrenador()
{
    return EntrenadorAsignado;
}
