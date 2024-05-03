#include<iostream>
#include "Opcion.h"

Opcion::Opcion(char tecla, string desc, function<void(void)> a)
{
	this->tecla = tecla;
	descripcion = desc;
	accion = a;
}
void Opcion::Desplegar()const
{
	std::cout << tecla << ") " << descripcion << std::endl;
}
