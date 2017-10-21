#pragma once

#include <string>
using  std::string;

class NodoSimple 
{
public:
	NodoSimple(string pDato)
	{
		_dato = pDato;
		_siguiente = nullptr;
	}
	NodoSimple(string pDato, NodoSimple* pNodo)
	{
		_dato = pDato;
		_siguiente = pNodo;
	}

protected:
	string _dato;
	NodoSimple* _siguiente;

	friend class ListaSimple;
};