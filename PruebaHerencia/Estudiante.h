#pragma once
#include "Persona.h"
#include <String.h>

using std::string;

class Estudiante : public Persona
{
    protected:
        int matricula;
        int semestre = 1;
        string carrera;

    public:
        Estudiante();
        Estudiante(int matricula, string nombre, string carrera = "Software", int semestre = 1, int edad = 18);
        void Estudiar();

        // * En una clase derivada se puede redifinir la forma como se hacen algunos metodos. El nuevo metodo sustituira al metodo de la clase base.
        void Saludar() const override;
        
};
