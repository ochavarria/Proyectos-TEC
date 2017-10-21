#pragma once
#include "ArbolBB.h"
#include "NodoAVL.h"



class ArbolAVL:public ArbolBB
{
//Constructor
public:
	ArbolAVL(void);

//Abritutos
private:
	bool _cambioAltura;

//Metodos
public:
	//Ejectura inserBalanceado
	void insertar(int pValor,string pDato="");
	void insertar(NodoAVL* pNodo);
	string Recorridos(NodoArbol*pRaiz);
private:
	//Insertar un valor usando el algoritmo del AVL
	NodoAVL* insertarBalanceado(NodoAVL* pRaiz, NodoAVL* pNodo);
	//Rotacion Simple de AVL
	NodoAVL * rotacionSimpleIzquierda(NodoAVL* pRaiz, NodoAVL* pHijoIzquierdo);

	NodoAVL * rotacionSimpleDerecha(NodoAVL* pRaiz, NodoAVL* pHijoDerecho);
	//Rotacion Doble de AVL
	NodoAVL * rotacionDobleIzquierda(NodoAVL* pRaiz, NodoAVL* pHijoIzquierdo);

	NodoAVL * rotacionDobleDerecha(NodoAVL* pRaiz, NodoAVL* pHijoDerecho);
protected:
	// Muestra el Arbol en preorden
	void preOrden(NodoAVL* pRaiz);
	//Muestra el Arbol en InOrden
	void inOrden(NodoAVL* pRaiz);
	//Muestra el Arbol en postOrden
	void postOrden(NodoAVL* pRaiz);



};

