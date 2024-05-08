#include "Menu.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
void Menu::AgregarOpcion(Opcion la_opcion)
{
	opciones[la_opcion.GetTecla()] = la_opcion;
	exit_key = la_opcion.GetTecla();
}

void Menu::Desplegar()
{
	cout << titulo << endl;
	for (auto& po : opciones)
		po.second.Desplegar();
}

char Menu::SeleccionarOpcion()
{
	//debemos leer la tecla que presione el usuario
	//y buscar la opcion correspondiente para
	//ejecutarla
	char t;
	while (true) {
		cout << "Seleccione una opcion: ";
		cin >> t;
		cin.ignore(1024, '\n');
		auto it = opciones.find(t);
		if (it != opciones.end()) {
			//ejecutamos second en it
			(*it).second.Ejecutar();
			return t;
		}
		else {
			cout << "Esa opcion no existe... fijate!" << endl;
		}
	}
	return t;
}

void Menu::Ejecutar()
{
	do {
		system("cls");
		Desplegar();
	} while (SeleccionarOpcion() != exit_key);
}
