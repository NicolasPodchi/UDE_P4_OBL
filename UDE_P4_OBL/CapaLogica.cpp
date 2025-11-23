#include "CapaLogica.h"

CapaLogica :: CapaLogica(): diccSocios(), diccEntrenadores()
{

}

void CapaLogica :: registrarEntrenador(Entrenador e, tipoError &error)
{
    if(diccEntrenadores.member(e.getCedula()))
    {
        error = YaExisteEntrenador;
    }
    else
    {
        if(diccSocios.member(e.getCedula()))
        {
            error = YaExisteSocio;
        }
        else
        {
            diccEntrenadores.Insert(e);
            error = ok;
        }
    }
}

void CapaLogica :: registrarSocio(Socio * nuevoSocio, long int cedulaEntrenador, tipoError &error)
{
    if(diccSocios.member(nuevoSocio -> getCedula()) == TRUE)
    {
        error = YaExisteSocio;
    }
    else if(diccEntrenadores.member(cedulaEntrenador) == FALSE) //AGREGAR CONTROL DE QUE SOCIO NO EXISTA COMO ENTRENADOR
    {
        error = NoExisteEntrenador;
    }
    else if(nuevoSocio -> getCuota() < 0)
    {
        error = CuotaSocioNegativa;
    }

    if(error == ok)
    {
        if(nuevoSocio->tipoSocio() == "comun")
        {
            if(((Comun *)nuevoSocio) -> getExtra() < 0)
            {
                error = ExtraSocioComunNegativo;
            }
        }
        else
        {
            if(((Becado *)nuevoSocio) -> getPorcentaje() < 0)
            {
                error = PorcentajBecadoNegativo;
            }
            else if((((Becado *)nuevoSocio) -> getFechaOtorgada()).esValida() == FALSE)
            {
                error = FechaInvalida;
            }
        }
    }

    if(error == ok)
    {
        diccSocios.Insert(nuevoSocio);
    }
}

IterPersonas CapaLogica :: listarEntrenadores(tipoError & )
{
}

void CapaLogica :: listarSocios(IterPersonas & iter)
{
    diccSocios.listarSocios(iter);
}

Socio * CapaLogica :: devolverSocio(long int, tipoError &)
{
}

float CapaLogica :: calcularCuotaSocio(int, tipoError &) {}
float CapaLogica :: calcularCuotasTodos(int) {}
int CapaLogica :: cuantosBecadosDesdeFecha(Fecha) {}
void CapaLogica :: cuantosEntrenadoresYPromedioSalario(Fecha, int &, float &) {}
Socio * CapaLogica :: socioCuotaMayor(int, tipoError &) {}
