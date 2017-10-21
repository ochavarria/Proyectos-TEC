#pragma once
#include <string>

using std::string;

class NodoArbol
{
public:
	NodoArbol();
	NodoArbol(int pValor);
	NodoArbol(int pValor, string pDato);

	string getDato();
protected:
	int _valor;
	string _dato;
	
	NodoArbol* _hijoDerecho;
	NodoArbol* _hijoIzquierdo;


friend class ArbolBB;
friend class ArbolAA;
friend class Diccionario;

};

