#include <iostream>
#include "Persona.h"
#include <string.h>

using std::cout;
using std::endl;

void Persona::Comer()
{
    cout << "Nom nom nom..." << endl;
}

void Persona::Saludar() const
{
    cout << "Hola, soy " << nombre;
    cout << " y tengo " << edad << " anios" << endl;
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
    if (nombre != nullptr)
    {
        cout << "Ejecutando destructor de " << nombre << endl;
        free(nombre);
    }
}

Persona::Persona()
{
    edad = 20;
    nombre = (char *)malloc(7);
    nombre[strlen(nombre)] = '/0';
    strncpy(nombre, "Sosimo", 6);
}

void Persona::SetNombre(const char *nuevo_nombre)
{
    // Liberar la memoria que se reservó para el nombre
    free(nombre);

    // Reservar memoria para el nuevo nombre
    nombre = (char *)malloc(strlen(nuevo_nombre));

    // Copiar el nombre
    strncpy(nombre, nuevo_nombre, strlen(nuevo_nombre));
    nombre[strlen(nuevo_nombre)] = '\0';
}

char *Persona::GetNombre()
{
    return nombre;
}

int Persona::GetEdad()
{
    {
        return edad;
    }
}
