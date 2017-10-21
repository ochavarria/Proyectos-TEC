#pragma once

#include "ListaSimple.h"
#include "Arco.h"
#include "Vertice.h"
#include <list>
#include <vector>
using std::vector;

#include <iostream>

#include <list>
using namespace std;

class Grafo
{
//Constructor
public:
	Grafo();
//Atributos

	ListaSimple* _listaDeAyacencia;
private:	
	ListaSimple* _admistradradorArcos;
	vector<Vertice*> _listaGrado;
	enum TIPORECORRIDO{ANCHURA,PROFUNDIDA};
//Metodos
public:
	void agregarConexion(int pInicio,int pFin, int pPeso=0,bool doble=false);
	void agregarNodo(Vertice* pDato);
	
	void recorrido(int tipo);
	void recorridoProfundidad();
	void recorridoAnchura();
	
	void borrarConexion(int pInicio, int pFin, int pPeso);
	void borrarNodo(string pDato);



	void mostrar();

	void mostrarGrafo();

	void colorear();
		
	//Metodos para prim
	void algoritmoDePrim();
	Arco* ConexionMenor(Vertice* vertice);
	Arco* BuscarValorMin();
	void ElimiarCiclo();
	void VerConexiones(Vertice* vertice);
	bool  Arconulo(Arco* arco);
	bool TodosNodosVisitados();

	//Metodos para kruskal
	void algoritomoDeKruskal();
	Arco* VerticeMinConexion();

	bool Siconexion(list<int> ListaVerticesConectados[11], int inicio, int fin);
	void AgregarAPosVacia(list<int> ListaVerticesConectados[11], int incio, int fin);
	bool Esta(list<int>ListaVerticesConectados[11], int valor, int pos);



private:
	void ordenarPorGrado();
	void ordenamiento();
	void grado();
	void gradoError();
	bool pintar(Vertice* pVertice);
	void insertarSegunTipo(Vertice* pVertice,int pTipo,Cola* pCola,Pila* pPila);
	void desvisitar();
	void despintar();
	


};