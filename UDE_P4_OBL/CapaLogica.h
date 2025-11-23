#ifndef CAPALOGICA_H_INCLUDED
#define CAPALOGICA_H_INCLUDED

#include "tipoError.h"
#include "Fecha.h"
#include "Socios.h"
#include "Comun.h"
#include "Becado.h"
#include "Entrenadores.h"

class CapaLogica
{
private:
    Socios diccSocios;
    Entrenadores diccEntrenadores;

public:
    CapaLogica();
    void registrarEntrenador(Entrenador, tipoError &);
    void registrarSocio(Socio *, long int cedulaEntrenador, tipoError &);
    IterPersonas listarEntrenadores(tipoError & );
    void listarSocios(IterPersonas &);
    Socio * devolverSocio(long int, tipoError &);
    float calcularCuotaSocio(int, tipoError &);
    float calcularCuotasTodos(int);
    int cuantosBecadosDesdeFecha(Fecha);
    void cuantosEntrenadoresYPromedioSalario(Fecha, int &, float &);
    Socio * socioCuotaMayor(int, tipoError &);
};


#endif // CAPALOGICA_H_INCLUDED
