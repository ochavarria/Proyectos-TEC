#include "NodoAVL.h"

//Constructor
NodoAVL::NodoAVL():NodoArbol()
{
	_factorBalance=0;
}

NodoAVL::NodoAVL(int pValor):NodoArbol(pValor)
{
	_factorBalance=0;
}

NodoAVL::NodoAVL(int pValor, string pDato):NodoArbol(pValor,pDato)
{
	_factorBalance=0;
}
