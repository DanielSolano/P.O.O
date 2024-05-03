#include "Persona.h"
#include <string>



#pragma once

class Profesionista : public Persona
{
protected:
    string cedula;
    int experiencia;

public:
    Profesionista();
    Profesionista(string nombre, string cedula = "De Tepito", int edad = 25, int experiencia = 3);
    virtual void Trabajar();

    //! Sobreescritura de saludar
    void Saludar() const;
};