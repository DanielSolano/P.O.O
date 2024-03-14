#include "Banco.h"
#include "Persona.h"
#include <iostream>
#include <time.h>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    Persona danna("Danna", 19);
    Persona miti("Miti", 19);
    Persona haro("Haro", 19);

    CuentaDeCheques cuenta1("372453", miti.GetNombre(), 2000);
    cuenta1.ImprimirEstadoCuenta();
    cuenta1.DepositarDinero(50);
    cuenta1.ImprimirEstadoCuenta();
    cuenta1.RetirarDinero(50);
    cuenta1.ImprimirEstadoCuenta();
    CuentaDeCheques cuenta2("373080", danna.GetNombre(), 1000);
    cuenta2.ImprimirEstadoCuenta();
    cuenta1.Transferencia(cuenta2, 2001);
    cuenta1.ImprimirEstadoCuenta();
    cuenta2.ImprimirEstadoCuenta();
    CuentaDeCheques cuenta3("372106", haro.GetNombre(), 10);
    cuenta3.RetirarDinero(100);
    cuenta3.ImprimirEstadoCuenta();
    cuenta3.DepositarDinero(100);
    cuenta3.ImprimirEstadoCuenta();
    cuenta3.RetirarDinero(110);
    cuenta3.ImprimirEstadoCuenta();
    cuenta2.Transferencia(cuenta3, 1000);
    cuenta3.ImprimirEstadoCuenta();

    return 0;
}
