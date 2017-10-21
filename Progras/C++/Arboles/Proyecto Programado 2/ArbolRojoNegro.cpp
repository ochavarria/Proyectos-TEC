#include "ArbolRojoNegro.h"
#include "EscritorArchivo.h"
#include "Constantes.h"
#include <iostream>
#include "Conversor.h"

//Constructor
ArbolRojoNegro::ArbolRojoNegro(void)
{
	_dosRojos=false;
	_derecha=false;
}
//Metodos Publicos
void ArbolRojoNegro::insertar(int pValor,string pDato)
{
	NodoRojoNegro* nuevo = new NodoRojoNegro(pValor,pDato);
	auto raiz = (NodoRojoNegro*)_raiz;
	raiz=insertarRojoNegro(raiz,nuevo);
	_raiz=raiz;
	if(raiz->_rojo)
		raiz->_rojo=false;
}

void ArbolRojoNegro::insertar(NodoRojoNegro* pNodo)
{
	auto raiz = (NodoRojoNegro*)_raiz;
	raiz=insertarRojoNegro(raiz,pNodo);
	_raiz=raiz;
	if(raiz->_rojo)
		raiz->_rojo=false;
}

//Metodos Privados
NodoRojoNegro* ArbolRojoNegro::insertarRojoNegro(NodoRojoNegro* pRaiz, NodoRojoNegro* pNodo)
{
	if(pRaiz==nullptr)
	{
		return pNodo;
	}
	else
	{
		if(pNodo->_valor>pRaiz->_valor)
		{
			pRaiz->_hijoDerecho=insertarRojoNegro((NodoRojoNegro*)pRaiz->_hijoDerecho,pNodo);
			if(_dosRojos)
			{
				auto hijoIzquierdo =(NodoRojoNegro*) pRaiz->_hijoIzquierdo;
				if(pRaiz->_hijoIzquierdo && hijoIzquierdo->_rojo)
				{
					reglaTio(pRaiz);
				}
				else
				{
					if(_derecha)
						pRaiz=rotacionSimpleDerecha(pRaiz,(NodoRojoNegro*)pRaiz->_hijoDerecho);
					else
						pRaiz=rotacionDobleDerecha(pRaiz,(NodoRojoNegro*)pRaiz->_hijoDerecho);
				}
				_dosRojos=false;
			}
			auto hijoDerecho =(NodoRojoNegro*) pRaiz->_hijoDerecho;
			if(pRaiz->_rojo && hijoDerecho->_rojo)
				_dosRojos=true;
			
			_derecha=true;
		}
		else
		{
			if(pNodo->_valor<=pRaiz->_valor)
			{
				pRaiz->_hijoIzquierdo=insertarRojoNegro((NodoRojoNegro*)pRaiz->_hijoIzquierdo,pNodo);
				if(_dosRojos)
				{
					auto hijoDerecho =(NodoRojoNegro*) pRaiz->_hijoDerecho;
					if(pRaiz->_hijoDerecho && hijoDerecho->_rojo)
					{
						reglaTio(pRaiz);
					}
					else
					{
						if(!_derecha)
							pRaiz=rotacionSimpleIzquierda(pRaiz,(NodoRojoNegro*)pRaiz->_hijoIzquierdo);
						else
							pRaiz=rotacionDobleIzquierda(pRaiz,(NodoRojoNegro*)pRaiz->_hijoIzquierdo);
						
					}
					_dosRojos=false;

				}
				auto hijoIzquierdo =(NodoRojoNegro*) pRaiz->_hijoIzquierdo;
				if(pRaiz->_rojo && hijoIzquierdo->_rojo)
					_dosRojos=true;
				_derecha=false;
			}
		}
		return pRaiz;
	}

}

void ArbolRojoNegro::reglaTio(NodoRojoNegro* pRaiz)
{
	pRaiz->_rojo=true;
	auto hijoDerecho =(NodoRojoNegro*) pRaiz->_hijoDerecho;
	hijoDerecho->_rojo=false;
	auto hijoIzquierdo =(NodoRojoNegro*) pRaiz->_hijoIzquierdo;
	hijoIzquierdo->_rojo=false;
}

NodoRojoNegro * ArbolRojoNegro::rotacionSimpleIzquierda(NodoRojoNegro* pRaiz, NodoRojoNegro* pHijoIzquierdo)
{
	pRaiz->_hijoIzquierdo=pHijoIzquierdo->_hijoDerecho;
    pHijoIzquierdo->_hijoDerecho=pRaiz;
	pRaiz->_rojo=true;
	pHijoIzquierdo->_rojo=false;

	return pHijoIzquierdo;
}

