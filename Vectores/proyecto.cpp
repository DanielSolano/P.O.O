#include <string.h>
#include <iostream>
#include "vector.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    Vector v1(10, 20, 5), v2 = {25, 11, 7}; // Distintas formas de inicializar un vector
    Vector v3;
   
    // v3 = v1.Sumar(v2);
    v3 = v1 + v2;
    
    cout << "Vector resultado: (" << v3.x << ", " << v3.y << ", " << v3.z << ")" << endl;
    string v;
    v = v3.ToString();
    cout << v << endl;
   
    // v3 = v1.Multiplicar(v2);
    v3 = v1 * v2;

    cout << v1.ToString() << " x " << v2.ToString() << " = " << v3.ToString() << endl;
   
    // v3 = v3.Multiplicar(2);
    v3 = v3 * 2;

    cout << v3.ToString() << endl;
    return 0;
}