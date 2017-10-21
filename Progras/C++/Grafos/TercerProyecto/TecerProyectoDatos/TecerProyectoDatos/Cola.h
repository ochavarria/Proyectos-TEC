#pragma once

#include "NodoLista.h"
#include "ListaSimple.h"
#include "Vertice.h"


class Cola: private ListaSimple
{

	//Metodos
public:

	bool colaVacia();

	//Metodo que inserta un nodod a la cola 
	void insertar(Vertice* pNodo);

	//Metodo que elimina un nodo de la cola 
	void eliminar();

	//Metodo que imprime la cola 
	void imprimir();

	//Metodo que extrae el primero(nodo) de la cola
	Vertice* extraer();
};
