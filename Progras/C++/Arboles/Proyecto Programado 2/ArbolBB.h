#pragma once;

#include "NodoArbol.h"
#include "Conversor.h"

class ArbolBB
{
//Constructor
public:
	ArbolBB(void);

//Atributos	
protected:
	NodoArbol* _raiz;
	string recorrido;
	Conversor conversor;

//Metodos
public:
	//Cambia el valor de la raiz
	void setRaiz(NodoArbol* pRaiz);
	NodoArbol* getRaiz();
	//Busca el valor solicitado
	NodoArbol * buscar(int pValor, bool Guardar);
	//Ejecuta el insertado iniciando en la raiz
	void insertar(int pValor,string pDato="");
	//Ejecuta el insertado iniciando en la raiz
	void insertar(NodoArbol* pNodo);
	//Ejecuta el preorden del arbol iniciando en la raiz
	void mostrarPreOrden();
	//Ejecuta el inorden del arbol iniciando en la raiz
	void mostrarInOrden();
	//Ejecuta el postOrden del arbol inciando en la raiz
	void mostrarPostOrden();
	//Ejecuta los 3 recorridos del arbol inciando en la raiz
	void Recorridos();

private:
	NodoArbol* buscarAuxiliar(NodoArbol* pRaiz, int pValor, bool Guardar);
	// Muestra el Arbol en preorden
	void preOrden(NodoArbol* pRaiz);
	//Muestra el Arbol en InOrden
	void inOrden(NodoArbol* pRaiz);
	//Muestra el Arbol en postOrden
	void postOrden(NodoArbol* pRaiz);
	
	NodoArbol* insertarOrdenado(NodoArbol* pRaiz, NodoArbol* pNodo);
};

