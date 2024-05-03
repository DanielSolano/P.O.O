#include <iostream>

#include "Estudiante.h"
#include "Persona.h"
#include "Profesionista.h"

using std::cout;
using std::endl;

int main()
{

    Estudiante estudiante;
    // estudiante.Saludar();
    // estudiante.Estudiar();

    Estudiante estudiante2(666000, "Guillermo", "Ing. Civil", 5, 20);
    estudiante2.Saludar();
    // estudiante2.Estudiar();

    Persona la_persona("Nicasio", 24);
    la_persona.Saludar();

    Profesionista prof1;
    prof1.Saludar();    
    prof1.Trabajar();

    Persona *persona;
    persona = new Estudiante(99012, "George", "Ing. Civil");
    persona->Saludar();
    

    Persona &ref_persona = estudiante2;
    ref_persona.Saludar();


}