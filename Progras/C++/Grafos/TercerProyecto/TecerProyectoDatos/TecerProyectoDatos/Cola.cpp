#include "Cola.h"


//Metodos Publicos

bool Cola::colaVacia()
{
	return listaVacia();
}

void Cola::insertar(Vertice* pNodo)
{
	insertarFinal(pNodo);
}

void Cola::eliminar()
{
	borrarInicio();
}

void Cola::imprimir()
{
	mostrar();
}

Vertice* Cola::extraer()
{
	primero();
	return (Vertice*)getActual();
}
