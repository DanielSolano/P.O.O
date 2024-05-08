#pragma once
#include <string>

using std::string;

class CuentaCheques
{
private:
	float saldo;
	int numeroCuenta;
	string fechaUltimoMovimiento;
public:
    CuentaCheques(int numeroDeCuenta, float saldo);
    ~CuentaCheques();
    void Depositar(float cantidad);
    void Retirar(float cantidad);
    void Transferir(CuentaCheques& destino, float cantidad);
    void Imprimir(void) const;
    float GetSaldo(void)
    {
        return saldo;
    }
    void SetSaldo(float nuevo_saldo)
    {
        saldo = nuevo_saldo;
    }
    void SetTransaccion(void);
};

