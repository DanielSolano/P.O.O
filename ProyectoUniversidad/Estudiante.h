#pragma once
#include "Kardex.h"
#include <string>
using std::string;

class Estudiante
{
    protected:
        int matricula;
        string nombre;
        string carrera;
        Kardex kardex;
    public:
        Estudiante(int matricula = 0, string nombre = "", string carrera = "");
};