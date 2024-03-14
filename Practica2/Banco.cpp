#include "Banco.h"
#include <string>
#include <iostream>
#include <time.h>

using std::cout;
using std::endl;
using std::string;

void CuentaDeCheques::Transferencia(CuentaDeCheques &destino, float cantidad)
{
    if (cantidad > Saldo) // No hay fondos suficientes
    {
        cout << " SALDO INSUFICIENTE / TRANSFERENCIA CANCELADA" << endl;
    }
    else
    {
        destino.SetSaldo(destino.Saldo = destino.Saldo + cantidad);
        Saldo = Saldo - cantidad;
        destino.SetTransaccion();
        time_t tm = time(0);
        char *fecha = ctime(&tm);
        UltimaTransaccion = fecha;
    }
}

void CuentaDeCheques::ImprimirEstadoCuenta()
{
    cout << "Propietario: " << Propietario << endl;
    cout << "Numero de cuenta: " << NumeroDeCuenta << endl;
    cout << "Saldo: " << Saldo << endl;
    cout << "Fecha ultima transaccion: " << UltimaTransaccion << endl;
}

void CuentaDeCheques::SetTransaccion(void)
{

    time_t tm = time(0);
    char *fecha = ctime(&tm);
    UltimaTransaccion = fecha;
}

CuentaDeCheques::~CuentaDeCheques()
{
    cout << "Ejecutando destructor de la cuenta " << NumeroDeCuenta << endl;
}

CuentaDeCheques::CuentaDeCheques(char *numeroDeCuenta, char *propietario, float saldo)
{
    // Utilizando string podemos copiar cadenas con '='
    NumeroDeCuenta = numeroDeCuenta;
    Propietario = propietario;
    Saldo = saldo;
    time_t tm = time(0);
    char *fecha = ctime(&tm);
    UltimaTransaccion = fecha;
}

void CuentaDeCheques::DepositarDinero(float cantidad)
{
    Saldo = Saldo + cantidad;
    time_t tm = time(0);
    char *fecha = ctime(&tm);
    UltimaTransaccion = fecha;
}

void CuentaDeCheques::RetirarDinero(float cantidad)
{
    if (cantidad > Saldo) // No hay fondos suficientes
    {
        cout << " SIN FONDOS DISPONIBLES PARA RETIRO DE: " << cantidad << endl;
    }
    else
    {
        Saldo = Saldo - cantidad;
        time_t tm = time(0);
        char *fecha = ctime(&tm);
        UltimaTransaccion = fecha;
    }
}
