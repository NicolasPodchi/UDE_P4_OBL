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


                    printf("Fecha que se otorga la beca:\n");
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
                    printf("\nSocio registrado con exito\n\n");
                    break;
                case YaExisteSocio:
                    printf("El socio que intenta registrar ya existe\n");
                    break;
                case NoExisteEntrenador:
                    printf("No existe un entrenador para la cedula ingresada\n");
                    break;
                case CuotaSocioNegativa:
                    printf("El valor de la cuota base no puede ser negativo\n");
                    break;
                case ExtraSocioComunNegativo:
                    printf("El valor de la cuota extra no puede ser negativo\n");
                    break;
                case PorcentajBecadoNegativo:
                    printf("El porcentaje de beca no puede ser negativo\n");
                    break;
                case FechaInvalida:
                    printf("La fecha ingresada no es valida\n");
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
            printf("\n");
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
            printf("\n\n");

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
    tipoError error = ok;

    int opcionConsultas;

    long int cedula;
    Socio * socio;

    do
    {
        system("cls");
        mostrarMenuConsultas(opcionConsultas);
        system("cls");

        switch(opcionConsultas)
        {
        case 1:
            printf(":: CONSULTAR SOCIO ::\n\n");/*consultar un socio en detalle*/

            error = ok;

            printf("\n\nIngrese los datos del nuevo socio:\n\n");

            printf("Cedula: ");
            scanf("%ld", &cedula);

            socio = capaLogica.devolverSocio(cedula, error);
            socio -> mostrar();

            system("pause");
            break;
        case 2:
        {
            printf("\n:: CALCULAR CUOTA MENSUAL PARA SOCIO ::\n\n");

            long int cedula;
            int mes;

            printf("INGRESE LA CEDULA DEL SOCIO: ");
            scanf("%ld", &cedula);

            printf("INGRESE EL MES (1-12): ");
            scanf("%d", &mes);

            Socio* socio = capaLogica.devolverSocio(cedula, error);

            if (socio == NULL)
            {
                printf("NO SE ENCONTRO SOCIO CON ESA CEDULA.\n");
            }
            else
            {
                float cuota = socio->calcularCuotaTotal(mes);
                printf("\nLA CUOTA DEL MES %d PARA EL SOCIO %ld ES: %.2f\n\n", mes, cedula, cuota);
            }

            system("pause");
        }
        break;
        system("pause");
        break;
        case 3:
        {
            printf(":: CALCULAR TOTAL DE INGRESOS POR MES ::\n\n");/*Calcular monto total por mes*/
            //faus
            int mes;
            printf("Ingrese un mes (1 al 12): ");
            scanf("%d", &mes);
            float total = capaLogica.calcularCuotasTodos(mes);
            printf("\nEl monto total del mes %d es de: %.2f\n\n", mes, total);
            system("pause");
            break;
        }
        case 4:
            printf(":: CANTIDAD DE BECADOS POR FECHA ::\n\n");/*Contar cantidad becados con fechaOtorgada mayor a una fecha dada*/
            //pochi

            system("pause");
            break;
      case 5:
{
    printf(":: CANTIDAD DE ENTRENADORES POR FECHA Y PROMEDIO DE SALARIOS ::\n\n");

    int anio;
    printf("INGRESE EL ANIO: ");
    scanf("%d", &anio);

    IterPersonas iter;
    capaLogica.listarEntrenadores(iter);

    int contador = 0;
    float sumaSalarios = 0;

    while(iter.hayMasPersonas() == TRUE)
    {
        Persona * p = iter.proximaPersona();
        Entrenador * ent = (Entrenador*) p;

        if(ent->getAnio() > anio)
        {
            contador++;
            sumaSalarios = sumaSalarios+ent->getSalario();
        }
    }

    if(contador == 0)
    {
        printf("\nNO HAY ENTRENADORES QUE HAYAN INGRESADO LUEGO DEL ANIO %d.\n", anio);
    }
    else
    {
        float promedio = sumaSalarios / contador;
        printf("\nCANTIDAD DE ENTRENADORES: %d\n", contador);
        printf("PROMEDIO DE SALARIOS: %.2f\n", promedio);
    }

    system("pause");
    break;
}
        case 6:
        {
            printf(":: SOCIO CON CUOTA MAS ALTA POR MES ::\n\n");/*Dado un mes, consultar en detalle el socio con la cuota mas alta*/
            //faus
            Socio * mayor = NULL;
            tipoError error = ok;
            int mes;
            printf("Ingrese un mes (1 al 12): ");
            scanf("%d", &mes);
            printf("\n");
            capaLogica.socioCuotaMayor(mes, error, mayor);
            switch(error)
            {
            case NoHaySocios:
                printf("\nNo existen socios \n");
                break;
            case ok:
                mayor->mostrar();
            }
            printf("\n\n");
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
