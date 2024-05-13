#include "Tanque.h"

Tanque::Tanque():
	Enemigo(500,250,30,1,5,15)
{
}

void Tanque::Golpear()
{
	if (alive)
	cout << "Tirando un golpe..." << endl;
}

void Tanque::Atacar()
{
	Golpear();
}

void Tanque::Curarse()
{
	if (alive)
	{
		vida += 2;
		vida = (vida > 500) ? 500 : vida;
	}
}

void Tanque::Defenderse()
{
	if (alive)
	{ 
		cout << "Poniendo el pecho..." << endl;

	}
}

void Tanque::RecibirDanio(float danio_recibido)
{
	if (!alive) return;
	vida -= danio_recibido * .25;
	cout << "Ouch! ( " << vida << ") " << endl;
	if (vida <= 0) {
		vida = 0;
		Morir();
	}
}

void Tanque::Morir()
{
	alive = false;
	cout << "Explotando..." << endl;
}
