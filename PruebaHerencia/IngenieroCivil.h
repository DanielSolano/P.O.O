#pragma once
#include "Ingeniero.h"

class IngenieroCivil : public Ingeniero
{
    public:
        IngenieroCivil(string nombre = "William", string cedula = "De tepito", int edad = 25, int experiencia = 3);
        virtual void Construir();
        void Trabajar() override;
        void ResolverProblemas() override;
};