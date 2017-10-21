#pragma once

#include "NodoDoble.h"
#include "Entero.h"

class NodoTexto : NodoDoble 
{
public:
	NodoTexto():NodoDoble()
	{
		_separacionatras="";
	}

protected:

	string _separacionatras;
	Entero* repeticion;

	friend class Texto;
};
