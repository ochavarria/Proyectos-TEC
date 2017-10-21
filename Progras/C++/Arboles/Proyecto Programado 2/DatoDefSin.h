#pragma once

#include "DatoCodigo.h"

class DatoDefSin
{
//Constructor
public:
	DatoDefSin()
	{
		codigoLetra=-1;
		codigoPalabra=-1;
		dato=nullptr;
	}
//Atributos
public:
	int codigoLetra;
	int codigoPalabra;
	DatoCodigo* dato;
};