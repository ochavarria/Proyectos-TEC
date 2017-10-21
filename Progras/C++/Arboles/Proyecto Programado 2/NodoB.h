#pragma once
#include "Constantes.h"

class NodoB
{
//Constructor
public:
	NodoB();
//Atributos
private:
	int _claves [TAMANOCLAVES+1];
	int _cuenta;
	NodoB* _ramas [TAMANOCLAVES+1];
public:
	std::string datos[TAMANOCLAVES+1];
friend class ArbolB;
};