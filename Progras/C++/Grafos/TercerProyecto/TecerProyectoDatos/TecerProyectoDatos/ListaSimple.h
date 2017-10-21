#pragma once

#include "NodoLista.h"
#include <iostream>
#include "Arco.h"

using std::cout;
using std::endl;

class ListaSimple
{
//Contructor de la clase
public:
	
	ListaSimple();
	~ListaSimple();
//Atributos
protected:
	NodoLista* _primero;
	NodoLista* _actual;
	int _largoLista;

//Metodos
public:
	//Inserta un valor al principio de la lista
	void insertarInicio(int pValor);
	//Inserta un nodo al principio de la lista
	void insertarInicio(NodoLista* pValor);
	//Inserta un valor al final de la lista
	void insertarFinal(int pValor);
	//Inserta un nodo al final de la lista
	void insertarFinal(NodoLista* pValor);
	//Inserta un valor en una determinada posicion de la lista
	void insertarPos(int pValor, int pPosicion);

	//Busca un elemento en la lista
	NodoLista* buscar(int pDato);
	
	//Devuelve la pos del elemento***
	Arco* buscarConexion(int pPeso, Vertice* inicio, Vertice* fin);
	//Devuelve un arco***
	NodoLista* buscarVertice(Vertice* pDato);



	//Muestra la lista
	void mostrar();

	//Poner al _Actual de la lista en el siguiente de la lista
	void siguiente();
	//Poner al _Actual de la lista en el primero de la lista
	void primero();
	//Poner al _Actual de la lista en el ultimo de la lista
	void ultimo();

	//Borra un valor al final de la lista
	void borrarFinal();
	//borra un valor al principio de la lista
	void borrarInicio();
	//Borra un valor en una posicion determinada de la lista
	void borrarPosicion(int pPosicion);

	//borrra una conexion***
	void borrarConexion(Arco* Conexion);

	//Dice la cantidad de nodos o elementos que tiene la lista 
	int largoLista();
	//Dice si la lista esta vacia o no 
	bool listaVacia();

	//inserta un elemento en la lista de los vertices ordenados *****
	void InsertarEnlistaVertices(NodoLista* pValor);
	
	//*****
	void NEXT();


	//Buscar Vertice en un arco ****
	Arco* VerticeEnArco(Vertice* vertice);


	//Devuleve el valor actual de la lista 
	int getValorActual();
	//Obtine el nodo de actual
	NodoLista* getActual();

	//obtiene el primero**
	NodoLista* getPrimero();

	//Poner un nodo de primero en la lista
	void setPrimero(NodoLista* parNodo);
	// Los atritutos de la lista
};