#include "Persona.h"

 Persona:: Persona (long int n, String s)
{
    CI=n;
    Nombre=s;
}
     String Persona::  getNombre ()
     {
         return Nombre;
     }
     long int Persona:: getCedula()
     {
         return CI;
     }
Persona :: Persona(const Persona &p)
{
    CI=p.CI;
    Nombre=p.Nombre;
}
Persona:: Persona ()
{

}
