#pragma once

#include <string>
using  std::string;

class NodoDoble 
{
public:
	NodoDoble()
	{
		_dato = "";
		_siguiente = this;
		_anterior = this;

	}

	NodoDoble(string pDato)
	{
		_dato = pDato;
		_siguiente = this;
		_anterior = this;
	}

protected:
	
	NodoDoble* _siguiente;
	NodoDoble* _anterior;
	string _dato;

	friend class ListaDoble;
};
