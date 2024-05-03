#pragma once
#include"Opcion.h"
#include<vector>
using std::vector;
class MenuI
{
	string titulo;
	vector<Opcion> opciones;
	char exit_key = 0;
	int im = 0;//indice de la opcion marcada
	int desc_width = 0;//ancho para despliegue de descripcion.
	//util para opciones iluminadas
public:
	MenuI(string ttl = "Menu") { titulo = ttl; }
	void AgregarOpcion(Opcion la_opcion);
	void Desplegar();

	void SetExit(char ek) { exit_key = ek; }

	char SeleccionarOpcion();
	void Ejecutar();
};

