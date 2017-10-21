#pragma once

#include "NodoDoble.h"

class ListaDoble
{

private:
	NodoDoble *_primero;
	NodoDoble *_actual;
	
	void insertar(NodoDoble*pNodo);

public:

	ListaDoble()
	{
		_primero = nullptr;
		_actual = nullptr;
		fin = false;
	}

	bool fin;

	void insertaPosicion(NodoDoble* pNodo, int pPosicion);

	void insertaInicio(NodoDoble* pNodo);

	void insertaFinal(NodoDoble* pNodo);

	void setActual(NodoDoble * pNodo);

	void setPrimero(NodoDoble* pNodo);

	void anterior();

	void siguiente();

	void primero();
	
	NodoDoble* getActual();

	NodoDoble* getActualPosicion(int pPosicion);

	NodoDoble* buscar(string pDato,bool pPrincipio=true);

	void eliminar(string pDato);

	void mostrar();

	int largo();

	void borrarPosicion(int pPosicion);

	void borrarInicio();

	void borrarFinal();

	void borrar(NodoDoble* pNodoBorrar);

	bool listaVacia();

	bool compararenminuscula(string pParametro1, string pParametro2);

	int hacerMinuscula(int pValor);
};
