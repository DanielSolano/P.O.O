#pragma once
#include <string>
#include <list>
#include "Figura.h"

using std::string;
using std:: list;

class Dibujo
{
protected:
	CRect dimensiones;
	bool finalizado = false;
	string nombre;
public:
	Dibujo(string nombre = "Dibujo");
	list<Figura*> figuras;
	void Agregar(Figura* fig) { figuras.push_back(fig); };
	void Borrar(Figura* fig);
	void Desplegar(CDC* pDC);
};

