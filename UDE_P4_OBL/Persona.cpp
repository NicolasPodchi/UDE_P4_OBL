#include "Persona.h"

Persona:: Persona ()
{

}

Persona:: Persona (long int c, String n)
{
    cedula=c;
    nombre=n;
}

Persona :: Persona(const Persona &p)
{
    cedula = p.cedula;
    nombre = p.nombre;
}

String Persona ::  getNombre ()
{
    return nombre;
}

long int Persona :: getCedula()
{
    return cedula;
}

void Persona :: mostrar()
{
    printf("Cedula: %ld", cedula);
    printf(" | ");

    printf("Nombre: ");
    nombre.print();
    printf(" | ");
}

Persona :: ~Persona()
{

}
