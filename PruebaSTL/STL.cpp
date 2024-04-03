#include <iostream>
#include <ostream>
#include <stack>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <forward_list>
#include <conio.h>
#include "Persona.h"
#include "Estudiante.h"

using namespace std;
using std::ostream;

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

void QueueTest2(void)
{
    deque<int> cola;
    bool alt = true;
    int n;
    while (true)
    {
        cout << "Dame un numero (-1 para terminar:)";
        cin >> n;
        if (n == -1)
            break;
        if (alt)
        {
            cola.push_back(n);
        }
        else
        {
            cola.push_front(n);
        }
        alt = !alt;
    }
    cout << "Cantidad de elementos en la cola: " << cola.size() << endl;
    cout << "Elemento al inicio: " << cola.front() << endl;
    cout << "Elemento al final: " << cola.back() << endl;
    _getch();
    cout << "Elementos en la cola: ";
    while (!cola.empty())
    {
        cout << cola.front() << " ";
        cola.pop_front();
    }
}

void PQueueTest()
{
    // Una cola de prioridad se utiliza para acceder a los elementos de acuerdo a su prioridad, los mas grandes van sobre los pequeños
    priority_queue<int> cola;
    int n;
    while (true)
    {
        cout << "Dame un numero (-1 para terminar): ";
        cin >> n;
        if (n == -1)
            break;
        cola.push(n);
    }
    cout << "Cantidad de elementos en la cola: " << cola.size() << endl;
    _getch();
    cout << "Elemento de mayor prioridad: " << cola.top() << endl;
    _getch();
    cout << "Elementos en la cola: ";
    while (!cola.empty())
    {
        cout << cola.top() << endl;
        cola.pop();
    }
}

void PQueueTest2()
{
    priority_queue<Estudiante> cola;
    cola.push(Estudiante(453621, "Espergencia Perez", 3456));
    cola.push({567241, "Josefina Vazquez Mota", 4321});
    Estudiante e;
    e = {999666, "Iker Perez", 2234};
    cola.push(e);
    cola.emplace(666999, "Jose Torres", 3245);
    cout << "Cantidad de elementos en cola: " << cola.size() << endl;
    cout << "Estudiante con mayor prioridad: " << cola.top() << endl;
    while (!cola.empty())
    {
        cout << cola.top() << endl;
        cola.pop();
    }
}

void VectorTest()
{
    int n = 5;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 100;
    }
    cout << "Elementos del vector: ";

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
    v.resize(10);
    for (int c : v)
    {
        cout << c << " ";
    }
    cout << endl;

    // v.push_back(rand() % 100);
    v.emplace_back(rand() % 100);
    cout << "Nuevo tamanio del vector: " << v.size() << endl;
    cout << "Nuevo vector: ";

    vector<int>::iterator it; // Un iterador es un puntero que apunta a los objetos de un vector.
    it = v.begin();
    while (it != v.end())
    {
        cout << (*it) << " "; // Con " * " accedemos al valor del objeto al que apunta
        it++;
    }

    v = {2, 3, 4, 5, 8, 10, 20, 99};
    cout << "Nuevo tamanio del vector: " << v.size() << endl;
    cout << "Elementos del vector: ";
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    int x;
    cout << "Dame un numero para insertarlo en el vector: ";
    cin >> x;
    it = v.begin();
    while ((it != v.end()) && ((*it) < x))
    {
        it++;
    }
    v.insert(it, x);
    cout << "Vector actualizado: ";
    for (int n : v)
    {
        cout << n << " ";
    }
    cout << endl;
    cout << "Dame un numero para borrarlo del vector: ";
    cin >> x;
    it = v.begin();
    while ((it != v.end()) && ((*it) != x))
    {
        it++;
    }
    if (it != v.end())
    {
        v.erase(it);
        cout << "Vector actualizado: ";
        for (int n : v)
        {
            cout << n << " ";
        }
    }
    else
    {
        cout << "El numero " << x << " no se encuentra en el vector";
    }
}

ostream &operator<<(ostream &out, list<int> l)
{
    out << "[";
    for (auto it = l.begin(); it != l.end(); it++)
    {
        out << (*it) << " ";
    }
    out << "]";
    return out;
}

ostream &operator<<(ostream &out, forward_list<int> l)
{
    out << "[";
    for (auto it = l.begin(); it != l.end(); it++)
    {
        out << (*it) << " ";
    }
    out << "]";
    return out;
}

void ListTest()
{
    list<int> lista = {7, 3, 99, 666, 2, 80, 20, 3, 8, 1};
    lista.push_back(45);
    lista.push_front(300);
    cout << "Lista: " << lista << endl;
    lista.sort();
    cout << "Lista ordenada: " << lista << endl;
}

void ForwardList()
{
    forward_list<int> lista = {3, 5, 8, 15, 21, 66, 99, 666};
    lista.push_front(1);
    cout << "Lista: " << lista << endl;
    auto it = lista.begin();
    it++;
    it++;
    it++;
    lista.insert_after(it, 7);
    cout << "Nueva lista: " << lista << endl;
    lista.sort();
    cout << "Lista ordenada: " << lista << endl;
    it++;
    lista.erase_after(it);
    cout << "Nueva lista (erase): " << lista << endl;
}

void MapTest()
{
    map<string, int> inventario;
    inventario["libreta"] = 10;
    inventario["lapiz"] = 20;
    inventario["borrador"] = 5;
    inventario["sacapuntas"] = 666;
    auto it = inventario.begin();
    while (it != inventario.end()) // El mapa lo ordena por la llave, en este caso, el string
    {
        cout << (*it).first << " -> " << it->second << endl;
        it++;
    }
    string producto;
    int cantidad;
    cout << "Que producto quieres comprar?: ";
    getline(cin, producto);
    cout << "Cuantos quieres comprar?: ";
    cin >> cantidad;
    // inventario[producto] -= cantidad;
    it = inventario.find(producto); // Devuelve un apuntador al elemento que buscas, si no lo encuentra, devuelve un apuntador a end()
    if (it != inventario.end())
    {
        //  inventario[producto] -= cantidad;
        if ((*it).second < cantidad)
        {
            cout << "No hay suficiente producto en el inventario" << endl;
            return;
        }
        else
            (*it).second -= cantidad;
    }
    else
    {
        cout << "El producto no se encuentra en el inventario" << endl;
    }
    cout << "Mapa actualizado: " << endl;
    for (auto &p : inventario) // Con referencia para que no haga copias
    {
        cout << p.first << " -> " << p.second << endl;
    }
}

int main()
{
    MapTest();
}