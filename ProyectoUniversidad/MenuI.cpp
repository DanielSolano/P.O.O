#include "MenuI.h"
#include <iostream>
#include<conio.h>
using std::cout;
using std::endl;

void MenuI::AgregarOpcion(Opcion la_opcion)
{
	opciones.push_back(la_opcion);
	exit_key = la_opcion.GetTecla();
	if (desc_width < la_opcion.GetDescripcion().size())
		desc_width = la_opcion.GetDescripcion().size();
}

void MenuI::Desplegar()
{
	system("cls");
	for (int i = 0; i < opciones.size(); i++) {
		if (i == im) {
			opciones[i].Desplegar(desc_width,true);//Despliega la opcion iluminada
		}
		else
		   opciones[i].Desplegar();
	}
}

char MenuI::SeleccionarOpcion()
{
	char t;
	while (true) {
		t = _getch();
		if (_kbhit()) {//Si aun queda informacion en el buffer de teclado, es una tecla de control
			t = _getch();//Necesitamos leer el codigo de control
			//Verificamos si es codigo de flecha
			if (t == 72) {//arriba
				im = (im - 1 + opciones.size()) % opciones.size();
				//system("cls");
				Desplegar();
			}
			if (t == 80) {//abajo
				im = (im + 1) % opciones.size();
				//system("cls");
				Desplegar();
			}
		}
		else {
			//Puede ser un caracter de la opcion
			for (Opcion& op : opciones) {
				if (op.GetTecla() == t) {
					op.Ejecutar();
					return op.GetTecla();
				}
			}
			if (t == 13) {
				opciones[im].Ejecutar();
				return opciones[im].GetTecla();
			}
		}
	}
	return 0;
}

void MenuI::Ejecutar()
{
	do {
		system("cls");
		Desplegar();
	} while (SeleccionarOpcion() != exit_key);
}
