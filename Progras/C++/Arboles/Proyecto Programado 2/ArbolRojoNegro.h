#pragma once
#include "NodoRojoNegro.h"
#include "ArbolBB.h"

class ArbolRojoNegro: public ArbolBB
{
//Constructor
public:
	ArbolRojoNegro(void);
	
//Atributos
private:
	bool _dosRojos;
	bool _derecha;

//Metodos
public:
	void insertar(int pValor,string pDato="");
	void insertar(NodoRojoNegro* pNodo);
	void Recorridos();

private:
	NodoRojoNegro* insertarRojoNegro(NodoRojoNegro* pRaiz, NodoRojoNegro* pNodo);

	void reglaTio(NodoRojoNegro* pRaiz);

	NodoRojoNegro* rotacionSimpleIzquierda(NodoRojoNegro* pRaiz,NodoRojoNegro* pHijoIzquierdo);

	NodoRojoNegro* rotacionSimpleDerecha(NodoRojoNegro* pRaiz,NodoRojoNegro* pHijoDerecho);

	NodoRojoNegro* rotacionDobleDerecha(NodoRojoNegro* pRaiz,NodoRojoNegro* pHijoDerecho);

	NodoRojoNegro* rotacionDobleIzquierda(NodoRojoNegro* pRaiz,NodoRojoNegro* pHijoIzquierdo);
	


protected:
	// Muestra el Arbol en preorden
	void preOrden(NodoRojoNegro* pRaiz);
	//Muestra el Arbol en InOrden
	void inOrden(NodoRojoNegro* pRaiz);
	//Muestra el Arbol en postOrden
	void postOrden(NodoRojoNegro* pRaiz);


};

