#pragma once
#include "NodoAVL.h"
#include "NodoAA.h"
#include "NodoRojoNegro.h"

class Palabra:public NodoAVL
{
//Constructor
public:
	Palabra(int pCodigo, string pPalabra);
//Atributos
public:
	NodoRojoNegro* definicion;
	NodoAA* sinonimo;
};