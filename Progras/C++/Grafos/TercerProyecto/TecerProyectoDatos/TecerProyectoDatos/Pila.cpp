#include "Pila.h"

void Pila::push(Vertice* pNodo)
{
	insertarInicio(pNodo);
}

Vertice* Pila::pop()
{
	Vertice* resultado = (Vertice*) _primero;
	borrarInicio();
	return resultado;
}

int Pila::getTope()
{
	return _primero->_valor;
}

bool Pila::pilaVacia()
{
	return listaVacia();
}

string Pila::verPila()
{
	mostrar();
	return "";
}