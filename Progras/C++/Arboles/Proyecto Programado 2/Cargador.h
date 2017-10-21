#pragma once
#include "LectorArchivo.h"
#include "NodoArbol.h"
#include "ArbolBB.h"
#include "Letra.h"
#include "ArbolNario.h"

class Cargador
{
//Constructor
//Atributos
public:
	ArbolNario _codigos;
private:
	LectorArchivo _lector;
//Metodos
public:
	NodoArbol* cargarAbecedario();
	
};