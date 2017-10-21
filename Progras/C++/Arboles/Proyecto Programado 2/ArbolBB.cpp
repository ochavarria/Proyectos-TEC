#include "ArbolBB.h"
#include <iostream>
#include "EscritorArchivo.h"
#include "Constantes.h"
#include "NodoRojoNegro.h"


//Constructor
ArbolBB::ArbolBB(void)
{
	_raiz=nullptr;
}




//Metodos Publicos
void ArbolBB::setRaiz(NodoArbol* pRaiz)
{
	_raiz=pRaiz;
}

NodoArbol* ArbolBB::getRaiz()
{
	return _raiz;
}

NodoArbol * ArbolBB::buscar(int pValor,bool Guardar)
{

	return buscarAuxiliar(_raiz, pValor, Guardar);
}
void ArbolBB::insertar(int pValor, string pDato)
{
	NodoArbol* nuevo = new NodoArbol(pValor,pDato);
	_raiz=insertarOrdenado(_raiz,nuevo);
}

void ArbolBB::insertar(NodoArbol* pNodo)
{
	_raiz=insertarOrdenado(_raiz,pNodo);
}

void ArbolBB::mostrarPreOrden()
{  
	preOrden(_raiz);
	std::cout << std::endl;
}

void ArbolBB::mostrarInOrden()
{
	inOrden(_raiz);
	std::cout << std::endl;
}

void ArbolBB::mostrarPostOrden()
{
	postOrden(_raiz);
	std::cout << std::endl;
}

NodoArbol* ArbolBB::buscarAuxiliar(NodoArbol* pRaiz, int pValor,bool Guardar)
{
	DatoTexto* dato = new DatoTexto();
	EscritorArchivo _escritor;
	if (pRaiz)
	{
		dato->palabra += "Pasando por " + pRaiz->_dato+"\n";

		if (pValor == pRaiz->_valor)
		{
			if (Guardar)
			{
				dato->palabra += "Dato encontrado";
				dato->separacionatras = "\n";
				_escritor.abrir(RUTAPALABRASVISITADAS, false);
				_escritor.escribir(dato);
				_escritor.cerrar();
			}
			return pRaiz;
		}
		else
		{
			if (Guardar)
			{
				dato->palabra += "Datos no coinciden ";
				dato->separacionatras = "\n";
				_escritor.abrir(RUTAPALABRASVISITADAS, false);
				_escritor.escribir(dato);
				_escritor.cerrar();
			}
			if (pValor < pRaiz->_valor)
				return buscarAuxiliar(pRaiz->_hijoIzquierdo, pValor,Guardar);
			else
				return buscarAuxiliar(pRaiz->_hijoDerecho, pValor, Guardar);
		}
	}
	else
	{
		if (Guardar)
		{
			dato->palabra = "Dato no encontrado";
			dato->separacionatras = "\n";
			_escritor.abrir(RUTAPALABRASVISITADAS, false);
			_escritor.escribir(dato);
			_escritor.cerrar();
		}
		return pRaiz;
	}
}

//Metodos Protegidos
void ArbolBB::preOrden(NodoArbol* pRaiz)
{
	if(pRaiz!=nullptr)
	{

		string valor = conversor.intToString(pRaiz->_valor);
		recorrido += "Codigo= " + valor;
		recorrido += " Dato= " + pRaiz->_dato + "\n";

		preOrden(pRaiz->_hijoIzquierdo);
		preOrden(pRaiz->_hijoDerecho);
	}
	
}

void ArbolBB::inOrden(NodoArbol* pRaiz)
{
	if(pRaiz!=nullptr)
	{

		inOrden(pRaiz->_hijoIzquierdo);
		string valor = conversor.intToString(pRaiz->_valor);
		recorrido += "Codigo= " + valor;
		recorrido += " Dato= " + pRaiz->_dato + "\n";
		inOrden(pRaiz->_hijoDerecho);
	}
}

void ArbolBB::postOrden(NodoArbol* pRaiz)
{
	if(pRaiz!=nullptr)
	{
		postOrden(pRaiz->_hijoIzquierdo);
		postOrden(pRaiz->_hijoDerecho);
		string valor = conversor.intToString(pRaiz->_valor);

		recorrido += "Codigo= " + valor;
		recorrido += " Dato= " + pRaiz->_dato + "\n";

	}
	
}
void ArbolBB::Recorridos()
{
	DatoTexto* dato = new DatoTexto();
	EscritorArchivo _escritor;
	_escritor.abrir(RUTARECORRIDOLETRAS, true);
	recorrido = "preOrden\n";
	preOrden(_raiz);
	recorrido+= "inOrden\n";
	inOrden(_raiz);
	recorrido += "postOrden\n";
	postOrden(_raiz);
	dato->palabra = recorrido;
	_escritor.escribir(dato);
	_escritor.cerrar();
}
//Metodos Privados
NodoArbol* ArbolBB::insertarOrdenado(NodoArbol* pRaiz, NodoArbol* pNodo)
{
	if(pRaiz==nullptr)
		return pNodo;
	else
	{
		if(pNodo->_valor<=pRaiz->_valor)
			pRaiz->_hijoIzquierdo=insertarOrdenado(pRaiz->_hijoIzquierdo,pNodo);
		else
			pRaiz->_hijoDerecho=insertarOrdenado(pRaiz->_hijoDerecho,pNodo);
		return pRaiz;
	}
}

