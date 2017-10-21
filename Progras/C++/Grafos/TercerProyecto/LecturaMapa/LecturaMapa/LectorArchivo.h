#pragma once

#include "InterpreteASCII.h"
#include "AdministradorArchivo.h"
#include "Conversor.h"
#include "Punto.h"

class LectorArchivo: public AdministradorArchivo
{

public:
	LectorArchivo()
	{
		conversor = new Conversor();
	}

	bool nuevoPais;
	void abrir(string pRuta);

	Punto* leerPunto();

	Conversor* conversor;
private:

	InterpreteASCII _interprete;

	int buffer;
};
