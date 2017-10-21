#include "NodoArbol.h"
#include "Conversor.h"

NodoArbol::NodoArbol()
{
	_valor = 0;
	_dato="";
	_hijoDerecho=nullptr;
	_hijoIzquierdo=nullptr;
}
NodoArbol::NodoArbol(int pValor)
{
	_valor = pValor;
	_dato="";
	_hijoDerecho=nullptr;
	_hijoIzquierdo=nullptr;
}

NodoArbol::NodoArbol(int pValor, string pDato)
{
	_valor = pValor;
	_dato=pDato;
	_hijoDerecho=nullptr;
	_hijoIzquierdo=nullptr;
}


string NodoArbol::getDato()
{
	return _dato;
}
