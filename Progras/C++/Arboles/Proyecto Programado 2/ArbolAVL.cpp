#include "ArbolAVL.h"
#include <iostream>
#include "Constantes.h"
#include "EscritorArchivo.h"

//Constructor
ArbolAVL::ArbolAVL(void):ArbolBB()
{
	_cambioAltura=false;
}

//Metodos Publicos
void ArbolAVL::insertar(int pValor,string pDato)
{
	NodoAVL* nuevo =  new NodoAVL(pValor,pDato);
	_raiz=insertarBalanceado((NodoAVL*)_raiz,nuevo);
}

void ArbolAVL::insertar(NodoAVL* pNodo)
{
	_raiz=insertarBalanceado((NodoAVL*)_raiz,pNodo);
}

//Metodos Privados
NodoAVL* ArbolAVL::insertarBalanceado(NodoAVL* pRaiz, NodoAVL* pNodo)
{  
    if(pRaiz==nullptr)
	{
        _cambioAltura = true;
		return pNodo;
    }
	else
	{
        if(pNodo->_valor<=pRaiz->_valor)
		{
			pRaiz->_hijoIzquierdo = insertarBalanceado((NodoAVL*)pRaiz->_hijoIzquierdo,pNodo);
			if(_cambioAltura)
			{
				switch(pRaiz->_factorBalance)
				{
				case 1: 
					pRaiz->_factorBalance=0;
					_cambioAltura = false;
					break;
				case 0: 
					pRaiz->_factorBalance = -1;
					break;
				case -1: 
					NodoAVL* hijoIzquierdo=(NodoAVL*)pRaiz->_hijoIzquierdo;
					if(hijoIzquierdo->_factorBalance ==-1)
						pRaiz=rotacionSimpleIzquierda(pRaiz, hijoIzquierdo);
					else
						pRaiz=rotacionDobleIzquierda(pRaiz,hijoIzquierdo);
					_cambioAltura = false;
					break;
				}
			}
        }
		else
		{
            if(pNodo->_valor>pRaiz->_valor)
			{
                pRaiz->_hijoDerecho=insertarBalanceado((NodoAVL*)pRaiz->_hijoDerecho,pNodo);

                if(_cambioAltura)
				{
					switch(pRaiz->_factorBalance)
					{
					case -1: 
						pRaiz->_factorBalance=0;
                        _cambioAltura = false;
                        break;
					case 0: 
						pRaiz->_factorBalance=1;
                        break;
					case 1:
						NodoAVL* hijoDerecho=(NodoAVL*)pRaiz->_hijoDerecho;
                        if(hijoDerecho->_factorBalance==1)
                            pRaiz=rotacionSimpleDerecha(pRaiz, hijoDerecho);
                        else
                            pRaiz=rotacionDobleDerecha(pRaiz, hijoDerecho);
						_cambioAltura=false;
                        break;
                    }
                }
            }
        }
		return pRaiz;
    }
}

NodoAVL * ArbolAVL::rotacionSimpleIzquierda(NodoAVL* pRaiz, NodoAVL* pHijoIzquierdo)
{
	pRaiz->_hijoIzquierdo=pHijoIzquierdo->_hijoDerecho;
    pHijoIzquierdo->_hijoDerecho=pRaiz;

    if(pHijoIzquierdo->_factorBalance==-1)
	{
        pRaiz->_factorBalance=0;
        pHijoIzquierdo->_factorBalance=0;
    }
	else
	{
        pRaiz->_factorBalance=-1;
        pHijoIzquierdo->_factorBalance=-1;
    }
	return pHijoIzquierdo;
}

NodoAVL * ArbolAVL::rotacionSimpleDerecha(NodoAVL* pRaiz, NodoAVL* pHijoDerecho)
{
	pRaiz->_hijoDerecho=pHijoDerecho->_hijoIzquierdo;
    pHijoDerecho->_hijoIzquierdo=pRaiz;

    if(pHijoDerecho->_factorBalance==1)
	{
        pRaiz->_factorBalance=0;
        pHijoDerecho->_factorBalance=0;
    }
	else
	{
        pRaiz->_factorBalance=1;
        pHijoDerecho->_factorBalance=-1;
    }
    return pHijoDerecho;
}

