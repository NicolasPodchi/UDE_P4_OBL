#include <iostream>

#include "Menu.h"
#include "CapaLogica.h"

using namespace std;

void procesarAltas(CapaLogica &capaLogica)
{
    tipoError error = ok;

    int opcionAltas;

    long int cedula;
    String nombre;
    float cuotaBase;
    float extra;
    float salario;
    String domicilio;
    long int cedulaEntrenador;
    int tipoSocio;
    int porcentaje;

    int dia;
    int mes;
    int anio;
    Fecha fechaOtorgada;

    Socio * nuevoSocio;
    Entrenador nuevoEntrenador;

    do
    {
        system("cls");
        mostrarMenuAltas(opcionAltas);
        system("cls");

        switch(opcionAltas)
        {
        case 1:
        {
            printf(":: CREAR ENTRENADOR ::");
            do
            {
                error = ok;

                printf("\n\nIngrese los datos del nuevo entrenador:\n\n");
                printf("Cedula: ");
                scanf("%ld", &cedula);

                printf("Nombre: ");
                nombre.scan();

                printf("Anio comienzo: ");
                scanf("%d", &anio);

                printf("Salario: ");
                scanf("%f", &salario);

                nuevoEntrenador = Entrenador(cedula, nombre, salario, anio);

                capaLogica.registrarEntrenador(nuevoEntrenador,error);

                switch(error)
                {
                case ok:
                    printf("\nEntrenador ingresado con exito\n\n");
                    break;

                case YaExisteSocio:
                    printf("La cedula ingresada ya esta registrada para un socio");
                    break;

                case YaExisteEntrenador:
                    printf("La cedula ingresada ya esta registrada para un entrenador");
                    break;
                }
            }
            while(error != ok);

            system("pause");
            break;
        }
        case 2:
        {
            printf(":: CREAR SOCIO ::");

            do
            {
                error = ok;

                printf("\n\nIngrese los datos del nuevo socio:\n\n");

                printf("Cedula: ");
                scanf("%ld", &cedula);

                printf("Nombre: ");
                nombre.scan();

                printf("Cuota: ");
                scanf("%f", &cuotaBase);

                printf("Domicilio: ");
                domicilio.scan();

                printf("Cedula Entrenador: ");
                scanf("%ld", &cedulaEntrenador);

                printf("Socio Comun (1: SI / 2: NO): ");
                scanf("%d", &tipoSocio);

                if(tipoSocio == 1) // comun
                {
                    printf("Extra: ");
                    scanf("%f", &extra);

                    nuevoSocio = new Comun(cedula, nombre, domicilio, cuotaBase, extra);
                }
                else // becado
                {
                    printf("Porcentaje Beca: ");
                    scanf("%d", &porcentaje);

                    printf("Dia: ");
                    scanf("%d", &dia);

                    printf("Mes: ");
                    scanf("%d", &mes);

                    printf("Anio: ");
                    scanf("%d", &anio);

                    Fecha fechaOtorgada(dia, mes, anio);

                    nuevoSocio = new Becado(cedula, nombre, domicilio, cuotaBase, porcentaje, fechaOtorgada);
                }

                capaLogica.registrarSocio(nuevoSocio, cedulaEntrenador, error);

                switch (error)
                {
                case ok:
                    printf("Socio registrado con éxito");
                    break;
                case YaExisteSocio:
                    printf("El socio que intenta registrar ya existe");
                    break;
                case NoExisteEntrenador:
                    printf("No existe un entrenador para la cedula ingresada");
                    break;
                case CuotaSocioNegativa:
                    printf("El valor de la cuota base no puede ser negativo");
                    break;
                case ExtraSocioComunNegativo:
                    printf("El valor de la cuota extra no puede ser negativo");
                    break;
                case PorcentajBecadoNegativo:
                    printf("El porcentaje de beca no puede ser negativo");
                    break;
                case FechaInvalida:
                    printf("La fecha ingresada no es válida");
                    break;
                }

            }
            while(error != ok);

            system("pause");
        }
        break;
        case 0:
            /*VOLVER*/
            break;
        default:
            system("cls");
            printf("OPCION INCORRECTA \n");
            system("pause");
            break;
        }
    }
    while (opcionAltas != 0);
}

