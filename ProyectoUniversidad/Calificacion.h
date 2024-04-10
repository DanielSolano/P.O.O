#pragma once
#include "Materia.h"

class Calificacion
{
    protected:
        int valor;
        Materia* materia;
    public:
        Calificacion(int valor = 0, Materia* materia = nullptr);

        //Getters
        int GetValor()const { return valor; }
        Materia* GetMateria()const { return materia; }
        
        string ToString();
};