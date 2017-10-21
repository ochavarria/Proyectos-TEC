#pragma once

#include "NodoSimple.h"
#include <iostream>

using std::cout;
using std::endl;

class ListaSimple
{

private:
	NodoSimple* _primero;
	NodoSimple* _actual;

public:

	ListaSimple()
	{
		_primero=nullptr;
		_actual=nullptr;
	}

	void insertarInicio(string pDato);

	void insertarFinal(string pDato);

	void insertaPosicion(string pDato, int pPosicion);

	string getValorActual();

	void setPrimero(NodoSimple* pNodo);

	string getValorPosicion(int pPosicion);
		
	void primero();

	void mostrar();

	int largo();

	void borrarPosicion(int pPosicion);

	void borrarInicio();

	void borrarFinal();

	void siguiente();

	bool listaVacia();

	NodoSimple* getPrimero();
};
