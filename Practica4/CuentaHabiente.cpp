#include "CuentaHabiente.h"
#include <iostream>
using std::cout;
using std::endl;

CuentaHabiente::~CuentaHabiente()
{
	cout << "Ejecutando destructor de cuenta habiente " << nombre << endl;
}

CuentaHabiente::CuentaHabiente(int numeroCH, string nombre, string curp)
{
	this->numeroCH = numeroCH;
	this->nombre = nombre;
	this->curp = curp;
}

void CuentaHabiente::AgregarCuenta(CuentaCheques* cuenta)
{
		cuentasCheques.push_back(cuenta);
}

void CuentaHabiente::ImprimirCuentas() const
{
	cout << "Cuenta habiente: " << nombre << endl;
	cout << "Numero de cuenta habiente: " << numeroCH << endl;
	cout << "CURP: " << curp << endl;
	for (int i = 0; i < cuentasCheques.size() ; i++)
	{
		cuentasCheques[i]->Imprimir();
	}
}
