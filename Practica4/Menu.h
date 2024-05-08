#pragma once
#include"Opcion.h"
#include<map>
using std::map;
class Menu
{
protected:
	string titulo;
	map<char, Opcion> opciones;
	char exit_key = 0;
public:
	Menu(string ttl = "Menu") { titulo = ttl; }
	void AgregarOpcion(Opcion la_opcion);
	void Desplegar();

	void SetExit(char ek) { exit_key = ek; }

	char SeleccionarOpcion();
	void Ejecutar();
};

