#pragma once

#include "InterpreteASCII.h"
#include "AdministradorArchivo.h"
#include "Conversor.h"
#include "Punto.h"
#include "Pais.h"
#include "Conexion.h"

class LectorArchivo: public AdministradorArchivo
{

public:
	LectorArchivo()
	{
		conversor = new Conversor();
	}
	
	Conversor* conversor;
	bool cambioLinea;
	
	void abrir(string pRuta);
	Punto* leerPunto();
	Pais* leerPais();
	Conexion* leerConexion();
	
private:

	InterpreteASCII _interprete;

	int buffer;
};
