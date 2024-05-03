#include "Ingeniero.h"


Ingeniero::Ingeniero(string nombre, string cedula, int edad, int experiencia)
    : Profesionista(nombre, cedula, edad, experiencia) // Constructor clase padre
{

}

void Ingeniero::Trabajar()
{
    Profesionista::Trabajar(); // Aplicamos el metodo trabajar de la clase padre
    ResolverProblemas();
}

void Ingeniero::ResolverProblemas()
{
    cout << "Resolviendo problemas con creatividad e ingenio... " << endl;
}

