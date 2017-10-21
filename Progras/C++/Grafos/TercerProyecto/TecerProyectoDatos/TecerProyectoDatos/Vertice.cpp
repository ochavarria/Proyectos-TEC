#include "Vertice.h"

Vertice::Vertice(int pDato,string pNombre)
{
	_nombre = pNombre;
	color = 0;
	gradoerror = 0;
	_valor = pDato;
	_visitado=false;
	_conexiones=nullptr;
}