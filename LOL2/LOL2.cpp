// LOL2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <thread>
#include <typeinfo>
#include"Enemigo.h"
#include"Mago.h"
#include"Tanque.h"
#include "Gargola.h"

using std::cout;
using std::endl;

void UsarEnemigo(Enemigo* enemigo)
{
    if (rand() % 2)
    {
        enemigo->Mover();
    }
    else
    {
        enemigo->Detenerse();
    }

        if (rand() % 2) {
            enemigo->RecibirDanio(rand() % 40);
        }
        if (rand() % 2) {
            enemigo->Atacar();
        }
        if (rand() % 2) {
            enemigo->Curarse();
        }

        // Para conocer el tipo que esta almacenado en una variable podemos usar el macro "type_id"
        // Devuele un objeto typeinfo que incluye el nombre de la clase
        /*
        auto &ti = typeid(*enemigo);
        if (ti == typeid(Mago)) {
            if (rand() % 2)
            {
                Mago* mago = (Mago*)enemigo;
                mago->RegenerarMana();
            }
		}
		else if (ti == typeid(Gargola)) {
            if (rand() % 2)
            {
                ((Gargola*)enemigo)->Volar();
            }
            else
            {
                ((Gargola*)enemigo)->Aterrizar();
            }
		}
        */

        // Otra forma de hacer lo mismo es con static_cast y dynamic_cast, el primero verifica en tiempo de compilacion
        // Pero todavia podria generar errores si se hace un cast a un tipo incorrecto
        Gargola* gargola = static_cast<Gargola*>(enemigo);

        // El segundo verifica en tiempo de ejecucion si el cast es valido, si no lo es devuelve nullptr, si es valido devuelve el puntero
        
        Mago* m = dynamic_cast<Mago*>(enemigo);
        if (m != nullptr)
        {
            if (rand() % 2)
                m->RegenerarMana();
        }

        Volador* v = dynamic_cast<Volador*>(enemigo);
        if (v != nullptr)
		{
			if (rand() % 2)
				v->Volar();
			else
				v->Aterrizar();
		}

}

void Delay(long ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int main()
{
    srand(time(0));
    //Enemigo es una clase abstracta. No se pueden crear instancias
    //de clases abstractas.
   // Enemigo malandro;
    std::vector<Enemigo*> enemigos;
    //creamos 10 enemigos de forma aleatoria
    for (int i = 0; i < 10; i++) {
        switch(rand() % 3) {
        case 0: enemigos.push_back(new Mago); break;
        case 1: enemigos.push_back(new Tanque); break;
        case 2: enemigos.push_back(new Gargola); break;
        }
    }
    bool vivos = true;
    while (vivos) {
        vivos = false;
        //iteramos el vector para interactuar con cada enemigo
        for (auto enemigo : enemigos)
        {
            if (enemigo->IsAlive())
            {
                vivos = true; //todavia hay al menos un enemigo vivo
                //interactuamos con el enemigo
                UsarEnemigo(enemigo);
            }
            Delay(100);
        }
    }
    
    
}

