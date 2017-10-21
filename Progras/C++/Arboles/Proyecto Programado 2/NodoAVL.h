#pragma once

#include "NodoArbol.h"


class NodoAVL: public NodoArbol
{
//Constructor
public:
	NodoAVL();
	NodoAVL(int pValor);
	NodoAVL(int pValor, string pDato);

//Atributos
protected:
	int _factorBalance;

friend class ArbolAVL;
};