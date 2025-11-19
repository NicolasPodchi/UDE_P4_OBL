#include "String.h"
#include <string.h>
#include <iostream>

using namespace std;

String :: String ()
{
    cadena = new char[1];
    cadena[0] = '\0';
}


String :: String (char * cad)
{
    int largo = strlen(cad);
    cadena = new char[largo + 1];
    strcpy(cadena,cad);

}


String :: String (const String &otro)
{
    int largo = strlen(otro.cadena);
    cadena = new char[largo + 1];
    strcpy(cadena,otro.cadena);
}

String :: ~String ()
{
    delete [] cadena;
}
bool String :: operator== (String otro)
{
    return (strcmp(cadena, otro.cadena) == 0);
}

String String :: operator= (const String &otro)
{
    if (this != & otro)
    {
        delete [] cadena;
        int largo = strlen(otro.cadena);
        cadena = new char [largo + 1];
        strcpy(cadena, otro.cadena);
    }
    return (*this);
}

bool String :: operator< (String otro)
{
    return (strcmp(cadena,otro.cadena) < 0);
}

String String :: operator+(String otro)
{
    int largo = strlen(cadena) + strlen(otro.cadena);
    String concatenados;
    delete[] concatenados.cadena;
    concatenados.cadena = new char [largo + 1];
    strcpy(concatenados.cadena, cadena);
    strcat(concatenados.cadena,otro.cadena);
    return (concatenados);
}

void String :: scan()
{
    char aux [MAX];
    char c = cin.get();
    int i = 0;
    while(i<MAX && c!='\n')
    {
        aux[i] = c;
        c = cin.get();
        i++;
    }
    aux[i] = '\0';
    cadena = new char[i];
    strcpy(cadena,aux);

}
void String :: print()
{
    cout << cadena;
}
