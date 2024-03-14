#include "Persona.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void UsarPersona(Persona &persona)
{
    cout << "\n---- Utilizando persona ---- " << endl;
    persona.Saludar();
    cout << "---- Persona utilizada ---- \n"
         << endl;
}

// Cuando se recibe parametro existe la posibilidad de que la funcion modifique el parametro
// afectando a la variable que utilizamos al invocar la funcion

void UsarPersona2(Persona persona)
{
    cout << "\n --- Usando otra vez a persona: " << persona.GetNombre();
    cout << " --- " << endl;
    persona.Saludar();
    persona.SetNombre("Ifigenia");
    persona.SetEdad(-20);
    cout << "---- Persona utilizada ---- \n"
         << endl;
}

int main()
{
    srand(time(NULL));

    Persona persona1("Sempronio", 20);
    Persona persona2("AMLO", 72);
    Persona *persona_dinamica;

    persona_dinamica = new Persona("Dinamico", 80);
    persona1.Saludar();
    UsarPersona(persona2);

    UsarPersona2(persona1);

    cout << "\n Adios \n"
         << endl;
    delete (persona_dinamica);
}
