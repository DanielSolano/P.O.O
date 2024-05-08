#define _CRT_SECURE_NO_WARNINGS 

#include "CuentaCheques.h"
#include <iostream>
#include <time.h>

using std::string;
using std::cout;
using std::endl;


CuentaCheques::~CuentaCheques()
{
    cout << "Ejecutando destructor de la cuenta " << numeroCuenta << endl;
}

CuentaCheques::CuentaCheques(int numeroDeCuenta, float saldo)
{
    numeroCuenta = numeroDeCuenta;
    this->saldo = saldo;
    time_t tm = time(0);
    char* fecha = ctime(&tm);
    fechaUltimoMovimiento = fecha;
}

void CuentaCheques::Transferir(CuentaCheques& destino, float cantidad)
{
    if (cantidad > saldo) // No hay fondos suficientes
    {
        cout << " SALDO INSUFICIENTE / TRANSFERENCIA CANCELADA" << endl;
    }
    else
    {
        destino.SetSaldo(destino.saldo = destino.saldo + cantidad);
        saldo = saldo - cantidad;
        destino.SetTransaccion();
        time_t tm = time(0);
        char* fecha = ctime(&tm);
        fechaUltimoMovimiento = fecha;
        cout << " TRANSFERENCIA REALIZADA" << endl;
    }
}

void CuentaCheques::Imprimir() const
{
    cout << "Numero de cuenta: " << numeroCuenta<< endl;
    cout << "Saldo: " << saldo << endl;
    cout << "Fecha ultima transaccion: " << fechaUltimoMovimiento<< endl;
}


void CuentaCheques::Depositar(float cantidad)
{
    saldo = saldo + cantidad;
    time_t tm = time(0);
    char* fecha = ctime(&tm);
    fechaUltimoMovimiento = fecha;
    cout << " DEPOSITO REALIZADO CON EXITO " << endl;
}

void CuentaCheques::Retirar(float cantidad)
{   
    if (cantidad > saldo) // No hay fondos suficientes
    {
        cout << " SIN FONDOS DISPONIBLES PARA RETIRO DE: " << cantidad << endl;
    }
    else
    {
        saldo = saldo - cantidad;
        time_t tm = time(0);
        char* fecha = ctime(&tm);
        fechaUltimoMovimiento = fecha;
        cout << " RETIRO REALIZADO CON EXITO " << endl;
    }
}

void CuentaCheques::SetTransaccion(void)
{
    time_t tm = time(0);
    char* fecha = ctime(&tm);
    fechaUltimoMovimiento = fecha;
}
