#include <iostream>

#include "Menu.h"
#include "CapaLogica.h"

using namespace std;

void procesarAltas(CapaLogica capaLogica)
{
    int opcionAltas;

    long int cedula;
    int anio;
    String nombre;
    float cuotaBase;
    float salario;
    String domicilio;
    long int cedulaEntrenador;

    do
    {
        system("cls");
        mostrarMenuAltas(opcionAltas);
        system("cls");

        switch(opcionAltas)
        {
        case 1:
            printf(":: CREAR ENTRENADOR ::\n\n");
            printf("Ingrese los datos del nuevo entrenador:\n\n");

            printf("Cedula: ");
            scanf("%ld", &cedula);

            printf("\nNombre: ");
            nombre.scan();

            printf("\nAnio comienzo: ");
            scanf("%d", &anio);

            printf("\nSalario: ");
            scanf("%f", &salario);

            system("pause");
            break;
        case 2:
            printf(":: CREAR SOCIO ::\n\n");

            printf("Ingrese los datos del nuevo socio:");

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
    while (opcionAltas != 0);
}

void procesarListados(CapaLogica capaLogica)
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

            printf(":: LISTADO DE ENTRENADORES ::\n\n");

            system("pause");
            break;
        case 2:
            printf(":: LISTADO DE SOCIOS ::\n\n");

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
    while (opcionListados != 0);
}

void procesarConsultas(CapaLogica capaLogica)
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
