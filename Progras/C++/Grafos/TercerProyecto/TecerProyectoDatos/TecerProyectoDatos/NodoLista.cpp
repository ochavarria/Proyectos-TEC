#include "NodoLista.h"

//Constructores
NodoLista::NodoLista()
{
	_valor = 0;
	_siguiente = nullptr;
}

NodoLista::NodoLista(int pValor)
{
	_valor = pValor;
	_siguiente = nullptr;
}

NodoLista::NodoLista(int pValor, NodoLista* pNodo)
{
	_valor = pValor;
	_siguiente = pNodo;
}
