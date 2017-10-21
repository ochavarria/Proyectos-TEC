#pragma once

#include "ListaSimple.h"
#include "Arco.h"
#include "Vertice.h"
#include <iostream>

#include <list>
using namespace std;
class Grafo
{
//Constructor
public:
	Grafo();
//Atributos
private:
	ListaSimple* _listaDeAyacencia;
	ListaSimple* _admistradradorArcos;
	enum TIPORECORRIDO{ANCHURA,PROFUNDIDA};
//Metodos
public:
	void agregarConexion(string pInicio,string pFin, int pPeso,bool doble=false);
	void agregarNodo(string pDato);
	
	void recorrido(int tipo);
	void recorridoProfundidad();
	void recorridoAnchura();
	
	void borrarConexion(string pInicio, string pFin, int pPeso);
	void borrarNodo(string pDato);
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

	//Arco* RevisarConexiones(Vertice* Conexion);
	//bool EncontrarConexion(Vertice* Inicio, Vertice* Final);
	//Arco* CrearConexion(Arco* Conexion, Vertice* VerticeCambio, Vertice* VerticeComparar);
	//bool ComparaConexiones(Arco* conexion, Arco* Ciclo);

	bool Siconexion(list<string> ListaVerticesConectados[11], string inicio, string fin);
	void AgregarAPosVacia(list<string> ListaVerticesConectados[11], string incio, string fin);
	bool Grafo::Esta(list<string>ListaVerticesConectados[11], string valor,int pos);

	void mostrar();
private:
	void insertarSegunTipo(Vertice* pVertice,int pTipo,Cola* pCola,Pila* pPila);

};