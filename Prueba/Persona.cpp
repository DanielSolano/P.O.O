#include <iostream>
#include "Persona.h"
#include <string.h>

using std::cout;
using std::endl;

void Persona::Reir()
{
    cout << "Jajaja..." << endl;
}

void Persona::Comer()
{
    cout << "Nom nom nom..." << endl;
}

void Persona::Saludar()
{
    cout << "Hola, soy " << nombre;
    cout << " y tengo " << edad << " anios" << endl;
}

void Persona::HacerReir(int motivo)
{
    if ((motivo % 3) == 0)
    {
        Reir();
    }
    else
    {
        cout << "~_~" << endl;
    }
}

Persona::Persona(const char *el_nombre, int la_edad)
{
    // Reservar memoria para el nombre
    nombre = (char *)malloc(strlen(el_nombre));
    // Copiamos el nombre
    strncpy(nombre, el_nombre, strlen(el_nombre));
    nombre[strlen(el_nombre)] = '\0';
    edad = la_edad;
}

Persona::~Persona()
{
    cout << "Ejecutando destructor de " << nombre << endl;
    free(nombre);
}

Persona::Persona()
{
    edad = 20;
    nombre = (char *)malloc(7);
    nombre[strlen(nombre)] = '/0';
    strncpy(nombre, "Sosimo", 6);
}

Persona::Persona(const Persona &original)
{
    cout << "Ejecutando constructor de copia de" << original.nombre << endl;
    nombre = (char *)malloc(strlen(original.nombre));
    strncpy(nombre, original.nombre, strlen(original.nombre));
    nombre[strlen(original.nombre)] = '\0';
}
