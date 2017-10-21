#include "ArbolNario.h"
#include <iostream>

ArbolNario::ArbolNario()
{
	_raiz=new NodoNario();
}
//Metodos Publicos
void ArbolNario::insertar(int pCodigo, string pPalabra)
{
	insertar(pCodigo,_raiz,0,pPalabra);
}

int ArbolNario::buscar(string pPalabra)
{
	return buscar(_raiz,0,pPalabra);
}

void ArbolNario::mostrarPreOrden()
{
	PreOrden(_raiz);
	std::cout<< std::endl;
}

//Metodos Privados
void ArbolNario::insertar(int pValor, NodoNario* pRaiz, int posicion, string pPalabra)
{
	int largoString = pPalabra.length();
	if(posicion==largoString)
	{
		pRaiz->_valor=pValor;
	}
	else
	{
		int codigoascii = pPalabra[posicion];
		int posicionenarreglo = codigoascii-97;

		if(pRaiz->_hijos[posicionenarreglo]==nullptr)
			pRaiz->_hijos[posicionenarreglo]= new NodoNario();
		insertar(pValor,pRaiz->_hijos[posicionenarreglo],posicion+1,pPalabra);
	}
}

int ArbolNario::buscar(NodoNario* pRaiz, int posicion, string pPalabra)
{
	int largoString = pPalabra.length();
	if(pRaiz)
	{
		if(posicion==largoString)
			return pRaiz->_valor;
		else
		{
			int codigoascii = pPalabra[posicion];
			if(codigoascii>=97 && codigoascii <= 122)
			{
				int posicionenarreglo = codigoascii-97;
				return buscar(pRaiz->_hijos[posicionenarreglo],posicion+1,pPalabra);
			}
			else
			{
				if(codigoascii>=65 && codigoascii <= 90)
				{

					int posicionenarreglo = codigoascii-65;
					return buscar(pRaiz->_hijos[posicionenarreglo],posicion+1,pPalabra);
				}	
				else
					return -1;
			}
				
		}
	}
	else
	 return -1;
}

void ArbolNario::PreOrden(NodoNario* pRaiz)
{
	if(pRaiz)
	{
		std::cout << pRaiz->_valor<<" - ";
		for (int posicion = 0;posicion<TAMANOABECEDARIO;posicion++)
		{
			PreOrden(pRaiz->_hijos[posicion]);
		}
	}
}

