#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "String.h"

class Persona
{
private:
    long int cedula;
    String nombre;

public :
    Persona ();
    Persona (long int, String);
    Persona (const Persona &);
    String getNombre();
    long int getCedula();
};

#endif // PERSONA_H_INCLUDED
