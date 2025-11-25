#pragma once
#include "Persona.h"

class Entrenador: public Persona
{

private:
    float salario;
    int anioComienzo;

public:
    Entrenador();
    Entrenador(long int, String,float,int);
    Entrenador (const Entrenador &);
    float getSalario();
    int getAnio();

    void mostrarBasico();
    void mostrar();
};
