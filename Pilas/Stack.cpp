#include "Stack.h"
template<class T>
Stack<T>::~Stack()
{
	Clear();
}

template<class T>
void Stack<T>::Push(T dato)
{
	struct nodo* nuevo = new struct nodo;
	if (nuevo == nullptr)
		throw "Memoria insuficiente...";
	nuevo->dato = dato;
	nuevo->prev = top;
	top= nuevo;
}
template<class T>
T Stack<T>::Pop()
{
	if (top == nullptr)//pila vacia
		throw "Underflow error...";
	auto aux = top;
	top = top->prev;
	T val = aux->dato;
	delete aux;
	return val;
}
template<class T>
void Stack<T>::Clear()
{
	// TODO: Add your implementation code here.
	struct nodo* aux;
	while (top != nullptr) {
		aux = top;
		top = top->prev;
		delete aux;
	}
}
template<class T>
T Stack<T>::Peek()
{
	if(top==nullptr)
		throw "Underflow error...";
	return top->dato;
}
