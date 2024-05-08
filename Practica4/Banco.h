#pragma once
#include "CuentaHabiente.h"
#include <string>
#include <iostream>
#include <map>

using std::map;
using std::string;
using std::cout;
using std::endl;

class Banco
{
private:
	string nombre;
	int contador_ch;
	int contador_cuenta;
	map<int, CuentaHabiente*> cuentaHabientes;
	map<int, CuentaCheques*> cuentaCheques;
public:
	~Banco();
	Banco(string nombre, int contador_ch = 10001, int contador_cuenta = 01016211440);
	CuentaHabiente* CrearCuentaHabiente(string nombre, string curp);
	CuentaCheques* CrearCuentaCheques(CuentaHabiente* cuenta, float saldo);

	CuentaHabiente* GetCuentaHabiente(int cuenta) const;
	CuentaCheques* GetCuentaCheques(int cuenta) const;

	void Depositar(int cuenta, float cantidad);
	void Retirar(int cuenta, float cantidad);
	void Transferir(int origen, int destino, float cantidad);
	void ImprimirEstadoDeCuenta(int cuenta) const;
	void ImprimirReporteDeCuentas(CuentaHabiente* cuenta) const;
};

