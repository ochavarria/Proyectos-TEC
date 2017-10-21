#pragma once

#include "EscritorArchivo.h"
#include "LectorArchivo.h"
#include "ListaDoble.h"
#include "NodoTexto.h"

class Texto 
{

public:

	void abrirTexto(string pRuta)
	{
		texto.setPrimero(nullptr);
		_lector.abrir(pRuta);
		cargar();
		_lector.cerrar();
		ultimoModificado = nullptr;
	}

	bool modificar(string pPalabra, string pRemplazo,bool inicio);
	
	void guardar(string pRuta="Salida.txt");

	DatoTexto* getPalabraTexto(bool iniciar);

	int cantidadPalabras();

	int repeticionesPalabra(string pPalabra);

private:

	ListaDoble texto;
	LectorArchivo _lector;
	EscritorArchivo _escritor;
	NodoTexto* ultimoModificado;
	void cargar();

};
