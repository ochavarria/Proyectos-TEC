#include "ArbolB.h"
#include <iostream>
#include "EscritorArchivo.h"
#include "Constantes.h"

//Constructor
ArbolB::ArbolB(void)
{
	_raiz = nullptr;
	_hijoDer = nullptr;
	_raizAux = nullptr;
	_esta=false;
	k=0;
}

string ArbolB::buscar(int pValor)
{
	return buscar(pValor,_raiz);
}

void ArbolB::mostrarPreOrden()
{
	PreOrden(_raiz);
	std::cout<< std::endl;

}

//Metodos
void ArbolB::insertar(int pValor, std::string pDato)
{
	_esta=false;
	empujar(pValor,_raiz,pDato);
	if (_empujaArriba)
	{
		NodoB* nodoNuevo = new NodoB();
		nodoNuevo->_cuenta = 1;
		nodoNuevo->_claves[1] = _mediana;
		nodoNuevo->datos[1]= _dato;
		nodoNuevo->_ramas[0] = _raiz;
		nodoNuevo->_ramas[1]= _hijoDer;
		_raiz=nodoNuevo;
	}
}

void ArbolB::empujar(int pValor, NodoB* pRaiz, string pDato)
{
	if (pRaiz==nullptr)
	{
		_empujaArriba = true;
		_mediana = pValor;
		_dato = pDato;
		_hijoDer = nullptr;
	}
	else
	{
		BuscarNodo(pValor,pRaiz);
		if(!_esta)
		{
			empujar(pValor, pRaiz->_ramas[k],pDato);
			if (_empujaArriba)
			{
				if (pRaiz->_cuenta < TAMANOCLAVES)
				{
					BuscarNodo(pValor,pRaiz);
					_empujaArriba = false;
					MeterHoja(_mediana, _hijoDer,pRaiz,pDato);
				}
				else
				{
					BuscarNodo(pValor,pRaiz);
					_empujaArriba = true;
					DividirNodo(_mediana, _hijoDer,pRaiz,k,pDato);
				}

			}
		}

	}
}

string ArbolB::buscar(int pValor, NodoB* pRaiz)
{
	if(pRaiz!=nullptr)
	{
		BuscarNodo(pValor,pRaiz);
		if(_esta)
			return pRaiz->datos[k];
		else
			return buscar(pValor,pRaiz->_ramas[k]);
	}
	else
	{
		return "";
	}
}

void ArbolB::limpiarNodo(NodoB* pRaiz)
{
	for(int i = pRaiz->_cuenta;i<TAMANOCLAVES+1;i++)
	{
		pRaiz->_claves[i]=-1;
		pRaiz->datos[i]="";
		pRaiz->_ramas[i]= nullptr;
	}
}



void ArbolB::BuscarNodo(int pValor, NodoB* pRaiz)
{
	if (pValor <pRaiz->_claves[1])
	{
		_esta = false;
		k = 0;
	}
	else
	{
		k = pRaiz->_cuenta;
		while (pValor<pRaiz->_claves[k] && k>1)
			k--;
		if (pValor == pRaiz->_claves[k])
			_esta=true;
	}
}

void ArbolB::MeterHoja(int pValor, NodoB* pHijoDer, NodoB* pRaiz, string pDato)
{
	int i; //sobra
	for (i = pRaiz->_cuenta; i > k; i--)
	{
		pRaiz->_claves[i+1] = pRaiz->_claves[i];
		pRaiz->datos[i+1] = pRaiz->datos[i];
		pRaiz->_ramas[i+1] = pRaiz->_ramas[i];
	}
	pRaiz->_claves[k + 1] = pValor;
	pRaiz->datos[k+1] = pDato;
	pRaiz->_ramas[k + 1] = pHijoDer;
	pRaiz->_cuenta ++;
}

void ArbolB::DividirNodo(int pValor, NodoB* pHijoDer, NodoB* pRaiz, int pPosicion, string pDato)
{
	int l;
	int Posmda = TAMANOCLAVES/2;
	if (pPosicion > Posmda)
		Posmda++;

	_hijoDer = new NodoB();
	for (l=Posmda+1; l <= TAMANOCLAVES; l++)
	{
		_hijoDer->_claves[l - Posmda] = pRaiz->_claves[l];
		_hijoDer->datos[l - Posmda] = pRaiz->datos[l];
		_hijoDer->_ramas[l - Posmda] = pRaiz->_ramas[l];
	}
	_hijoDer->_cuenta = TAMANOCLAVES - Posmda;
	pRaiz->_cuenta = Posmda;
	
	if (pPosicion <= TAMANOCLAVES/2)
	{
		MeterHoja(pValor, pHijoDer, pRaiz,pDato);
	}

	else
	{
		k=pPosicion - Posmda;
		MeterHoja(pValor, pHijoDer, _hijoDer,pDato);
	}

	_mediana = pRaiz->_claves[pRaiz->_cuenta];
	_dato =  pRaiz->datos[pRaiz->_cuenta];
	_hijoDer->_ramas[0] = pRaiz->_ramas[pRaiz->_cuenta];
	limpiarNodo(pRaiz);
	pRaiz->_cuenta--;

}

void ArbolB::PreOrden(NodoB* pRaiz)
{
	Conversor conversor;
	if (pRaiz)
	{
		_recorrido += "Clave\n";
		for (int posicion = 1; posicion < pRaiz->_cuenta + 1; posicion++)
		{
			_recorrido += "Estudiante= "+pRaiz->datos[posicion] +" Carnet= "+ conversor.intToString(pRaiz->_claves[posicion]);
			_recorrido += " - ";
			std::cout << pRaiz->_claves[posicion] << " - ";
		}
		_recorrido += "\n";
		for (int posicion = 0; posicion<5; posicion++)
			PreOrden(pRaiz->_ramas[posicion]);
	}
}
void ArbolB::Recorridos()
{
	DatoTexto* dato = new DatoTexto();
	EscritorArchivo _escritor;
	_escritor.abrir(RUTARECORRIDOESTUDIANTES, true);
	_recorrido = "PreOrden\n";
	PreOrden(_raiz);
	dato->palabra = _recorrido;
	_escritor.escribir(dato);
	_escritor.cerrar();
}

