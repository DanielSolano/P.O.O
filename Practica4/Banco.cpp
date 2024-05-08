#include "Banco.h"

Banco::Banco(string nombre, int contador_ch, int contador_cuenta)
{
	this->nombre = nombre;
	this->contador_ch = contador_ch;
	this->contador_cuenta = contador_cuenta;
}

Banco::~Banco()
{
	for (auto& cuenta : cuentaHabientes)
	{
		delete cuenta.second;
	}
	for (auto& cuenta : cuentaCheques)
	{
		delete cuenta.second;
	}
}

CuentaHabiente* Banco::CrearCuentaHabiente(string nombre, string curp)
{
	CuentaHabiente *nuevo = new CuentaHabiente(contador_ch, nombre, curp);
	cuentaHabientes[contador_ch] = nuevo;
	contador_ch++;
	return nuevo;
}

CuentaCheques* Banco::CrearCuentaCheques(CuentaHabiente* cuenta, float saldo)
{
	CuentaCheques* nueva = new CuentaCheques(contador_cuenta, saldo);
	cuentaCheques[contador_cuenta] = nueva;
	cuenta->AgregarCuenta(nueva);
	contador_cuenta++;
	return nueva;
}

void Banco::Depositar(int cuenta, float cantidad)
{
	if (cuentaCheques.find(cuenta) != cuentaCheques.end()) {
		cuentaCheques[cuenta]->Depositar(cantidad);
	}
	else {
		cout << "CUENTA NO REGISTRADA \n";
	}
}

void Banco::Retirar(int cuenta, float cantidad)
{
	if (cuentaCheques.find(cuenta) != cuentaCheques.end()) {
		cuentaCheques[cuenta]->Retirar(cantidad);
	}
	else {
		cout << " CUENTA NO REGISTRADA \n";
	}
}

void Banco::Transferir(int origen, int destino, float cantidad)
{
	if (cuentaCheques.find(origen) != cuentaCheques.end() && cuentaCheques.find(destino) != cuentaCheques.end())
	{
		cuentaCheques[origen]->Transferir(*cuentaCheques[destino], cantidad);
	}
	else
	{
		cout << " CUENTA NO REGISTRADA \n";
	}
}

void Banco::ImprimirEstadoDeCuenta(int cuenta) const
{
	if (cuentaCheques.find(cuenta) != cuentaCheques.end())
	{
		cuentaCheques.at(cuenta)->Imprimir();
	}
	else
	{
		cout << " CUENTA NO REGISTRADA \n";
	}
}

void Banco::ImprimirReporteDeCuentas(CuentaHabiente* cuenta) const
{
	if (cuenta != nullptr)
	{
		cuenta->ImprimirCuentas();
	}
	else
	{
		cout << " CUENTA NO REGISTRADA \n ";
	}
	
}

CuentaCheques* Banco::GetCuentaCheques(int cuenta) const
{
	if (cuentaCheques.find(cuenta) != cuentaCheques.end())
	{
		return cuentaCheques.at(cuenta);
	}
	else
	{
		cout << " CUENTA NO REGISTRADA \n";
		return nullptr;
	}
}

CuentaHabiente* Banco::GetCuentaHabiente(int cuenta) const
{
	if (cuentaHabientes.find(cuenta) != cuentaHabientes.end())
	{
		return cuentaHabientes.at(cuenta);
	}
	else
	{
		cout << " CUENTA NO REGISTRADA \n";
		return nullptr;
	}
}