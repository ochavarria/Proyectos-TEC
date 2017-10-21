#include "Arco.h"

Arco::Arco(int pPeso, Vertice* inicio, Vertice* fin):NodoLista(0)
{
	_peso=pPeso;
	_incio=inicio;
	_fin = fin;
}