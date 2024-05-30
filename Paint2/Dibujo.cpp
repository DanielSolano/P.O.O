#include "pch.h"
#include "Dibujo.h"

Dibujo::Dibujo(string nombre)
{
	this->nombre = nombre;
}

void Dibujo::Borrar(Figura* fig)
{
	auto it = figuras.begin();
	while (it != figuras.end() && *it != fig)
	{
		it++;
	}
	if (it != figuras.end())
	{
		figuras.erase(it);
		delete fig;
	}
}

void Dibujo::Desplegar(CDC* pDC)
{
	for (auto fig : figuras)
	{
		fig -> Desplegar(pDC);
	}
}
