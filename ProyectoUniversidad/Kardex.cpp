#include "Kardex.h"
#include "Estudiante.h"
#include <sstream>
#include <iomanip>

using std::setw;
using std::left;
using std::right;
using std::string;
using std::endl;

string Kardex::ToString() const
{
    std::ostringstream out;
    out << "Matricula" << estudiante->GetMatricula() << endl;
    out << setw(50) << left << "Nombre" << estudiante->GetNombre() << endl;
    out << "Carrera" << estudiante->GetCarrera() << endl;
    
    out << "---------------------------------------------------------------------------" << endl;
    out << "Clave ";
    out << setw(50) << "Nombre";
    out << " Valor Creditos" << endl;
    out << "---------------------------------------------------------------------------" << endl;
    for(Calificacion cal : calificaciones)
    {
        out << cal.ToString() << endl;
    }   
    out << "---------------------------------------------------------------------------" << endl;
    out << "Promedio: " << std::setprecision(2) << promedio << endl;
    out << "Creditos: " << creditos << endl;
    return out.str();
}

void Kardex::RegistrarCalificacion(Calificacion calif)
{
    calificaciones.push_back(calif);

    // Actualizar creditos y promedio

    if (calif.GetValor() >= 70)
    {
        creditos += calif.GetMateria()->GetCreditos();
    }

    // Obtener el promedio

    double sc = 0;
    for (Calificacion &cal : calificaciones)
    {
        sc += cal.GetValor();
    }
    promedio = sc / calificaciones.size();
}

