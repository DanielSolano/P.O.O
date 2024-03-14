// PruebaExcepciones.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int dividir(int n, int d) {
    int r;
    //Una forma de manejar los errores en C++, son las excepciones.
    //Una excepcion es una notificacion de error. Cuando ocurre un
    //error, se lanza la notificacion, y quien invoca la funcion
    //puede recibir esa notificacion (atraparla) y hacer acciones
    //necesarias para manejar el error.
    //Cuando una excepcion es lanzada, la ejecucion de la funcion se
    //interrumpe y el control regresa al codigo que invoco la funcion.
    if (d == 0) {
        //Para lanzar la notificacion utilizar throw
        //return 0;
        throw "Error: division entre cero...";
    }
    r = n / d;
    return r;
}

int main()
{
    int x, y;
    cout << "Dame el dividendo: ";
    cin >> x;
    cout << "Dame el divisor: ";
    cin >> y;
    //Se puede validar y, o dividir puede hacer la validacion
    //Cuando una funcion puede generar una excepcion, se puede ejecutar
    //el codigo relacionado con la invocacion de la funcion en un bloque
    //try-catch.
    try {
        int d = dividir(x, y);
        //En caso de que se genere una excepcion, la ejecucion del bloque
        //try se interrumpe, y el control pasa al bloque catch.
        cout << "La division de " << x << " entre " << y << " es " << d << endl;
    }
    catch (const char *e) {
        cout << e << endl;
    }
    
}

