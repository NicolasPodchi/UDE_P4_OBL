#ifndef ITERPERSONAS_H_INCLUDED
#define ITERPERSONAS_H_INCLUDED
#include "Persona.h"
#include "Boolean.h"

class IterPersonas {
private:
    struct Nodo {
        Persona * info;
        Nodo * sig;
    };
    Nodo * prim; Nodo * ult; Nodo * actual;

public:
    IterPersonas();
    void insertar (Persona *);
    Boolean hayMasPersonas();
    Persona * proximaPersona();
    ~IterPersonas();
};

#endif // ITERPERSONAS_H_INCLUDED
