#pragma once
#include <string>
#include "Estudiante.h"
#include <map>

using std::map;
using std::string;

class Universidad
{
protected:
    string nombre;
    map<int, Estudiante *> estudiantes;
    map<int, Materia *> materias;
    int cont_mat = 33000;
    int cont_cm = 40000;

public:
    Universidad(string nombre = "WABECE") { this->nombre = nombre; }
    string GetNombre() const { return nombre; }
    Estudiante *RegistrarEstudiante(string nombre, string carrera);
    Materia* RegistrarMateria(string nombre, int creditos,
		bool obligatoria = true, Materia::Etapa etapa = Materia::BASICA);
    void RegistrarCalificacion(int matricula, int clave, int valor);
    void ReporteEstudiantes() const;
    void ReporteMaterias() const;
    ~Universidad();
    Kardex GetKardex(int matricula);
};
