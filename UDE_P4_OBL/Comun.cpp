#include "Comun.h"

//virtual float getCuota();
//    virtual String tipoSocio();
//    Comun:: Comun ()
//    {
//
//    }
    Comun:: Comun (long int ci, String nombre,String domicilio , float cuota, Entrenador ent,float extra): Socio(ci,nombre,domicilio,cuota,ent)
    {
        Extra=extra;
    }
    float Comun::  getExtra ()
    {
        return Extra;
    }
