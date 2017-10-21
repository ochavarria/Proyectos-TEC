#include "NodoAA.h"
NodoAA::NodoAA():NodoArbol()
{
	_nivel=1;
}

NodoAA::NodoAA(int pValor):NodoArbol(pValor)
{
	_nivel=1;
}

NodoAA::NodoAA(int pValor, string pDato):NodoArbol(pValor,pDato)
{
	_nivel=1;
}