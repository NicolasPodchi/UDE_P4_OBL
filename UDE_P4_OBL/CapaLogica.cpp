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
    else if(diccEntrenadores.member(nuevoSocio -> getCedula()) == TRUE)
    {
        error = ExisteSocioComoEntrenador;
    }
    else if(diccEntrenadores.member(cedulaEntrenador) == FALSE)
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
            int coso = ((Becado *)nuevoSocio) -> getPorcentaje() ;
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
        Entrenador * entrenadorAsignado = diccEntrenadores.Find(cedulaEntrenador);
        nuevoSocio -> setEntrenador(entrenadorAsignado);

        diccSocios.Insert(nuevoSocio);
    }
}

void CapaLogica :: listarEntrenadores(IterPersonas & iter)
{
    diccEntrenadores.listarEntrenadores(iter);
}

void CapaLogica :: listarSocios(IterPersonas & iter)
{
    diccSocios.listarSocios(iter);
}

void CapaLogica :: devolverSocio(long int cedula, tipoError &error, Socio * &s)
{
    if((Boolean)diccSocios.member(cedula) == FALSE)
    {
        error = NoExisteSocio;
    }
    else
    {
        s = diccSocios.Find(cedula);
        error = ok;
    }
}

float CapaLogica :: calcularCuotaSocio(int, tipoError &) {}


float CapaLogica :: calcularCuotasTodos(int mes)
{
    return diccSocios.montoTotalCuotasMes(mes);
}

int CapaLogica :: contarBecadosPorFecha(Fecha f)
{
    return diccSocios.contarBecadosPorFecha(f);
}

void CapaLogica :: cuantosEntrenadoresYPromedioSalario(Fecha, int &, float &) {}

void CapaLogica :: socioCuotaMayor(int mes, tipoError &error, Socio * &s)
{
    if(diccSocios.Empty() == TRUE)
    {
        error = NoHaySocios;
    }
    else
    {
        s = diccSocios.socioCuotaMayor(mes);
        error = ok;
    }
}

void CapaLogica :: cuantosEntrenadoresYPromedioSalario(int Anio, int &cant, float &promedio)
{
    diccEntrenadores.recorrerEntrenadorAnioYpromedio(Anio,cant,promedio);
}
