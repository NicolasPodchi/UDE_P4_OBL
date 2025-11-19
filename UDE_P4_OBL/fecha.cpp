#include "fecha.h"
bool Fecha :: esBisiesto()
{
    return ((anio % 4 == 0 && anio % 100 != 0 ) || anio % 400 == 0);
}

void Fecha :: incrementar ()
{
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(dia == 31)
        {
            dia = 1;
            if(mes == 12)
            {
                mes = 1;
                anio ++;
            }
            else
                mes++;
        }
        else
            dia ++;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        if(dia == 31)
        {
            dia = 1;
            mes ++;
        }
        else
            dia ++;
        break;

    case 2:
        if(esBisiesto())
        {
            if(dia == 29)
            {
                dia = 1;
                mes++;
            }
            else
            {
                dia++;
            }
        }
        else
        {
            if(dia == 28)
            {
                dia = 1;
                mes++;
            }
            else
                dia++;
        }
    }
}

Fecha :: Fecha ()
{
    dia = 1;
    mes = 1;
    anio = 1900;
}

Fecha :: Fecha (int d, int m, int a)
{
    dia = d;
    mes = m;
    anio = a;
}

Fecha :: Fecha (const Fecha &otra)
{
    dia = otra.dia;
    mes = otra.mes;
    anio = otra.anio;

}

int Fecha :: getDia ()
{
    return dia;
}

int Fecha :: getMes ()
{
    return mes;
}

int Fecha :: getAnio ()
{
    return anio;
}

bool Fecha::operator<(Fecha f)
{
    bool menor = false;

    if (anio < f.anio)
    {
        menor = true;
    }
    else if (anio == f.anio)
    {
        if (mes < f.mes)
        {
            menor = true;
        }
        else if (mes == f.mes)
        {
            if (dia < f.dia)
            {
                menor = true;
            }
        }
    }

    return menor;
}


bool Fecha :: operator== (Fecha f)
{
    return (f.anio == anio && f.mes == mes && f.dia == dia);
}

Fecha Fecha :: operator++ ()
{
    this->incrementar();
    return (*this);
}

Fecha Fecha :: operator++ (int x)
{
    Fecha resu = *this;
    this->incrementar();
    return resu;
}

Fecha Fecha :: operator+ (int d)
{
    for(int i = 0; i < d; i++)
    {
        (*this)++;
    }
    return (*this);
}

int Fecha :: operator- (Fecha f) //se rompe si las fechas no son validas
{
    int cant = 0;
    int signo = 1;
    if(*this < f)
    {
        for(Fecha aux = (*this); aux < f; aux++)
        {
            cant++;
        }
    }
    else
    {
        signo = -1;
        for(Fecha aux = f; aux < *this; aux++)
        {
            cant++;
        }
    }
    return (cant * signo);
}

bool Fecha :: esValida ()
{
    bool valido= true;
    switch(mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(dia<1||dia>31)
            valido = false;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(dia<1||dia>30)
            valido = false;
        break;
    case 2:
        if(esBisiesto())
        {
            if(dia<1||dia>29)
                valido = false;
        }
        else
        {
            if(dia<1||dia>28)
                valido = false;
        }
    default:
        valido = false;
    }
    return valido;
}
