#pragma once
#include "Ingeniero.h"

class IngenieroSoftware : public Ingeniero
{
    public:
        IngenieroSoftware(string nombre = "El metodo", string cedula = "De reddit", int edad = 25, int experiencia = 3);
        virtual void Construir();
        void Trabajar() override;
        void ResolverProblemas() override;
};