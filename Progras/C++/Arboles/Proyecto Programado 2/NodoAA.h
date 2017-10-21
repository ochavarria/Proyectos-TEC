#pragma once

#include "NodoArbol.h"

class NodoAA: public NodoArbol
{
//Constructor
public:
	NodoAA();
	NodoAA(int pValor);
	NodoAA(int pValor, string pDato);

//Atributos
private:
	int _nivel;

friend class ArbolAA;
};