#include <iostream>
#include "persona.h"
#include <time.h>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    srand (time(NULL));
    // Creamos un par de objetos de clase persona
    // Existen 2 formas de crear un objeto
    // Estatica, el objeto se crea en memoria estatica
    // en el stack del programa

    Persona la_persona("Mitillo", 19);
    
    // En este punto del programa, ya existe un objeto
    // clase persona en la memoria (en el stack).

    // La segunda forma es la forma dinamica, el objeto
    // se debe crear en memoria dinamica por medio del 
    // operador new.

    // new devuelve la direccion de memoria del objeto
    // recien creado en el heap. Necesitamos un apuntador para
    // almacenar la direccion y poder acceder al objeto

    Persona* otra_persona;

    // Todavia no existe objeto nuevo en este punto

    otra_persona = new Persona("Amlo", 6);

    // otra_persona ya apunta a la direccion del nuevo objeto
    
    // La principal diferencia entre los objetos en memoria estatica y los objetos 
    // en memoria estatica es que los objetos estaticos se eliminan automaticamente
    // de memoria una vez que finaliza el bloque de codigo en el cual fueron creados
    // los objetos creados en memoria dinamica deben ser eliminados manualmente



    la_persona.Saludar();
    la_persona.HacerReir(rand());

    otra_persona->Saludar();
    otra_persona->HacerReir(rand());

    Persona tercer_persona("Mitillo", 50);
    tercer_persona.Saludar();

    // Eliminar la persona de memoria dinamica
    delete otra_persona;

    return 0;
}
