#pragma once
#include "Profesionista.h"
#include <string>

using std::endl;

class Ingeniero : public Profesionista
{
    public:
        Ingeniero(string nombre = "William", string cedula = "De tepito", int edad = 25, int experiencia = 3);
        void Trabajar() override;
        void Saludar() const override;
        virtual void ResolverProblemas();
};