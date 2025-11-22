#include "Persona.h"
class Entrenador: public Persona
{
private:
    float Salario;
    int AnioComienzo;
public:
        Entrenador();
        Entrenador(long int, String,float,int);
        Entrenador (const Entrenador &);
        float getSalario();
        int GetAnio();
};
