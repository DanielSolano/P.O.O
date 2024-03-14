#pragma once
template<class T>
class Stack
{
	struct nodo {
		T dato;
		struct nodo* prev = nullptr;
	};
	struct nodo* top = nullptr;
public:
	~Stack();
	void Push(T dato);
	T Pop();
	bool IsEmpty() {return (top == nullptr);}
	void Clear();
	T Peek();
};

