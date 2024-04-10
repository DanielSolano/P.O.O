#include "Estudiante.h"

Estudiante::Estudiante(int matricula, string nombre, string carrera)
{
    this->matricula = matricula;
    this->nombre = nombre;
    this->carrera = carrera;
    Kardex = Kardex(this);
}