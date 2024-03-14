#pragma once
#include <iostream>
#include <ostream>

using std::ostream;
using std::string;

class fraccion
{
public:
    int numerador;
    int denominador;
    fraccion(int numerador = 0, int denominador = 0);
    fraccion(string fraccion);
    fraccion operator+(fraccion fraccion2);
    fraccion operator-(fraccion fraccion2);
    fraccion operator*(fraccion fraccion2);
    fraccion operator/(fraccion fraccion2);
};

fraccion operator+(int escalar, fraccion f); 
fraccion operator-(int escalar, fraccion f); 
fraccion operator*(int escalar, fraccion f); 
fraccion operator/(int escalar, fraccion f); 

ostream& operator<<(ostream &out, fraccion f);
