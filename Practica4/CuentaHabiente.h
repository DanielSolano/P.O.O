#pragma once
#include <string>
#include <vector>
#include "CuentaCheques.h"

using std::vector;
using std::string;

class CuentaHabiente
{
private:
	int numeroCH;
	string nombre;
	string curp;
	vector<CuentaCheques*> cuentasCheques;
public:
	~CuentaHabiente();
	CuentaHabiente(int numeroCH, string nombre, string curp);
	vector<CuentaCheques*> ObtenerCuentas() const { return cuentasCheques; };
	int GetNumeroCH() const { return numeroCH; };	
	void AgregarCuenta(CuentaCheques* cuenta);
	void ImprimirCuentas() const;
};

