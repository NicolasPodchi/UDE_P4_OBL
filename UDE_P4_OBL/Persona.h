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
    //TIPO PERSONA IMPLEMENTAR
    virtual void mostrarBasico() = 0;
    virtual void mostrar();
};

#endif // PERSONA_H_INCLUDED
