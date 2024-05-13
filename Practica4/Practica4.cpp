#include <iostream>
#include "Banco.h"
#include "Menu.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    Banco *el_banco = new Banco("Nu", 0, 0);

    CuentaHabiente* miti = el_banco->CrearCuentaHabiente("Miti", "SOMA041228HBCLZNA0");
    CuentaHabiente* danna = el_banco->CrearCuentaHabiente("Danna", "SAIJ041108MBCNSNA3");
    CuentaHabiente* haro = el_banco->CrearCuentaHabiente("Haro", "HARO040126HBCCLA1");

    CuentaCheques* cuentaMiti = el_banco->CrearCuentaCheques(miti, 1000);
    CuentaCheques* cuentaMiti2 = el_banco->CrearCuentaCheques(miti, 1000);
    CuentaCheques* cuentaDanna = el_banco->CrearCuentaCheques(danna, 1000);
    CuentaCheques* cuentaHaro = el_banco->CrearCuentaCheques(haro, 1000);

    Menu menu("Nu");
    menu.AgregarOpcion({ '1', "Deposito", [&]()
                  {
                          int cuenta;
                          float cantidad;

                          cout << "Ingrese el numero de cuenta: ";
                          cin >> cuenta;
                          cout << "Ingrese la cantidad a depositar: ";
                          cin >> cantidad;
                          el_banco->Depositar(cuenta, cantidad);
                          getchar();
                          getchar();
                  } });

    menu.AgregarOpcion({ '2', "Retiro", [&]()
                  {
                          int cuenta;
                          float cantidad;
                          cout << "Ingrese el numero de cuenta: ";
                          cin >> cuenta;
                          cout << "Ingrese la cantidad a retirar: ";
                          cin >> cantidad;
                          el_banco->Retirar(cuenta, cantidad);
                          getchar();
                          getchar();
                  } });

    menu.AgregarOpcion({ '3', "Transferencia", [&]()
                  {
                          int cuenta_origen, cuenta_destino;
                          float cantidad;

                          cout << "Ingrese el numero de cuenta origen: ";
                          cin >> cuenta_origen;
                          cout << "Ingrese el numero de cuenta destino: ";
                          cin >> cuenta_destino;
                          cout << "Ingrese la cantidad a transferir: ";
                          cin >> cantidad;
                          el_banco->Transferir(cuenta_origen, cuenta_destino, cantidad);
                          getchar();
                          getchar();
                   } });

    menu.AgregarOpcion({ '4', "Imprimir Cuenta", [&]()
                  { 
                        int cuenta;
                        cout << "Ingrese el numero de cuenta: ";
                        cin >> cuenta;
                        el_banco->ImprimirEstadoDeCuenta(cuenta);
                    	getchar();
                        getchar();
                  } });
    menu.AgregarOpcion({ '5', "Imprimir Reporte", [&]()
                  {
                      int cuenta; 
                      cout << "Ingrese el numero de cuenta habiente: ";
                      cin >> cuenta;
                      el_banco->ImprimirReporteDeCuentas(el_banco->GetCuentaHabiente(cuenta));
                      getchar();
                      getchar();
                  } });

    menu.AgregarOpcion({ '6', "Salir", [&]()
                  {
                      delete el_banco;
                      cout << " ADIOS " << endl;
                      getchar();
                  } });

    menu.Ejecutar();
}