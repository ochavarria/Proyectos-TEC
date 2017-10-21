#pragma once
#include "NodoNario.h"
#include <string>

using std::string;

class ArbolNario
{
//Constructor
public:
	ArbolNario();
//Atributos
private:
	NodoNario* _raiz;
//Metodos
public:
	void insertar(int pCodigo,string pPalabra);
	int buscar(string pPalabra);
	void mostrarPreOrden();
private:
	void insertar(int pValor,NodoNario* pRaiz,int posicion,string pPalabra);
	int buscar(NodoNario* pRaiz,int posicion,string pPalabra);
	void PreOrden(NodoNario* pRaiz);
};