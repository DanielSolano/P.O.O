

#include <iostream>
using std::cout;
using std::endl;


//En c++ existe un mecanismo llamado plantillas o templates.
//Una plantilla permite parametrizar el tipo de dato para bloques de codigo. 
// Se declara un tipo de dato generico y el codigo se programa usando este tipo de dato en donde sea pertinente. 
// Cuando se utiliza el bloque de codigo creado con template, se puede especificar que tipo de dato se aplicara al generico.

template<class T> //T es un tipo de dato generico
void Swap(T& a, T& b) {
	T t;
	t = a;
	a = b;
	b = t;
}
int main()
{
	int x = 10;
	int y = 666;
	cout << "X: " << x << "    Y:" << y << endl;
	Swap<int> (x, y);
	cout << "X: " << x << "    Y:" << y << endl;

	float o = 10.0f;
	float p = 3.1416f;
	cout << "O: " << o << "    P: " << p << endl;
	Swap<float>(o, p);
	cout << "O: " << o << "    P: " << p << endl;

	//Swap(x, o); no se puede

}

