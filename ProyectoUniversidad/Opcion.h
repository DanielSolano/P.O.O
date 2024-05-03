#pragma once
#include<string>
#include<functional>
using std::string;
using std::function;
class Opcion
{
protected:
	string descripcion;
	char tecla;
	function<void(void)> accion;//lo que se hara cuando se ejecute
	
public:
	Opcion(char tecla = 0, string desc = "",
		function<void(void)> accion = []() {});
	//Getters
	char GetTecla()const { return tecla; }
	string GetDescripcion()const { return descripcion; }
	//Otros metodos
	void Desplegar(int width = 0, bool higlighted = false) const;
	
	void Ejecutar() const { accion(); }

};