NodoRojoNegro * ArbolRojoNegro::rotacionSimpleDerecha(NodoRojoNegro* pRaiz, NodoRojoNegro* pHijoDerecho)
{
	pRaiz->_hijoDerecho=pHijoDerecho->_hijoIzquierdo;
    pHijoDerecho->_hijoIzquierdo=pRaiz;
	pRaiz->_rojo=true;
	pHijoDerecho->_rojo=false;
    return pHijoDerecho;
}

NodoRojoNegro* ArbolRojoNegro::rotacionDobleDerecha(NodoRojoNegro* pRaiz, NodoRojoNegro* pHijoDerecho)
{
	NodoRojoNegro *auxiliar;
    auxiliar=(NodoRojoNegro*)pHijoDerecho->_hijoIzquierdo;
    pRaiz->_hijoDerecho = auxiliar->_hijoIzquierdo;
    auxiliar->_hijoIzquierdo=pRaiz;
    pHijoDerecho->_hijoIzquierdo=auxiliar->_hijoDerecho;
    auxiliar->_hijoDerecho=pHijoDerecho;

	auxiliar->_rojo=false;
	pRaiz->_rojo=true;
    
    return auxiliar;
}

NodoRojoNegro* ArbolRojoNegro::rotacionDobleIzquierda(NodoRojoNegro* pRaiz, NodoRojoNegro* pHijoIzquierdo)
{
	NodoRojoNegro *auxiliar;
    auxiliar=(NodoRojoNegro*)pHijoIzquierdo->_hijoDerecho;
    pRaiz->_hijoIzquierdo = auxiliar->_hijoDerecho;
    auxiliar->_hijoDerecho=pRaiz;
    pHijoIzquierdo->_hijoDerecho=auxiliar->_hijoIzquierdo;
    auxiliar->_hijoIzquierdo=pHijoIzquierdo;

	auxiliar->_rojo=false;
	pRaiz->_rojo=true;

	return auxiliar;
}
//Metodos Protegidos
void ArbolRojoNegro::preOrden(NodoRojoNegro* pRaiz)
{
	if (pRaiz != nullptr)
	{
		string valor = conversor.intToString(pRaiz->_valor);

		recorrido += "Codigo= "+valor;
		recorrido += " Color= " + conversor.RojoNegro(pRaiz->_rojo);
		recorrido += " Dato= "+pRaiz->_dato + "\n";

		preOrden((NodoRojoNegro*)pRaiz->_hijoIzquierdo);
		preOrden((NodoRojoNegro*)pRaiz->_hijoDerecho);
	}

}

void ArbolRojoNegro::inOrden(NodoRojoNegro* pRaiz)
{
	if (pRaiz != nullptr)
	{
		inOrden((NodoRojoNegro*)pRaiz->_hijoIzquierdo);
		string valor = conversor.intToString(pRaiz->_valor);
		recorrido += "Codigo= " + valor;
		recorrido += " Color= " + conversor.RojoNegro(pRaiz->_rojo);
		recorrido += " Dato= " + pRaiz->_dato + "\n";

		inOrden((NodoRojoNegro*)pRaiz->_hijoDerecho);
	}
}

void ArbolRojoNegro::postOrden(NodoRojoNegro* pRaiz)
{
	if (pRaiz != nullptr)
	{
		postOrden((NodoRojoNegro*)pRaiz->_hijoIzquierdo);
		postOrden((NodoRojoNegro*)pRaiz->_hijoDerecho);
		string valor = conversor.intToString(pRaiz->_valor);
		recorrido += "Codigo= " + valor;
		recorrido += " Color= " + conversor.RojoNegro(pRaiz->_rojo);
		recorrido += " Dato= " + pRaiz->_dato + "\n";



	}

}
void ArbolRojoNegro::Recorridos()
{   
	DatoTexto* dato = new DatoTexto();
	EscritorArchivo _escritor;

	_escritor.abrir(RUTARECORRIDODEFINICIONES, true);
	recorrido += "preOrden\n";
	preOrden((NodoRojoNegro*)_raiz);


	recorrido += "inOrden\n";
	inOrden((NodoRojoNegro*)_raiz);


	recorrido += "postOrden\n";
	postOrden((NodoRojoNegro*)_raiz);
	dato->palabra = recorrido;
	_escritor.escribir(dato);
	_escritor.cerrar();
}

