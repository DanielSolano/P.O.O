#pragma once
#include<string>
#include <ostream>

using std::ostream;
using std::string;
using std::cout;

class Persona
{

protected:
	int edad=18;
	
	std::string nombre; //el nombre lo manejaremos con cadena de c++
	void Reir() const;  //Un metodo const no puede modificar atributos
	void Comer()const;
public:
	//Constructores
	Persona();
	Persona(const char* el_nombre, int la_edad);
	//Destructor
	//~Persona(); no manejamos memoria dinamica, no es necesario el
	//destructor
	virtual void HacerReir(int motivo) const;
	//Getters y setters
	std::string GetNombre() const;
	void SetNombre(const char* nuevo_nombre);
	
	int GetEdad() const { return edad; };
	void SetEdad(int nueva_edad)
	{
		edad = (nueva_edad > 0) ? nueva_edad : edad;
	}
	
	// * El metodo saludar tendra versiones particulares en cada clase derivada
	// * por lo que se declara como virtual
	virtual void Saludar() const; 

};

ostream &operator<<(ostream &out, Persona &persona);
