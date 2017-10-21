#pragma once
#include "NodoArbol.h"
#include "NodoAVL.h"

class Letra: public NodoArbol
{
//Constructor
public:
	Letra(int pCodigo,string pLetra);
//Atributos
	NodoAVL* palabras;

	
};