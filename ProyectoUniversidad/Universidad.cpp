#include "Universidad.h"
#include <iostream>
#include <iomanip>

using namespace std;

Estudiante *Universidad::RegistrarEstudiante(string nombre, string carrera)
{
    Estudiante *new_est = new Estudiante(++cont_mat, nombre, carrera);
    // Registramos al estudiante en el mapa de estudiantes
    estudiantes[cont_mat] = new_est;
}

Estudiante *Universidad::RegistrarMateria(string nombre, int creditos, bool obligatoria, Materia::Etapa etapa)
{
    Materia *new_mat = new Materia(++cont_cm, nombre, creditos, obligatoria, etapa);
    materias.insert({cont_cm, new_mat});
}

void Universidad::RegistrarCalificacion(int matricula, int valor, int clave, double calif)
{
    auto ite = estudiantes.find(matricula);
    if (ite == estudiantes.end())
        throw "Estudiante no existente";
    auto itm = materias.find(clave);
    if (itm == materias.end())
        throw "Materia no existente";
    (*ite).second->GetKardex().RegistrarCalificacion(
        {valor, materias[clave]});

}

void Universidad::ReporteEstudiantes() const
{
    cout <<"-------------------------------------------------------------------------------" << endl;
    cout << "Matricula" << setw(50) << left << "Nombre";
    cout << "Carrera" << endl;
    cout <<"-------------------------------------------------------------------------------" << endl;
    for (auto pe : estudiantes)
    {
        cout << pe.second->ToString() << endl;
    }
    cout <<"-------------------------------------------------------------------------------" << endl;
