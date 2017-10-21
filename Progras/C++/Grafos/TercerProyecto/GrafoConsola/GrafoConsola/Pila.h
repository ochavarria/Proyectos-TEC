#pragma once

#include "ListaSimple.h"
#include "Vertice.h"

class Pila: ListaSimple
{
public:
	//Metodo que ingresa un valor a la pila
	void push(Vertice* pNodo);

	//Metodo que saca un valor de la pila
	Vertice* pop();

	//Metodo que devuelve el tope de la pila
	string getTope();

	//Pregunta si la pila esta vacia
	bool pilaVacia();

	//Envia la pila en formato string separada por ,
	string verPila();
};

