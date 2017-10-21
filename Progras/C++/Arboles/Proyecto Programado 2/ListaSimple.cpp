#include "ListaSimple.h"

void ListaSimple::insertarInicio(string pDato)
{
	if (listaVacia())
		_primero = new NodoSimple(pDato);
	else
		_primero = new NodoSimple(pDato, _primero);
}

void ListaSimple::insertarFinal(string pDato)
{
	if (listaVacia())
		_primero = new NodoSimple(pDato);
	else
	{
		NodoSimple* nodoAuxiliar = _primero;

		while (nodoAuxiliar->_siguiente != nullptr)
			nodoAuxiliar = nodoAuxiliar->_siguiente;

		nodoAuxiliar->_siguiente = new NodoSimple(pDato);
	}
}

void ListaSimple::insertaPosicion(string pDato, int pPosicion)

{
	if (listaVacia())
		_primero = new NodoSimple(pDato);
	else
	{
		if (pPosicion <= 1)
		{
			NodoSimple* nuevo = new NodoSimple (pDato);
			nuevo->_siguiente = _primero;
			_primero = nuevo;
		}
		else
		{
			NodoSimple* nodoAuxiliar = _primero;
			int i = 2;

			while ((i != pPosicion) && (nodoAuxiliar->_siguiente != nullptr))
			{
				i++;
				nodoAuxiliar = nodoAuxiliar->_siguiente;
			}

			NodoSimple* nuevo = new NodoSimple(pDato);
			nuevo->_siguiente = nodoAuxiliar->_siguiente;
			nodoAuxiliar->_siguiente = nuevo;

		}
	}
}

string ListaSimple::getValorActual()
{
	if (_actual != nullptr)
		return _actual->_dato;
	else
		return "";
}

void ListaSimple::setPrimero(NodoSimple* pNodo)
{
	_primero = pNodo;
}

string ListaSimple::getValorPosicion(int pPosicion)
{
	if (pPosicion <= largo())
	{
		int contador = 1;
		while (contador != pPosicion)
		{
			siguiente();
		}
		return _actual->_dato;
	}
	else
	{
		cout << "La posicion indicada no existe en la lista" << endl;
		return nullptr;
	}
}

void ListaSimple::primero()
{
	_actual = _primero;
}

void ListaSimple::mostrar()
{
	NodoSimple* nodoAuxiliar = _primero;

	while (nodoAuxiliar)
	{
		cout << nodoAuxiliar->_dato << ",";
		nodoAuxiliar = nodoAuxiliar->_siguiente;
	}
	cout << endl;
}

int ListaSimple::largo()
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

void ListaSimple::borrarPosicion(int pPosicion)

{
	if (listaVacia())
	{
		cout << "Lista vacia" << endl;
	}
	else
	{
		if ((pPosicion>largo()) || (pPosicion<0))
		{
			cout << "Error en posicion" << endl;
		}
		else
		{
			NodoSimple* nodoAuxiliar = _primero;

			if (pPosicion == 1)
			{
				_primero = _primero->_siguiente;
				delete nodoAuxiliar;
			}
			else
			{
				int contador = 2;

				while (contador<pPosicion)
				{
					nodoAuxiliar = nodoAuxiliar->_siguiente;
					contador++;
				}
				NodoSimple* nodoBorrar = nodoAuxiliar->_siguiente;
				nodoAuxiliar->_siguiente = nodoAuxiliar->_siguiente->_siguiente;
				delete nodoBorrar;
			}
		}
	}
}

void ListaSimple::borrarInicio()

{
	if (listaVacia())
	{
		cout << "No hay elementos en la Lista:" << endl;
	}
	else
	{
		if (_primero->_siguiente == nullptr)
		{
			 NodoSimple* nodoAuxiliar = _primero;
			_primero = nullptr;
			delete nodoAuxiliar;
		}
		else
		{
			NodoSimple* nodoAuxiliar = _primero;
			_primero = _primero->_siguiente;
			delete nodoAuxiliar;
		}
	}
}

void ListaSimple::borrarFinal()

{
	if (listaVacia())
	{
		cout << "No hay elementos en la Lista:" << endl;
	}
	else
	{
		if (_primero->_siguiente == nullptr)
		{
			_primero = nullptr;
		}
		else
		{
			NodoSimple* nodoAuxiliar = _primero;

			while (nodoAuxiliar->_siguiente->_siguiente != nullptr)
			{
				nodoAuxiliar = nodoAuxiliar->_siguiente;
			}

			NodoSimple* temp = nodoAuxiliar->_siguiente;
			nodoAuxiliar->_siguiente = nullptr;
			delete temp;
		}
	}
}

void ListaSimple::siguiente()
{
	if (_actual) _actual = _actual->_siguiente;
}

bool ListaSimple::listaVacia()
{
	return _primero == nullptr;
}

NodoSimple* ListaSimple::getPrimero()
{
	return _primero ;
}