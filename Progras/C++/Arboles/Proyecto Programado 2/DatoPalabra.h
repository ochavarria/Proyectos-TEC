#pragma once

#include "DatoCodigo.h"

class DatoPalabra
{
//Constructor
public:
	DatoPalabra()
	{
		codigoLetra=-1;
		dato=nullptr;
	}
//Atributo
public:
	int codigoLetra;
	DatoCodigo* dato;
};