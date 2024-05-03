#include "Universidad.h"
#include <iostream>
#include <iomanip>

using namespace std;

Estudiante *Universidad::RegistrarEstudiante(string nombre, string carrera)
{
    Estudiante *new_est = new Estudiante(++cont_mat, nombre, carrera);
    // Registramos al estudiante en el mapa de estudiantes
    estudiantes[cont_mat] = new_est;
    return new_est;
}

Materia *Universidad::RegistrarMateria(string nombre, int creditos, bool obligatoria, Materia::Etapa etapa)
{
    Materia *new_mat = new Materia(++cont_cm, nombre,
                                   creditos, obligatoria, etapa);
    // Registramos la materia en el mapa de materias
    materias.insert({cont_cm, new_mat});
    return new_mat;
}

void Universidad::RegistrarCalificacion(int matricula, int clave, int valor)
{
    // Primero buscamos al estudiante
    auto ite = estudiantes.find(matricula);
    // verificamosm si el estudiante existe
    if (ite == estudiantes.end())
        throw "Estudiante no existente";
    // Despues, buscamos la materia
    auto itm = materias.find(clave);
    if (itm == materias.end())
        throw "Materia no existente";
    // (*ite).second->GetKardex().RegistrarCalificacion(
    //     {valor, materias[clave]});
    (*ite).second->kardex.RegistrarCalificacion(
        {valor, materias[clave]});
}

void Universidad::ReporteEstudiantes() const

{
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Matricula" << setw(50) << left << "Nombre";
    cout << "Carrera" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (auto pe : estudiantes)
    {
        cout << pe.second->ToString() << endl;
    }
    cout << "-------------------------------------------------------------------------------" << endl;
}

void Universidad::ReporteMaterias() const
{
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Clave" << setw(50) << left << "Nombre";
    cout << "Creditos Tipo Etapa" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (auto pm : materias)
        cout << pm.second->ToString() << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
}

Universidad::~Universidad()
{
    for (auto pe : estudiantes)
        delete pe.second;
}

Kardex Universidad::GetKardex(int matricula)
{
    auto ite = estudiantes.find(matricula);
    if (ite == estudiantes.end())
        throw "Estudiante no existente";
    return (*ite).second;
}
