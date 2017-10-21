#pragma once

#include "NodoLista.h"
#include "Vertice.h"

class Arco:public NodoLista
{
//Constructor
public:
	Arco(int pPeso,Vertice* inicio,Vertice* fin);
//Atributos
protected:
	int _peso;
	Vertice* _incio;
	Vertice* _fin;
friend class Grafo;
friend class ListaSimple;
};