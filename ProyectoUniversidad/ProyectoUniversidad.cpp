#include <iostream>
#include "Materia.h"
#include "Universidad.h"
#include "MenuI.h"

#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

Universidad uni;

void Inicializar()
{

	uni.RegistrarEstudiante("Solano Meza", "Tronco comun");
	uni.RegistrarEstudiante("Sandez Danna", "Sociologia");
	uni.RegistrarEstudiante("Haro Fernanado", "Vida");
	uni.RegistrarEstudiante("Odin Gosky", "Techo");

	uni.ReporteEstudiantes();

	uni.RegistrarMateria("Calculo Diferencial", 7);
	uni.RegistrarMateria("Algebra Superior", 7);
	uni.RegistrarMateria("Metodologia de la programacion", 4);
	uni.RegistrarMateria("Comunicacion Oral y Escrita", 4);
	uni.RegistrarMateria("Introduccion a la ingenieria", 4);
	uni.RegistrarMateria("Desarrollo profesional del ingeniero", 3);
	uni.RegistrarMateria("Calculo Integral", 7);

	uni.ReporteMaterias();

	uni.RegistrarCalificacion(333001, 40001, 90);
	uni.RegistrarCalificacion(333001, 40002, 90);
	uni.RegistrarCalificacion(333001, 40003, 90);
	uni.RegistrarCalificacion(333001, 40004, 90);
	uni.RegistrarCalificacion(333001, 40005, 90);
	uni.RegistrarCalificacion(333001, 40006, 90);
	uni.RegistrarCalificacion(333001, 40007, 90);
}

void ReporteEstudiantes()
{
	uni.ReporteEstudiantes();
}

void ReporteMaterias()
{
	uni.ReporteMaterias();
}

void ImpresionKardex()
{
	int matricula;
	cout << "Impresio de kardex\n \n Matricula: ";
	cin >> matricula;
	cout << uni.GetKardex(matricula).ToString() << endl;
}

void AltaEstudiante()
{
	cout << "No implementado ... " << endl;
}

void AltaCalificacion()
{
	cout << "No implementado ... " << endl;
}

void AltaMateria()
{
	int matricula, clave, valor;
	cout << "Alta de calificacion\n\nMatricula: ";
	cin >> matricula;
	cout << "Clave de materia";
	cout << "No implementado ... " << endl;
}

int main()
{
	Inicializar();
	MenuI menu("Super sistema universitario");
	menu.AgregarOpcion({'1', "Reporte de Estudiantes", ReporteEstudiantes});
	menu.AgregarOpcion({'2', "Catologo de Materias", ReporteMaterias});
	menu.AgregarOpcion({'3', "Imprimir Kardex", ImpresionKardex});
	menu.AgregarOpcion({'4', "Registrar Materia", AltaMateria});
	menu.AgregarOpcion({'5', "Registrar Estudiante", AltaEstudiante});
	menu.AgregarOpcion({'5', "Registrar Calificacion", AltaCalificacion});
	menu.AgregarOpcion({'6', "Salir", [](){}});
}