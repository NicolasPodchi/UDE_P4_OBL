#include <iostream>
#include "menu.h"

void mostrarMenuPrincipal (int &opcion)
{
    printf(":: MENU PRINCIPAL ::\n");
    printf("\n1 - Altas");
    printf("\n2 - Listados");
    printf("\n3 - Consultas");
    printf("\n\n0 - Salir");

    printf("\n\nSELECCIONE UNA OPCION: ");
    scanf("%d", &opcion);
}


void mostrarMenuAltas (int &opcion)
{
    printf(":: ALTAS ::");
    printf("\n1 - Crear entrenador");
    printf("\n2 - Crear socio");
    printf("\n\n0 - Volver");

    printf("\n\nSELECCIONE UNA OPCION: ");
    scanf("%d", &opcion);
}

void mostrarMenuListados (int &opcion)
{
    printf(":: LISTADOS ::\n");
    printf("\n1 - Listar entrenadores");
    printf("\n2 - Listar socios");
    printf("\n\n0 - Volver");

    printf("\n\nSELECCIONE UNA OPCION: ");
    scanf("%d", &opcion);
}

void mostrarMenuConsultas (int &opcion)
{
    printf(":: CONSULTAS ::");
    printf("\n1 - Consultar socio");
    printf("\n2 - Calcular cuota mensual para socio");
    printf("\n3 - Calcular total e ingresos por mes");
    printf("\n4 - Cantidad de becados por fecha");
    printf("\n5 - Cantidad de entrenadores por anio y promedio de salarios");
    printf("\n6 - Socio con cuota mas alta por mes");
    printf("\n\n0 - Volver");

    printf("\n\nSELECCIONE UNA OPCION: ");
    scanf("%d", &opcion);
}

