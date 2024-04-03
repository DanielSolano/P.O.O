#include <iostream>
#include "Menu.h"
#include <conio.h>

using std::cout;
using std::endl;

void Listado()
{
    cout << "Archivos en el folder" << endl;
    system("dir");
    _getch();
}

void ConfiguracionIP()
{
    cout << "Configuracion IP: " << endl;
    system("ipconfig");
    _getch();
}

void ConexionesActivas()
{
    cout << "Conexiones activas: " << endl;
    system("netstat");
    _getch();
}

void Configuracion()
{
    cout << "Pendiente" << endl;
    _getch();
}

int main()
{
    Menu el_menu("Menu de prueba");
    el_menu.Agregar({'1', "Ver listado de archivos", Listado});
    el_menu.Agregar({'2', "Ver configuracion IP", ConfiguracionIP});
    el_menu.Agregar({'3', "Ver conexiones activas", ConexionesActivas});
    el_menu.Agregar({'4', "Ver configuracion", Configuracion});
    el_menu.Agregar({'5', "Salir", {[](){cout << "Saliendo..." << endl;}}});

    /*
    do
    {
        system("cls");
        el_menu.Desplegar();
    } while (el_menu.Seleccionar() != '5');
    */

    el_menu.Ejecutar();   

}
