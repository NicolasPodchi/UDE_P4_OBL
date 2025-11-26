#include"Entrenador.h"

Entrenador :: Entrenador()
{

}

Entrenador:: Entrenador(long int c, String n,float s,int a):Persona(c,n)
{
    salario=s;
    anioComienzo=a;
}

Entrenador::Entrenador(const Entrenador &ent): Persona(ent)   // <--- LLAMA AL CONSTRUCTOR DE COPIA DE PERSONA
{
    salario = ent.salario;
    anioComienzo = ent.anioComienzo;
}

float Entrenador:: getSalario()
{
    return salario;
}

int Entrenador :: getAnio()
{
    return anioComienzo;
}

void Entrenador :: mostrar()
{
    Persona :: mostrar();

    printf("Salario: %.2f", salario);
    printf(" | ");

    printf("Anio ingreso: %d", anioComienzo);

}

void Entrenador :: mostrarBasico() //borrar dejarlo en socio nomas
{
}
