#pragma once

class Persona
{

    // Los miembros de la clase tienen un nivel de proteccion o acceso
    // por default todos los elementos son privados, se puede cambiar al tipo
    // que deseemos.

    // private (default)
    // protected
    // public

    // El constructor debe de ser una funcion con el MISMO nombre que la clase pero NO debe de retornar ningun tipo de dato
    // este da informacion al objeto

    // Los objetos pueden tener un destructor. El destructor es un metodo que se ejecuta antes de que el objeto sea destruido

protected:
    int edad;
    char *nombre; // Nombre con memoria dinamica
    void Comer();

public:
    void Saludar() const;
  
    Persona();
    Persona(const char *el_nombre, int la_edad);
    Persona(const Persona &original); // Constructor de copia

    // Existen metodos para modificar y acceder atributos que estan protegidos del mundo exterior
    // Setter, modificar
    // Getter, acceder

    char *GetNombre();
    void SetNombre(const char *nombre);

    // Las funciones pueden ser implementadas al momento de ser declaradas. Se recomienda que sean funciones con poco codigo

    int GetEdad() { return edad; }

    void SetEdad(int nueva_edad)
    {
        edad = (nueva_edad > 0) ? nueva_edad : edad;
    }

    // Destructor, sin parametros ni retorno, con ~
    ~Persona();
};