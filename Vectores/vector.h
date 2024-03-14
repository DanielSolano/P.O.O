#include <string.h>
#include <iostream>
#include <ostream>

using std::ostream;
using std::string;

class Vector
{
public:

    double x;
    double y;
    double z;
    Vector(double x = 0, double y = 0, double z = 0); // Constructor utilizando parametros default, si no se pasan valores, se inicializan en 0
    string ToString();

    double GetMagnitud(); // Obtener magnitud del vector
    Vector GetUnitVector(); // Obtener magnitud del vector

    // Sobrecarga de funciones

    Vector Multiplicar(Vector v2); // Producto vectorial
    Vector Multiplicar(double s);  // Producto punto
    Vector Sumar(Vector v2); // Suma de vectores

    // Sobrecarga de operadores

    Vector operator*(Vector v2); // Creando operador para multiplicar vectores
    Vector operator*(double s); // Creando operador para multiplicar vector por radical
    Vector operator+(Vector v2); // Creando operador para sumar vectores
    
};

Vector operator*(double s, Vector v); // Operador para cuando el operador esta del lado izquierdo

ostream& operator<<(ostream& out, Vector v) // Operador para enviar como salida a un stream
{
    out << "(" << v.x << "," << v.y << "," << v.z << ")";
    return out;
}