#pragma once


class NodoLista
{
//Constructores
public:
	NodoLista();
	NodoLista(int pValor);
	NodoLista(int pValor, NodoLista* pNodo);

//Atributos
protected:
	int _valor;
	NodoLista* _siguiente;

	friend class ListaSimple;
	friend class Pila;
	friend class Cola;
};
