#include "Opcion.h"
#include<iostream>
#include<iomanip>
using std::cout;
using std::endl;

Opcion::Opcion(char tecla, string desc, function<void(void)> accion)
{
	this->tecla = tecla;
	descripcion = desc;
	this->accion = accion;
}

void Opcion::Desplegar(int width, bool highlighted) const
{
	if (highlighted) {
		//Utilizamos secuencia de escape ANSI para modificar color de fondo y de letra
		cout << "\x1B[30;47m" << tecla << ") ";
		if (width != 0)
			cout << std::setw(width) << std::left << descripcion << "\x1B[0m" << endl;
		else
			cout << descripcion << "\x1B[0m" << endl;
	}
	else
		cout << tecla << ") " << descripcion << endl;
}
