#pragma once
#include <string>
#include <functional>
using std::function;
using std::string;
class Opcion
{
protected:
    string descripcion;
    char tecla;
    function<void(void)> accion; // que se ejecutara con esta opcion
public:
    Opcion(char tecla = 0, string desc = "", function<void(void)> a = []() {});
    // Getters
    char GetTecla() const { return tecla; };
    string GetDescripcion() const { return descripcion; };
    void Desplegar() const;
    void Ejecutar() const { accion(); }
};
