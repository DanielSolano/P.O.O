#include "Estudiante.h"
#include <sstream>
#include <iomanip>
using std::setw;
using std::left;
using std::right;
using std::endl;

Estudiante::Estudiante(int matricula, string nombre, string carrera)
{
    this->matricula = matricula;
    this->nombre = nombre;
    this->carrera = carrera;
    kardex = Kardex(this);
}

string Estudiante::ToString() const
{
    std::ostringstream out;
    out <<setw(8) << left << matricula  << matricula << " ";
    out << setw(50) << left << nombre << " ";
    out << carrera << " ";
    return out.str();
}
