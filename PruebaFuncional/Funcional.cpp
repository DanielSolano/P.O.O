#include <iostream>
#include <functional>
#include <vector>
#include <ostream>

using namespace std;

void Saludo()
{
    cout << "Hola mundo" << endl;
}

void Saludar(function<void(void)> fs)
{
    cout << "Te voy a saludar... " << endl;
    cout << "... preparate ... " << endl;
    fs();
    cout << "... listo ... " << endl;
}

void Saludo2()
{
    srand(time(NULL));
    if ((rand() % 100) < 50)
        cout << "Que transa" << endl;
    else
        cout << "Buenas noches" << endl;
}

int conteoPares(vector<int> v)
{
    int conteo = 0;
    for (int n : v)
    {
        if (n % 2 == 0)
            conteo++;
    }
    return conteo;
}

vector<int> extraerPares(vector<int> v)
{
    vector<int> pares;
    int conteo = 0;
    for (int n : v)
    {
        if (n % 2 == 0)
            pares.push_back(n);
    }
    return pares;
}

int Contar(vector<int> v, function<bool(int)> p)
{
    int conteo = 0;
    for (int n : v)
    {
        if (p(n))
            conteo++;
    }
    return conteo;
}

vector<int> Extraer(vector<int> v, function<bool(int)> p)
{
    vector<int> elem;
    for (int n : v)
    {
        if (p(n))
            elem.push_back(n);
    }
    return elem;
}

bool EsPar(int n)
{
    return n % 2 == 0;
}

bool EsPrimo(int x)
{
    if ((x == 2) || (x == 3)) return true;
    if ((x == 1) || (x % 2 == 0) || (x % 3 == 0)) return false;
    for (int d = 5; d <= x; d += 2)
    {
        if (x % d == 0) return false;
    }
    return true;    
}

ostream &operator<<(ostream &os, vector<int> v)
{
    for (int n : v)
    {
        os << n << " ";
    }
    return os;
}

int main()

{
    // Saludo();

    // Las funciones pueden ser manejadas como objeto

    // function<void(void)> f = Saludo;
    // function<void(void)> f2 = Saludo;

    // Saludar(f2);

    vector<int> numeros = {6, 9, 11, 666, 85, 42, 1, 8, 2, 21, 777};
    vector<int> pares = extraerPares(numeros);
    cout << "Vector: " << numeros << endl;
    // cout << "Hay " << conteoPares(numeros) << " numeros pares" << endl;
    // cout << "Numeros pares: " << pares << endl;

    vector<int> n2 = Extraer(numeros, EsPar);
    cout << "Hay " << n2.size() << " numeros pares" << endl;
    cout << "Numeros pares: " << n2 << endl;

    cout << "Hay ";
    cout<< std::count_if(numeros.begin(), numeros.end(), [](int x) {return ((x % 3) == 0); });
    cout << " multiplos de 3 en el vector..." << endl;
}
