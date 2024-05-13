#pragma once
#include<iostream>
using std::cout;
using std::endl;
class Enemigo
{
protected:
	float vida;
	float defensa;
	float danio;
	int nivel;
	float rango;//rango de ataque
	float velocidad;
	//atributo de estado para operacion del enemigo
	bool moving = false;
	bool alive = true;

public:
	Enemigo(float vida = 100, float defensa = 50, float danio = 80,
		int nivel = 1, float rango = 5,float velocidad=20);
	//Getters
	float GetVida()const { return vida; }
	float GetDefensa()const { return defensa; }
	float GetDanio()const { return danio; }
	int GetNivel()const { return nivel; }
	float GetRango()const { return rango; }
	float GetVelocidad() const { return velocidad; }
	bool IsAlive() const { return alive; }
	//metodos
	/*No sabemos que hara el enemigo para atacar, por lo que no podemos
	poner codigo en la implementacion, pero el metodo es necesario por
	diseño. Cuando tenemos este tipo de metodo lo declaramos como
	virtual puro. Una funcion virtual pura se le conoce como funcion 
	abstracta y no tiene codigo, por lo que se le asigna 0 como codigo*/
	virtual void Atacar()=0;
	//toda clase que tenga al menos un metodo virtual puro se convierte
	//en clase abstracta
	virtual void Curarse() = 0;
	virtual void Defenderse()=0;
	virtual void RecibirDanio(float danio_recibido);
	virtual void Mover();
	virtual void Detenerse();
	virtual void Morir();


};

