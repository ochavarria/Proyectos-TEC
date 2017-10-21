#include "ListaDoble.h"
#include <iostream>

using std::cout;
using std::endl;

//inserta utilizando primero
void ListaDoble::insertar(NodoDoble*pNodo)
{
	pNodo->_siguiente = _primero;
	pNodo->_anterior = pNodo->_siguiente->_anterior;
	pNodo->_anterior->_siguiente = pNodo;
	pNodo->_siguiente->_anterior = pNodo;
		
}
//inserta en la posicion indicada
void ListaDoble::insertaPosicion(NodoDoble* pNodo, int pPosicion)
{
	if (listaVacia())
		_primero = pNodo;
	else
	{
		if (pPosicion <= 1)
			insertaInicio(pNodo);
		else
		{
			if (pPosicion <= largo())
			{
				NodoDoble* aux = _primero;
				int contador = 2;
				while (contador != pPosicion)
				{
					contador++;
					aux = aux->_siguiente;
				}
				pNodo->_siguiente = aux->_siguiente;
				aux->_siguiente = pNodo;
				aux->_siguiente->_anterior = aux;
				pNodo->_siguiente->_anterior = pNodo;
			}
			else
				cout << "La posicion indicada no existe en la lista" << endl;
		}
	}
}
//inserta al inicio de la lista 
void ListaDoble::insertaInicio(NodoDoble* pNodo)
{
	if (listaVacia())
		_primero = pNodo;
	else
	{
		insertar(pNodo);
		_primero = pNodo;
	}
}
//inseta al final de la lista
void ListaDoble::insertaFinal(NodoDoble* pNodo)
{
	if (listaVacia())
		_primero = pNodo;
	else
		insertar(pNodo);
}
//devuelve Actual
NodoDoble* ListaDoble::getActual()
{
	return _actual;
}
// Cambia el actual
void ListaDoble::setActual(NodoDoble* pNodo)
{
	_actual = pNodo;
}
//Cambia primero al nodo recibido por parametro
void ListaDoble::setPrimero(NodoDoble* pNodo)
{
	_primero = pNodo;
}
//cambia actual al anterio nodo
void ListaDoble::anterior()
{
	if (_actual) _actual = _actual->_anterior;
}
//cambia actual al nodo siguiente
void  ListaDoble::siguiente()
{
	if (_actual)
	{
		_actual = _actual->_siguiente;
		if (_actual == _primero)
			fin = true;
	}
}
//cambia actual al nodo primero
void ListaDoble::primero()
{
	fin = false;
	_actual = _primero;
}
//busca en nodo en la posicion indicada y lo devuelve ademas de dejarlo como actual
NodoDoble* ListaDoble::getActualPosicion(int pPosicion)
{
	if (pPosicion <= largo())
	{
		int contador = 1;
		while (contador != pPosicion)
		{
			siguiente();
		}
		return _actual;
	}
	else
	{
		cout << "La posicion indicada no existe en la lista" << endl;
		return nullptr;
	}
}
//buscar el primer nodo que contenga el dato indicado
NodoDoble* ListaDoble::buscar(string pDato,bool pPrincipio)
{
	bool encontrado = false;
	if (!listaVacia())
	{
		if (pPrincipio && compararenminuscula(_primero->_dato, pDato))
		{
			return _primero;
		}
		else
		{
			if (pPrincipio)
				primero();
			siguiente();
			while (_actual != _primero)
			{
				if (compararenminuscula(_actual->_dato,pDato))
				{
					encontrado = true;
					break;
				}
				else
				{
					siguiente();
				}
			}
		}
	}
	if (encontrado)
		return _actual;
	else
		return nullptr;
}
//elimina el primer nodo que contenga el dato indicado
void ListaDoble::eliminar(string pDato)
{
	if (_primero->_dato == pDato)
	{
		borrarInicio();
	}
	else
	{
		primero();
		siguiente();
		while (_actual != _primero)
		{
			if (_actual->_dato == pDato)
			{
				borrar(_actual);
				break;
			}
			else
				siguiente();			
		}
	}
}
//Muestra la lista en la consola de comando
void ListaDoble::mostrar()
{
	if (!listaVacia())
	{
		primero();
		cout << _actual->_dato << "-> ";
		_actual = _actual->_siguiente;

		while (_actual != _primero)
		{
			cout << _actual->_dato << "-> ";
			siguiente();
		}
		cout << endl;
	}
}
//saca el largo de la lista
int ListaDoble::largo()
{
	int largo = 0;

	if (listaVacia())
		return largo;
	else
	{
		primero();
		siguiente();
		largo++;
		while (_actual != _primero)
		{
			siguiente();
			largo++;
		}
		return largo;
	}
}
//Borra el nodo en la posicion indicada
void ListaDoble::borrarPosicion(int pPosicion)
{
	if (listaVacia())
		cout << "Lista vacia" << endl;
	else
	{
		if ((pPosicion>largo()) || (pPosicion<0))
			cout << "Error en posicion" << endl;
		else
		{
			if (pPosicion == 1)
				borrarInicio();
			else
			{
				int contador = 1;
				primero();
				while (contador<pPosicion)
				{
					siguiente();
					contador++;
				}
				borrar(_actual);
			}
		}
	}

}
//Borra el nodo inicial
void ListaDoble::borrarInicio()
{
	if (listaVacia())
	{
		cout << "No hay elementos en la lista:" << endl;
	}
	else
	{
		if (_primero->_siguiente == _primero) 
		{
			_primero = nullptr;
		}
		else
		{
			NodoDoble* auxiliar = _primero;
			_primero = _primero->_siguiente;
			auxiliar->_anterior->_siguiente = _primero;
			_primero->_anterior = auxiliar->_anterior;
		}
	}
}
//Borra el nodo final
void ListaDoble::borrarFinal()
{
	if (listaVacia())
	{
		cout << "No hay elementos en la lista:" << endl;
	}

	else
	{
		if (_primero->_siguiente == _primero)
		{
			_primero = nullptr;
		}
		else
		{
			NodoDoble* auxiliar = _primero->_anterior;
			auxiliar->_anterior->_siguiente = _primero; 
			_primero->_anterior = auxiliar->_anterior;
		}
	}
}
//borra el nodo indicado
void ListaDoble::borrar(NodoDoble* pNodoBorrar)
{
	NodoDoble* temporal = pNodoBorrar->_anterior;
	temporal->_siguiente = pNodoBorrar->_siguiente;
	temporal->_siguiente->_anterior = temporal;
	pNodoBorrar->_anterior = nullptr;
	pNodoBorrar->_siguiente = nullptr;
}
//devuelve si la lista esta vacia o no
bool ListaDoble::listaVacia()
{
	return _primero == nullptr;
}

bool ListaDoble::compararenminuscula(string pParametro1, string pParametro2)
{
	bool resultado = false;
	int largo1 = pParametro1.length() + 1;
	int largo2 = pParametro2.length() + 1;

	char *caracteres1 = new char[largo1];
	char *caracteres2 = new char[largo2];

	strcpy_s(caracteres1, largo1, pParametro1.c_str());
	strcpy_s(caracteres2, largo2, pParametro2.c_str());


	for (int indice = 0; indice < largo1; indice++)
	{
		caracteres1[indice] = hacerMinuscula(caracteres1[indice]);
	}
	for (int indice = 0; indice < largo2 + 1; indice++)
	{
		caracteres2[indice] = hacerMinuscula(caracteres2[indice]);
	}
	if (largo1 == largo2)
	{
		for (int indice = 0; indice < largo2; indice++)
		{
			if (caracteres2[indice] == caracteres1[indice])
			{
				resultado = true;
			}
			else
			{
				resultado = false;
				break;
			}
		}
	}

	return resultado;
}

int ListaDoble::hacerMinuscula(int pValor)
{
	if (pValor < 97)
		pValor = pValor + 32;
	return pValor;
}