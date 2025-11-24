#ifndef TIPOERROR_H_INCLUDED
#define TIPOERROR_H_INCLUDED
#include "String.h"

typedef enum tipoError
{
    ok,
    YaExisteSocio,
    YaExisteEntrenador,
    NoExisteSocio,
    SocioNoBecado,
    NoHaySocios,
    CuotaSocioNegativa,
    ExtraSocioComunNegativo,
    PorcentajBecadoNegativo,
    FechaInvalida,
    NoExisteEntrenador
};
#endif // TIPOERROR_H_INCLUDED
