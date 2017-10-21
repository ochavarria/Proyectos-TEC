#pragma once

#include "NodoArbol.h"

class NodoRojoNegro: public NodoArbol
{
//Constructor
public:
	NodoRojoNegro();
	NodoRojoNegro(int pValor);
	NodoRojoNegro(int pValor, string pDato);

//Atributos
//private:
	bool _rojo;

friend class ArbolRojoNegro;
};