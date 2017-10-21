#pragma once

#include "NodoLista.h"

class Vertice: public NodoLista
{
//Constructor
public:
	Vertice(string pDato);
//Atributos
protected:
	bool _visitado;
	NodoLista* _conexiones;

	friend class Grafo;
	friend class ListaSimple;
};