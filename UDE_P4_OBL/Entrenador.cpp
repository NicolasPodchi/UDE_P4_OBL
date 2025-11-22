#include"Entrenador.h"

Entrenador:: Entrenador(long int c, String n,float s,int a):Persona(c,n)
{
    Salario=s;
    AnioComienzo=a;
}
Entrenador::Entrenador(const Entrenador &ent): Persona(ent)   // <--- LLAMA AL CONSTRUCTOR DE COPIA DE PERSONA
{
    Salario = ent.Salario;
    AnioComienzo = ent.AnioComienzo;
}

float Entrenador:: getSalario()
{
    return Salario;
}
int Entrenador :: GetAnio()
{
    return AnioComienzo;
}
Entrenador :: Entrenador()
{

}
