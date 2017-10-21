#include "EscritorArchivo.h"

void EscritorArchivo::abrir(string pRuta, bool pSobrescitura)
{
	if (pSobrescitura)
		_administrador.open(pRuta, fstream::out);
	else
		_administrador.open(pRuta, fstream::app);
}

void EscritorArchivo::escribir(string pDato)
{
	_administrador << pDato;
}