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
    void listarEntrenadores(IterPersonas &);
    void listarSocios(IterPersonas &);
    void devolverSocio(long int, tipoError &, Socio * &);
    float calcularCuotaSocio(int, tipoError &);
    float calcularCuotasTodos(int);
    int contarBecadosPorFecha(Fecha);
    void cuantosEntrenadoresYPromedioSalario(Fecha, int &, float &);
    void socioCuotaMayor(int, tipoError &, Socio * &);
    void cuantosEntrenadoresYPromedioSalario(int, int &, float &);
};


#endif // CAPALOGICA_H_INCLUDED
