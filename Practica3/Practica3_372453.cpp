#include <iostream>
#include "numeros.h"

using std::cout;
using std::endl;

int main()
{
    int escalar;
    fraccion f1;
    fraccion f2;
    fraccion f3;
    fraccion f4;
    fraccion f5;
    string cadena = "3 / 4";
    f1 = cadena;
    cout << "Constructor cadena \nf1 = " << f1 << endl;

    f2 = {3, 4};
    cout << "Constructor enteros \nf2 = " << f2 << endl;

    escalar = 2;
    f3 = f1 + f2;
    cout << "Suma con sobrecarga de operador: (" << f1 << ") + (" << f2 << ") = " << f3 << endl;
    f3 = escalar + f2;
    cout << "Suma escalar con sobrecarga de operador: " << escalar << " + (" << f2 << ") = " << f3 << endl;
    
    f2 = {5, 7};
    escalar = 3;
    f3 = f1 - f2;
    cout << "Resta con sobrecarga de operador: (" << f1 << ") - (" << f2 << ") = " << f3 << endl;
    f3 = escalar - f2;
    cout << "Resta escalar con sobrecarga de operador: " << escalar << " - (" << f2 << ") = " << f3 << endl;

    f2 = {7, 8};
    f1 = {1, 2};
    escalar = 5;
    f4 = f1 * f2;
    cout << "Multiplicacion con sobrecarga de operador: (" << f1 << ") * (" << f2 << ") = " << f4 << endl;
    f5 = escalar * f1;
    cout << "Multiplicacion por escalar con sobrecarga de operador: " << escalar << " * (" << f1 << ") = " << f5 << endl;

    f2 = {9, 4};
    f1 = {8, 3};
    escalar = 6;
    f3 = f1 / f2;
    cout << "Division con sobrecarga de operador: (" << f1 << ") / (" << f2 << ") = " << f3 << endl;
    f5 = escalar / f1;
    cout << "Division por escalar con sobrecarga de operador: " << escalar << " / (" << f1 << ") = " << f5 << endl;

    return 0;
}