void procesarListados(CapaLogica &capaLogica)
{
    int opcionListados;

    do
    {
        system("cls");
        mostrarMenuListados(opcionListados);
        system("cls");

        switch(opcionListados)
        {
        case 1:
        {
            IterPersonas iter;
            printf(":: LISTADO DE ENTRENADORES ::\n\n");
            capaLogica.listarEntrenadores(iter);

            while(iter.hayMasPersonas() == TRUE)
            {
                Persona * personaMostrar = iter.proximaPersona();
                personaMostrar -> mostrar();
            }
            system("pause");
            break;
        }
        case 2:
        {
            IterPersonas iter;
            printf(":: LISTADO DE SOCIOS ::\n\n");
            capaLogica.listarSocios(iter);

            while(iter.hayMasPersonas() == TRUE)
            {
                Persona * personaMostrar = iter.proximaPersona();
                personaMostrar -> mostrarBasico();
            }
            system("pause");

            break;
        }
        case 0:
            /*VOLVER*/
            break;
        default:
            system("cls");
            printf("OPCION INCORRECTA \n");
            system("pause");
            break;
        }
    }
    while (opcionListados != 0);
}

void procesarConsultas(CapaLogica &capaLogica)
{
    int opcionConsultas;

    do
    {
        system("cls");
        mostrarMenuConsultas(opcionConsultas);
        system("cls");

        switch(opcionConsultas)
        {
        case 1:
            printf(":: CONSULTAR SOCIO ::\n\n");/*consultar un socio en detalle*/


            system("pause");
            break;
        case 2:
            printf(":: CALCULAR CUOTA MENSUAL PARA SOCIO ::\n\n");/*consultar cuota mensual de un socio por cedula y mes*/


            system("pause");
            break;
        case 3:
            printf(":: CALCULAR TOTAL DE INGRESOS POR MES ::\n\n");/*Calcular monto total por mes*/


            system("pause");
            break;
        case 4:
            printf(":: CANTIDAD DE BECADOS POR FECHA ::\n\n");/*Contar cantidad becados con fechaOtorgada mayor a una fecha dada*/


            system("pause");
            break;
        case 5:
            printf(":: CANTIDAD DE ENTRENADORES POR FECHA Y PROMEDIO DE SALARIOS ::\n\n");/*Dado un anio, contar entrenadores que ingresaron luego de esa fecha y calcular el salario promedio de todos ellos.*/


            system("pause");
            break;
        case 6:
            printf(":: SOCIO CON CUOTA MAS ALTA POR MES ::\n\n");/*Dado un mes, consultar en detalle el socio con la cuota mas alta*/


            system("pause");
            break;
        case 0:
            /*VOLVER*/
            break;
        default:
            system("cls");
            printf("OPCION INCORRECTA \n");
            system("pause");
            break;
        }
    }
    while (opcionConsultas != 0);
}

int main()
{
    CapaLogica capaLogica;

    /*MENU*/
    int opcion;
    do
    {
        system("cls");
        mostrarMenuPrincipal(opcion); //REVISAR

        switch(opcion)
        {
        case 1:
            /*ALTAS*/
            procesarAltas(capaLogica);
            break;
        case 2:
            /*LISTADOS*/
            procesarListados(capaLogica);
            break;
        case 3:
            /*CONSULTAS*/
            procesarConsultas(capaLogica);
            break;
        case 0:
            /*SALIR*/
            break;
        default:
            system("cls");
            printf("OPCION INCORRECTA \n");
            system("pause");
            break;
        }
    }
    while (opcion != 0);

    return 0;
}
