#include "Profesionista.h"
#include <iostream>

using std::cout;

using std::endl;

Profesionista::Profesionista()
    : Persona("Nicolas", 25), cedula("De Tepito"), experiencia(3) // Constructor clase padre, y atributos extra
{
}

Profesionista::Profesionista(string nombre, string cedula, int edad, int experiencia)
    : Persona(nombre.c_str(), edad) // Constructor clase padre
{
    this->cedula = cedula;
    this->experiencia = experiencia;   
}

void Profesionista::Trabajar()
{
    cout << "Mi primera chamba ... " << endl;
}

void Profesionista::Saludar() const
{
    cout << "Hola, soy el profesionista " << nombre << ", tengo " << experiencia << " anios de experiencia y mi cedula es " << cedula << endl;
}