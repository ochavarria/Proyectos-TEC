#include "ArbolAA.h"
#include <iostream>
#include "Constantes.h"
#include "EscritorArchivo.h"

void ArbolAA::insertar(int pValor, string pDato)
{
	NodoAA* pNodo = new NodoAA(pValor,pDato);
	_raiz=insertarAA(_raiz,pNodo);
}

void ArbolAA::insertar(NodoAA* pNodo)
{
	_raiz=insertarAA(_raiz,pNodo);
}

NodoArbol* ArbolAA::insertarAA(NodoArbol* pRaiz, NodoAA* pNodo)
{
	if(pRaiz==nullptr)
		return pNodo;
	else
	{
		if(pNodo->_valor<=pRaiz->_valor)
		{
			pRaiz->_hijoIzquierdo=insertarAA(pRaiz->_hijoIzquierdo,pNodo);
			auto raiz = (NodoAA*)pRaiz;
			auto hijoIzquierdo = (NodoAA*)pRaiz->_hijoIzquierdo;
			if(raiz->_nivel<=hijoIzquierdo->_nivel)
				pRaiz=giro(pRaiz);
		}
		else
			pRaiz->_hijoDerecho=insertarAA(pRaiz->_hijoDerecho,pNodo);

		if(hayTresEnMismoNivel(pRaiz))
			pRaiz=reparto(pRaiz);
		
		return pRaiz;
	}
}

NodoArbol* ArbolAA::giro(NodoArbol* pRaiz)
{
	auto auxiliar = pRaiz->_hijoIzquierdo->_hijoDerecho;
	pRaiz->_hijoIzquierdo->_hijoDerecho=pRaiz;
	pRaiz=pRaiz->_hijoIzquierdo;
	pRaiz->_hijoDerecho->_hijoIzquierdo=auxiliar;
	return pRaiz;
}

NodoArbol* ArbolAA::reparto(NodoArbol* pRaiz)
{
	auto auxiliar=pRaiz->_hijoDerecho->_hijoIzquierdo;
	pRaiz->_hijoDerecho->_hijoIzquierdo=pRaiz;
	pRaiz=pRaiz->_hijoDerecho;
	pRaiz->_hijoIzquierdo->_hijoDerecho=auxiliar;
	auto raiz =  (NodoAA*)pRaiz;
	raiz->_nivel++;
	return pRaiz; 
}

bool ArbolAA::hayTresEnMismoNivel(NodoArbol* pRaiz)
{
	bool resultado = false;
	auto raiz = (NodoAA*) pRaiz;
	auto hijoDerecho = (NodoAA*) raiz->_hijoDerecho; 
	if(hijoDerecho && raiz->_nivel==hijoDerecho->_nivel)
	{
		auto siguienteHijoDerecho = (NodoAA*)hijoDerecho->_hijoDerecho;
		if(siguienteHijoDerecho && raiz->_nivel==siguienteHijoDerecho->_nivel)
			resultado = true;
	}
	return resultado;
}
//Metodos Protegidos
void ArbolAA::preOrden(NodoAA* pRaiz)
{
	if (pRaiz != nullptr)
	{
		string valor = conversor.intToString(pRaiz->_valor);

		recorrido += "Codigo= " + valor;
		recorrido += " Nivel= " + conversor.intToString(pRaiz->_nivel);
		recorrido += " Dato= " + pRaiz->_dato + "\n";

		preOrden((NodoAA*)pRaiz->_hijoIzquierdo);
		preOrden((NodoAA*)pRaiz->_hijoDerecho);
	}

}

void ArbolAA::inOrden(NodoAA* pRaiz)
{
	if (pRaiz != nullptr)
	{
		inOrden((NodoAA*)pRaiz->_hijoIzquierdo);
		string valor = conversor.intToString(pRaiz->_valor);
		recorrido += "Codigo= " + valor;
		recorrido += " Nivel= " + conversor.intToString(pRaiz->_nivel);
		recorrido += " Dato= " + pRaiz->_dato + "\n";

		inOrden((NodoAA*)pRaiz->_hijoDerecho);
	}
}

void ArbolAA::postOrden(NodoAA* pRaiz)
{
	if (pRaiz != nullptr)
	{
		postOrden((NodoAA*)pRaiz->_hijoIzquierdo);
		postOrden((NodoAA*)pRaiz->_hijoDerecho);
		string valor = conversor.intToString(pRaiz->_valor);
		recorrido += "Codigo= " + valor;
		recorrido += " Nivel= " + conversor.intToString(pRaiz->_nivel);
		recorrido += " Dato= " + pRaiz->_dato + "\n";



	}

}
void ArbolAA::Recorridos()
{
	DatoTexto* dato = new DatoTexto();
	EscritorArchivo _escritor;

	_escritor.abrir(RUTARECORRIDOSINONIMOS, true);
	recorrido += "preOrden\n";
	preOrden((NodoAA*)_raiz);


	recorrido += "inOrden\n";
	inOrden((NodoAA*)_raiz);


	recorrido += "postOrden\n";
	postOrden((NodoAA*)_raiz);
	dato->palabra = recorrido;
	_escritor.escribir(dato);
	_escritor.cerrar();
}

