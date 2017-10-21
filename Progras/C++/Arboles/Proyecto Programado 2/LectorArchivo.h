#pragma once

#include "DatoTexto.h"
#include "InterpreteASCII.h"
#include "AdministradorArchivo.h"
#include "DatoCodigo.h"
#include "Conversor.h"
#include "DatoPalabra.h"
#include "DatoDefSin.h"

class LectorArchivo: public AdministradorArchivo
{

public:
	Conversor _conversor;

	void abrir(string pRuta);

	DatoTexto* leerTexto();
	// Lee un Codigo seguido de un ; y una palabra o letra
	DatoCodigo* leerCodigo();
	//
	DatoPalabra* leerArchivoPalabra();
	//
	DatoDefSin* leerArchivoDS();
private:

	InterpreteASCII _interprete;
	
	int buffer;
};
