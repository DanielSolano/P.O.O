#include "numeros.h"
#include <string.h>
#include <iostream>

string removeSpaces(string str)
{
    string ret;
    for (char c : str)
    {
        if (c != ' ')
        {
            ret.push_back(c);
        }
    }

    return ret;
}

fraccion::fraccion(int numerador, int denominador)
{
    this->numerador = numerador;
    this->denominador = denominador;
}

fraccion::fraccion(string fraccion)
{
    string f2 = removeSpaces(fraccion);
    int pos = f2.find("/");                             
    string num = f2.substr(0, pos);                    
    string den = f2.substr(pos + 1, f2.length() - pos); // Extraer el denominador

    this->numerador = stoi(num);
    this->denominador = stoi(den);
}

fraccion fraccion::operator+(fraccion fraccion2)
{
    fraccion r;
    r.numerador = this->numerador * fraccion2.denominador + fraccion2.numerador * this->denominador;
    r.denominador = this->denominador * fraccion2.denominador;
    return r;
}

fraccion fraccion::operator-(fraccion fraccion2)
{
    fraccion r;
    r.numerador = this->numerador * fraccion2.denominador - fraccion2.numerador * this->denominador;
    r.denominador = this->denominador * fraccion2.denominador;
    return r;
}

fraccion fraccion::operator*(fraccion fraccion2)
{
    fraccion r;
    r.numerador = this->numerador * fraccion2.numerador;
    r.denominador = this->denominador * fraccion2.denominador;
    return r;
}

fraccion fraccion::operator/(fraccion fraccion2)
{
    fraccion r;
    r.numerador = this->numerador * fraccion2.denominador;
    r.denominador = this->denominador * fraccion2.numerador;
    return r;
}

fraccion operator+(int escalar, fraccion f)
{
    fraccion f1(escalar, 1);
    fraccion r;
    r.numerador = f1.numerador * f.denominador + f.numerador * f1.denominador;
    r.denominador = f1.denominador * f.denominador;
    return r;
}

fraccion operator-(int escalar, fraccion f)
{
    fraccion f1(escalar, 1);
    fraccion r;
    r.numerador = f1.numerador * f.denominador - f.numerador * f1.denominador;
    r.denominador = f1.denominador * f.denominador;
    return r;
}

fraccion operator*(int escalar, fraccion f)
{
    fraccion r;
    fraccion f1(escalar, 1);
    r.numerador = f1.numerador * f.numerador;
    r.denominador = f1.denominador * f.denominador;
    return r;
}

fraccion operator/(int escalar, fraccion f)
{
    fraccion r;
    fraccion f1(escalar, 1);
    r.numerador = f1.numerador * f.denominador;
    r.denominador = f1.denominador * f.numerador;
    return r;
}

ostream &operator<<(ostream &out, fraccion f)
{
    out << f.numerador << " / " << f.denominador;
    return out;
}
