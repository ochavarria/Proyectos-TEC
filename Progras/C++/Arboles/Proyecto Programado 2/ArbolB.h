#pragma once
#include "NodoB.h"
#include "Conversor.h"
using std::string;

class ArbolB 
{
	//Constructor
public:
	ArbolB(void);

	//Abritutos
private:
	NodoB* _raiz;
	bool _empujaArriba;
	bool _esta;
	int _mediana;
	string _dato;
	int k;

	NodoB* _hijoDer;
	NodoB* _raizAux;

	string _recorrido;
//Metodos
public:
	string buscar(int pValor);
	void mostrarPreOrden();
	void insertar(int pValor, string pDato="");
	//Ejectura inserBalanceado
	void Recorridos();

private:
	
	void empujar(int pValor, NodoB* pRaiz, string pDato);
	string buscar(int pValor, NodoB* pRaiz);
	void limpiarNodo(NodoB* pRaiz);
	void Inorden();
	void PreOrden(NodoB* pRaiz);
	void BuscarNodo(int pValor, NodoB* pRaiz);
	void MeterHoja(int pValor, NodoB* pHijoDer, NodoB* pRaiz, string pDato);
	void DividirNodo(int pValor, NodoB* pHijoDer, NodoB* pRaiz, int pPosicion, string pDato);

};