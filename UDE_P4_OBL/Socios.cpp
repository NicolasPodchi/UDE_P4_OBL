#include "Socios.h"

void Socios :: destruirArbol (Nodo * &a)
{
    if(a!=NULL)
    {
        destruirArbol(a->hIzq);
        destruirArbol(a->hDer);
        delete a->info;
        delete a;
        a = NULL;
    }
}

Boolean Socios :: perteneceArbol (Nodo * a, long int ci)
{
    Boolean encontre = FALSE;
    while (!encontre && a != NULL)
    {
        long int cedula = a->info ->getCedula();
        if( cedula== ci)
            encontre = TRUE;
        else
        {
            if(ci < cedula)
                a = a->hIzq;
            else
                a = a->hDer;
        }
    }
    return encontre;
}

void Socios :: insertarEnArbol (Nodo * &a, Socio * s)
{
    if(a==NULL)
    {
        a = new Nodo;
        a -> info = s;
        a ->hIzq = NULL;
        a -> hDer = NULL;
    }
    else
    {
        if(s -> getCedula() < a->info->getCedula())
            insertarEnArbol(a->hIzq,s);
        else
            insertarEnArbol(a->hDer,s);
    }
}

Socio * Socios :: obtenerEnArbol (Nodo * a, long int ci)
{
    while (a->info->getCedula() != ci)
    {
        if(ci < a->info->getCedula())
            a = a -> hIzq;
        else
            a = a->hDer;
    }
    return a->info;
}

void Socios :: cargarIterador (Nodo * a, IterPersonas &iter)
{
    if(a!=NULL)
    {
        cargarIterador(a->hIzq,iter);
        iter.insertar(a->info);
        cargarIterador(a->hDer, iter);
    }
}

Socios :: Socios ()
{
    ABB = NULL;

}

Socios :: ~Socios ()
{
    destruirArbol(ABB);
}

Boolean Socios :: member (long int ci)
{
    return perteneceArbol(ABB, ci);
}

void Socios :: Insert(Socio * s)
{
    insertarEnArbol(ABB,s);

}

Socio * Socios ::  Find (long int ci)
{
    return obtenerEnArbol(ABB, ci);
}

void Socios :: listarSocios (IterPersonas &iter)
{
    cargarIterador(ABB, iter);

}

Boolean Socios :: Empty ()
{
    return (Boolean)(ABB == NULL);
}

float Socios :: CuotasTotalesEnArbol(Nodo * a, int mes)
{
    float totalNodo = 0.0;
    float totalIzq = 0.0;
    float totalDer = 0.0;
    if(a != NULL)
    {
        totalIzq =CuotasTotalesEnArbol(a->hIzq, mes);
        totalNodo = (a->info)->calcularCuotaTotal(mes);
        totalDer = CuotasTotalesEnArbol(a->hDer, mes);
    }
    return totalNodo + totalIzq + totalDer;
}

float Socios :: montoTotalCuotasMes (int mes)
{
    return CuotasTotalesEnArbol(ABB, mes);
}

Socio * Socios :: socioMayorCuotaEnArbol (Nodo * a, int mes)
{
    Socio * socioMayor = a->info;
    float cuotaMayor = a->info->calcularCuotaTotal(mes);

    if(a->hIzq != NULL)
    {
        Socio * socioIzq = socioMayorCuotaEnArbol(a->hIzq, mes);
        if(socioIzq->calcularCuotaTotal(mes) > cuotaMayor)
        {
            cuotaMayor = socioIzq->calcularCuotaTotal(mes);
            socioMayor = socioIzq;
        }

    }

    if(a->hDer != NULL)
    {
        Socio * socioDer = socioMayorCuotaEnArbol(a->hDer, mes);
        if(socioDer->calcularCuotaTotal(mes) > cuotaMayor)
        {
            cuotaMayor = socioDer->calcularCuotaTotal(mes);
            socioMayor = socioDer;
        }

    }

    return socioMayor;
}

Socio * Socios :: socioCuotaMayor (int mes)
{
    return socioMayorCuotaEnArbol(ABB, mes);

}

int Socios :: cuantosBecadosDesdeFecha(Nodo * a, Fecha f)
{
    int cantidadBecados = 0;

    if(a != NULL)
    {
        Socio * socioActual = a -> info;
        if(socioActual -> tipoSocio() == "becado")
        {
            Fecha fechaBeca = ((Becado *)socioActual) -> getFechaOtorgada();
            if(f < fechaBeca)
            {
                cantidadBecados++;
            }
        }

        if(a->hIzq != NULL)
        {
            cantidadBecados += cuantosBecadosDesdeFecha(a -> hIzq, f);
        }

        if(a->hDer != NULL)
        {
            cantidadBecados += cuantosBecadosDesdeFecha(a -> hDer, f);
        }

    }
        return cantidadBecados;
}

int Socios :: contarBecadosPorFecha(Fecha f)
{
    return cuantosBecadosDesdeFecha(ABB, f);
}
