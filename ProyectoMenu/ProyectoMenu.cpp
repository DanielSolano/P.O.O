// ProyectoMenu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<conio.h>
#include"MenuI.h"
using std::cout;
using std::endl;
void Opcion1() {
	cout << "Archivos en el folder: " << endl;
	system("dir");
	_getch();
}
void Opcion2() {
	cout << "Configuracion de red: " << endl;
	system("ipconfig /all");
	_getch();
}
void Opcion3() {
	MenuI submenu("Otras opciones");
	submenu.AgregarOpcion({ '1',"Subpcion 1",
		[]() {cout << "Ejecutando subopcion 1..." << endl; _getch(); } });
	submenu.AgregarOpcion({ '2',"Subpcion 2",
		[]() {cout << "Ejecutando subopcion 1..." << endl; _getch(); } });
	submenu.AgregarOpcion({ '3',"Subpcion 3",
		[]() {cout << "Ejecutando subopcion 3..." << endl; _getch(); } });
    submenu.AgregarOpcion({ '4',"Regresar",
		[]() {} });
	submenu.Ejecutar();
}
int main()
{

	
	
	MenuI el_menu;
	//agregamos las opciones
	el_menu.AgregarOpcion({ '1',"Ver listado de archivos",Opcion1 });
	el_menu.AgregarOpcion({ '2',"Ver configuracion de red",Opcion2 });
	el_menu.AgregarOpcion({ '3',"Otras opciones",Opcion3 });
	el_menu.AgregarOpcion({ '4',"Salir",[]() {cout << "Adios.." << endl; } });
	/*do {
		el_menu.Desplegar();
	}while(el_menu.SeleccionarOpcion()!='4');
	*/
	el_menu.Ejecutar();

}

