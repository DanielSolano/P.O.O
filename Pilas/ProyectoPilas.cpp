#include <iostream>
#include "Stack.h"

using std::cout;
using std::endl;

int main()
{
    Stack pila;
    pila.push(9);
    pila.push(20);
    pila.push(1);
    pila.push(3);
    pila.push(666);
    cout << "Elementos de la pila: ";
    while(!pila.IsEmpty())
    {
        cout << " " <<pila.pop();
    }
    cout << endl;
    return 0;
}