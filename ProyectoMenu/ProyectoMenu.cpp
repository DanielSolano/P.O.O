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
    Menu submenu("Configuracion");
    submenu.Agregar({'1', "Subopcion 1", {[]()
                                          {system("cls");cout << "Ejecutando subopcion 1" << endl; _getch(); }}});
    submenu.Agregar({'2', "Subopcion 2", {[]()
                                          {system("cls");cout << "Ejecutando subopcion 2" << endl; _getch(); }}});
    submenu.Agregar({'3', "Subopcion 3", {[]()
                                          {system("cls");cout << "Ejecutando subopcion 3" << endl; _getch(); }}});
    submenu.Agregar({'4', "Regresar", {[]()
                                       {system("cls");cout << "Regresando..." << endl; _getch(); }}});
    submenu.Ejecutar();
}

int main()
{
    Menu el_menu("Menu de prueba");
    el_menu.Agregar({'1', "Ver listado de archivos", Listado});
    el_menu.Agregar({'2', "Ver configuracion IP", ConfiguracionIP});
    el_menu.Agregar({'3', "Ver conexiones activas", ConexionesActivas});
    el_menu.Agregar({'4', "Ver configuracion", Configuracion});
    el_menu.Agregar({'5', "Salir", {[]()
                                    { cout << "Saliendo..." << endl; }}});

    /*
    do
    {
        system("cls");
        el_menu.Desplegar();
    } while (el_menu.Seleccionar() != '5');
    */

    el_menu.Ejecutar();
}
