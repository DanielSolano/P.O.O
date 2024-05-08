#include "IngenieroCivil.h"

using std::cout;

IngenieroCivil::IngenieroCivil(string nombre, string cedula, int edad, int experiencia) : Ingeniero(nombre, cedula, edad, experiencia)
{
}

void IngenieroCivil::Construir()
{
    cout << "Construyendo... meneando la cuchara con estilo" << endl;
}

void IngenieroCivil::ResolverProblemas()
{
    Construir();
}
