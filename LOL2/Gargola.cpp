#include "Gargola.h"

Gargola::Gargola() :
	Enemigo(100, 50, 50, 1, 5, 15)
{
}

void Gargola::Atacar()
{
	if (!alive) return;
	if (rand() % 2)
	{
		Morder();
	}
}

void Gargola::Curarse()
{
	if (!alive) return;
	vida = vida * 1.10;
	vida = (vida > 100) ? 100 : vida;
}

void Gargola::Defenderse()
{
	if (!alive) return;
	cout << "Cubriendose con las alas... " << endl;
}

void Gargola::Morder()
{
	cout << "Mordiendo... grrr..." << endl;
}

void Gargola::Volar()
{
	if (alive)
	{
		Volador::Volar();
		cout << "Aleteando y papaloteando..." << endl;
	}
}

void Gargola::Aterrizar()
{
	
	Volador::Aterrizar();
	cout << "En el piso... " << endl;
	
}

void Gargola::Araniar()
{
	cout << "Araniando... " << endl;
}

void Gargola::RecibirDanio(float danio_recibido)
{
	if (!alive) return;
	if (!volando)
	{
		Defenderse();
		return;
	}
	float da = (rand() % 100) / 100.0f * danio_recibido;
	vida -= da;
	if (vida <= 0) {
		vida = 0;

		Morir();
	}
}

void Gargola::Morir()
{
	alive = 0;
	cout << "Cayendo con pescuezo retorcido... " << endl;
}
