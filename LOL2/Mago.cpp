#include "Mago.h"

Mago::Mago():
	Enemigo(100,25,75,1,25,5)
{
}

void Mago::LanzarHechizo()
{
	if (mana >= 80) {
		cout << "Por Demacia!" << endl; 
		mana -= 80;
	}
	else {
		cout << "no hay mana..." << endl;
	}
}

void Mago::LanzarHechizoCurativo()
{
	if (mana >= 90) {
		cout << "Hechizo curativo..." << endl;
		mana -= 90;
		vida *= 1.2;
		vida = (vida > 100) ? 100 : vida;
	}
	else {
		cout << "No hay mana..." << endl;
	}
}

void Mago::Atacar()
{
	if(alive)
	//Verificar el rango de ataque
		LanzarHechizo();
}

void Mago::Curarse()
{
	if(alive)
		LanzarHechizoCurativo();
}

void Mago::Defenderse()
{
	if(alive)
		cout << "Poniendo barrera invisible..." << endl;
}

void Mago::Morir()
{
	alive = 0;
	cout << "Desplomandoze muerto..." << endl;
}

void Mago::RecibirDanio(float danio_recibido)
{
	if (!alive) return;
	if (!moving) {
		if (mana >= 90)
		{
			Defenderse();
			return;
		}
	}
	float da = (rand() % 100) / 100.0f * danio_recibido;
	cout << "Recibiendo danio... " << endl;
	vida -= da;
	if (vida <= 0) 
	{
		vida = 0;

		Morir();
	}
}

void Mago::RegenerarMana()
{

	if (mana >= 990)
		mana += 10;
		cout << "Regenarando mana" << endl;
}