NodoAVL * ArbolAVL::rotacionDobleIzquierda(NodoAVL* pRaiz, NodoAVL* pHijoIzquierdo)
{
	NodoAVL *auxiliar;
    auxiliar=(NodoAVL*)pHijoIzquierdo->_hijoDerecho;
    pRaiz->_hijoIzquierdo = auxiliar->_hijoDerecho;
    auxiliar->_hijoDerecho=pRaiz;
    pHijoIzquierdo->_hijoDerecho=auxiliar->_hijoIzquierdo;
    auxiliar->_hijoIzquierdo=pHijoIzquierdo;

    if(auxiliar->_factorBalance==1)
        pHijoIzquierdo->_factorBalance=-1;
	else
        pHijoIzquierdo->_factorBalance=0;
    if(auxiliar->_factorBalance==-1)
        pRaiz->_factorBalance=1;
    else
        pRaiz->_factorBalance=0;

    auxiliar->_factorBalance=0;
    return auxiliar;
}

NodoAVL * ArbolAVL::rotacionDobleDerecha(NodoAVL* pRaiz, NodoAVL* pHijoDerecho)
{
	NodoAVL *auxiliar;
    auxiliar=(NodoAVL*)pHijoDerecho->_hijoIzquierdo;
    pRaiz->_hijoDerecho = auxiliar->_hijoIzquierdo;
    auxiliar->_hijoIzquierdo=pRaiz;
    pHijoDerecho->_hijoIzquierdo=auxiliar->_hijoDerecho;
    auxiliar->_hijoDerecho=pHijoDerecho;

    if(auxiliar->_factorBalance==1)
        pRaiz->_factorBalance=-1;
    else
        pRaiz->_factorBalance=0;
    if(auxiliar->_factorBalance==-1)
        pHijoDerecho->_factorBalance=1;
    else
        pHijoDerecho->_factorBalance=0;

    auxiliar->_factorBalance=0;
    return auxiliar;
}

//Metodos Protegidos
void ArbolAVL::preOrden(NodoAVL* pRaiz)
{
	if (pRaiz != nullptr)
	{
		string valor = conversor.intToString(pRaiz->_valor);
		recorrido += "Codigo= " + valor;
		recorrido += "Factor Balance= " + conversor.intToString(pRaiz->_factorBalance);
		recorrido += " Dato= " + pRaiz->_dato + "\n";
		preOrden((NodoAVL*)pRaiz->_hijoIzquierdo);
		preOrden((NodoAVL*)pRaiz->_hijoDerecho);
	}

}

void ArbolAVL::inOrden(NodoAVL* pRaiz)
{
	if (pRaiz != nullptr)
	{
		inOrden((NodoAVL*)pRaiz->_hijoIzquierdo);
		string valor = conversor.intToString(pRaiz->_valor);
		recorrido += "Codigo= " + valor;
		recorrido += "Factor Balance= " + conversor.intToString(pRaiz->_factorBalance);
		recorrido += " Dato= " + pRaiz->_dato + "\n";
		inOrden((NodoAVL*)pRaiz->_hijoDerecho);
	}
}

void ArbolAVL::postOrden(NodoAVL* pRaiz)
{
	if (pRaiz != nullptr)
	{
		postOrden((NodoAVL*)pRaiz->_hijoIzquierdo);
		postOrden((NodoAVL*)pRaiz->_hijoDerecho);
		string valor = conversor.intToString(pRaiz->_valor);
		recorrido += "Codigo= " + valor;
		recorrido += "Factor Balance= " + conversor.intToString(pRaiz->_factorBalance);
		recorrido += " Dato= " + pRaiz->_dato + "\n";

	}

}
string ArbolAVL::Recorridos(NodoArbol*pRaiz )
{
	recorrido = "";
	recorrido += "\n-----------Preorden-------------\n";
	preOrden((NodoAVL*)pRaiz);
	
	recorrido += "\n-----------inOrden------------- \n";
	inOrden((NodoAVL*)pRaiz);
	
	recorrido += "\n-----------postOrden------------- \n";
	postOrden((NodoAVL*)pRaiz);

	return recorrido;
}

