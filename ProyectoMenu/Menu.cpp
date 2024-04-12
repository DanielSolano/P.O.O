#include "Menu.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Menu::Menu(string titulo)
{
    this->titulo = titulo;
}

void Menu::Agregar(Opcion la_opcion)
{
    // Agregamos la opcion al mapa
    if (opciones.find(la_opcion.GetTecla()) == opciones.end())
    {
        opciones.insert({la_opcion.GetTecla(), la_opcion});
        exit_key = la_opcion.GetTecla();
    }
    else
    {
        throw "La opcion ya existe en el menu";
    }
}

void Menu::Eliminar(char tecla)
{
    auto it = opciones.find(tecla);
    if (it != opciones.end())
    {
        opciones.erase(it);
    }
    else
    {
        throw "La opcion no existe en el menu";
    }
}

void Menu::Desplegar()
{
    cout << titulo << endl;
    // Desplegamos opciones
    for (auto &par : opciones)
    {
        par.second.Desplegar();
    }
}

char Menu::Seleccionar()
{
    while (true)
    {
        char selec;
        cout << "Seleccione una opcion: ";
        cin >> selec;
        cin.ignore(1024, '\n');
        // Buscar la opcion seleccionada
        auto it = opciones.find(selec);
        if (it != opciones.end())
        {
            (*it).second.Ejecutar();
            return selec;
        }
        else
        {
            cout << "Opcion no valida" << endl;
        }
    }
}

void Menu::Ejecutar()
{
    do{
        system("cls");
        Desplegar();
    }while(Seleccionar() != exit_key);
}
