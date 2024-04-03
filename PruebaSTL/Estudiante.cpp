#include "Estudiante.h"
#include <string>
Estudiante::Estudiante()
{
}

Estudiante::Estudiante(int matricula, string nombre, int puntuacion)
{
    this->nombre = nombre;
    this->matricula = matricula;
    this->puntuacion = puntuacion;
}

ostream &operator<<(ostream &out, const Estudiante &e)
{
    out << "Estudiante [" << e.GetMatricula() << "," << e.GetNombre() << "," << e.GetPuntuacion() << "]";
    return out;
}

bool operator<(const Estudiante &e1, const Estudiante &e2)
{
    return e1.GetNombre() < e2.GetNombre();
}
