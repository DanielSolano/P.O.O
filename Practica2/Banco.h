#pragma once
#include <string>

using std::string;

class CuentaDeCheques
{

private:
    string NumeroDeCuenta;
    string Propietario;
    string UltimaTransaccion;
    float Saldo;

public:
    CuentaDeCheques(char *numeroDeCuenta, char *propietario, float saldo);
    void DepositarDinero(float cantidad);
    void RetirarDinero(float cantidad);
    void Transferencia(CuentaDeCheques &destino, float cantidad);
    void ImprimirEstadoCuenta(void);
    float GetSaldo(void)
    {
        return Saldo;
    }
    void SetSaldo(float nuevo_saldo)
    {
        Saldo = nuevo_saldo;
    }
    void SetTransaccion(void);
    ~CuentaDeCheques();
};