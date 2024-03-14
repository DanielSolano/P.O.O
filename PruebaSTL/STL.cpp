#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include "Persona.h"
/*
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::stack;
using std::string;
*/

using namespace std;

void StackTest()
{
    stack<int> pila;
    int n;
    while (true)
    {
        cout << "Dame un numero (-1 para terminar:)";
        cin >> n;
        if (n == -1)
            break;
        pila.push(n);
    }
    cout << "Cantidad de elementos agregados a la pila: " << pila.size() << endl;
    cout << "Elemento en el tope de la pila: " << pila.top() << endl;
    cout << "Todos los elementos de la pila: " << endl;
    while (!pila.empty())
    {
        cout << pila.top() << " ";
        pila.pop();
    }
}

void StackTest2()
{
    string frase;
    cout << "Dame una frase: ";
    getline(cin, frase);
    stack<char> pila;
    for (int i = 0; i < frase.size(); i++)
    {
        if (frase[i] != ' ')
            pila.push(tolower(frase[i]));
    }
    bool palindromo = true;
    for (char c : frase)
    {
        if (c == ' ')
            continue;
        if (tolower(c) != pila.top())
        {
            palindromo = false;
            break;
        }
        pila.pop();
    }

    if (palindromo)
    {
        cout << "\"" << frase << "\" es palindromo... " << endl;
    }
    else
    {
        cout << "La frase no es un palindromo" << endl;
    }
}

void StackTest3()
{
    stack<Persona> personas;
    personas.push(Persona("Sosimo", 20));
    personas.push(Persona("Maria", 30));
    personas.push(Persona("Pedro", 40));
    personas.push(Persona("Ana", 50));
    // Emplace es mas eficiente que el push, ya que emplea el constructor para crear el objeto
    personas.emplace("Sempronio", 25);
    while (!personas.empty())
    {
        cout << personas.top() << endl;
        personas.pop();
    }
}

void QueuesTest()
{
    queue<int> cola;
    int n;
    while (true)
    {
        cout << "Dame un numero (-1 para terminar:)";
        cin >> n;
        if (n == -1)
            break;
        cola.push(n);
    }
    cout << "Numero de elementos agregados a la cola: " << cola.size() << endl;
    cout << "Elemento en el frente de la cola: " << cola.front() << endl;
    cout << "Ultimo elemento de la cola: " << cola.back() << endl;
    cout << "Todos los elementos de la cola: " << endl;
    while (!cola.empty())
    {
        cout << cola.front() << " ";
        cola.pop();
    }

}

int main()
{
    StackTest3();
}