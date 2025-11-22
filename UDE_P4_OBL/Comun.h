#ifndef COMUN_H_INCLUDED
#define COMUN_H_INCLUDED
#include "Socio.h"

class Comun: public Socio
{
private:
    float Extra;

public:
//    virtual float getCuota();
//    virtual String tipoSocio();
    Comun ();
    Comun (long int, String,String , float,Entrenador, float);
    float getExtra ();



};
#endif // COMUN_H_INCLUDED
