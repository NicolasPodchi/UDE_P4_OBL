#include "CapaLogica.h"

CapaLogica :: CapaLogica(): diccSocios(), diccEntrenadores()
{

}

void CapaLogica :: registrarEntrenador(Entrenador e, tipoError &error)
{

}

void registrarSocio(Socio *, tipoError &);
IterPersonas listarEntrenadores(tipoError & );
IterPersonas listarSocios();
Socio * devolverSocio(long int, tipoError &);
float calcularCuotaSocio(int, tipoError &);
float calcularCuotasTodos(int);
int cuantosBecadosDesdeFecha(Fecha);
void cuantosEntrenadoresYPromedioSalario(Fecha, int &, float &);
Socio * socioCuotaMayor(int, tipoError &);
