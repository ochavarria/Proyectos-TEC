#pragma once

#include "NodoAA.h"
#include "ArbolBB.h"

class ArbolAA:public ArbolBB
{
//Constructor
//Atributos
//Metodos
public:
	void insertar(int pValor,string pDato="");
	void insertar(NodoAA* pNodo);
	void Recorridos();
private:

	NodoArbol* insertarAA(NodoArbol* pRaiz, NodoAA* pNodo);
	NodoArbol* giro(NodoArbol* pRaiz);
	NodoArbol* reparto(NodoArbol* pRaiz);
	bool hayTresEnMismoNivel(NodoArbol* pRaiz);
protected:
	// Muestra el Arbol en preorden
	void preOrden(NodoAA* pRaiz);
	//Muestra el Arbol en InOrden
	void inOrden(NodoAA* pRaiz);
	//Muestra el Arbol en postOrden
	void postOrden(NodoAA* pRaiz);


};