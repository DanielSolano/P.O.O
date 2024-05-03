#pragma once
#include<string>
#include<map>
#include"Opcion.h"
using std::string;
using std::map;
class Menu
{
protected:
	string titulo;
	map<char, Opcion> opciones;
    char exit_key;
public:
	Menu(string titulo = "Menu");
    void Agregar(Opcion la_opcion);
    void Eliminar(char tecla);
    void Desplegar();
    char Seleccionar();
    void SetExitKey(char ek){exit_key = ek;}
    void Ejecutar();
};

