#include "ListaSimple.h"

//Constructor
ListaSimple::ListaSimple()
{
	_primero = _actual = nullptr;
	_largoLista = 0;
}

ListaSimple::~ListaSimple()
{
	NodoLista* nodoAuxiliar;

	while (_primero)
	{
		nodoAuxiliar = _primero;
		_primero = _primero->_siguiente;
		delete nodoAuxiliar;
	}

	_actual = nullptr;
}

//Metodos Publicos
void ListaSimple::insertarInicio(int pValor)
{
	if (listaVacia())
		_primero = new NodoLista(pValor);
	else
		_primero = new NodoLista(pValor, _primero);
	_largoLista++;
}

void ListaSimple::insertarInicio(NodoLista* pValor)
{
	if (listaVacia())
		_primero = pValor;
	else
		pValor->_siguiente = _primero;
	_primero = pValor;
	_largoLista++;
}

NodoLista* ListaSimple::getActual()
{
	return _actual;
}

void ListaSimple::insertarFinal(int pValor)
{
	if (listaVacia())
		_primero = new NodoLista(pValor);
	else
	{
		NodoLista* nodoAuxiliar = _primero;

		while (nodoAuxiliar->_siguiente != nullptr)
			nodoAuxiliar = nodoAuxiliar->_siguiente;

		nodoAuxiliar->_siguiente = new NodoLista(pValor);
	}
	_largoLista++;
}

void ListaSimple::insertarFinal(NodoLista* pValor)
{
	if (listaVacia())
		_primero = pValor;
	else
	{
		NodoLista* nodoAuxiliar = _primero;

		while (nodoAuxiliar->_siguiente != nullptr)
			nodoAuxiliar = nodoAuxiliar->_siguiente;

		nodoAuxiliar->_siguiente = pValor;
	}
	_largoLista++;
}

void ListaSimple::insertarPos(int pValor, int pPosicion)
{
	if (listaVacia())
		_primero = new NodoLista(pValor);
	else
	{
		if (pPosicion <= 1)
		{
			NodoLista* nuevo = new NodoLista(pValor);
			nuevo->_siguiente = _primero;
			_primero = nuevo;
		}
		else
		{
			NodoLista* nodoAuxiliar = _primero;
			int i = 2;

			while ((i != pPosicion) && (nodoAuxiliar->_siguiente != nullptr))
			{
				i++;
				nodoAuxiliar = nodoAuxiliar->_siguiente;
			}

			NodoLista* nuevo = new NodoLista(pValor);
			nuevo->_siguiente = nodoAuxiliar->_siguiente;
			nodoAuxiliar->_siguiente = nuevo;
		}
	}
	_largoLista++;
}

NodoLista* ListaSimple::buscar(int pDato)
{
	NodoLista* aux = _primero;
	while(aux!=nullptr && aux->_valor!=pDato)
		aux=aux->_siguiente;
	if(aux!=nullptr && aux->_valor==pDato)
		return aux;
	else
		return nullptr;
}

void ListaSimple::mostrar()
{
	NodoLista* nodoAuxiliar = _primero;

	while (nodoAuxiliar)
	{
		cout << nodoAuxiliar->_valor << "";
		nodoAuxiliar = nodoAuxiliar->_siguiente;
	}
	cout << endl;
}

void ListaSimple::siguiente()
{
	if (_actual) _actual = _actual->_siguiente;
}

void ListaSimple::primero()
{
	_actual = _primero;
}

void ListaSimple::ultimo()
{
	_actual = _primero;
	if (!listaVacia())
		while (_actual->_siguiente) siguiente();
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
			NodoLista* nodoAuxiliar = _primero;

			while (nodoAuxiliar->_siguiente->_siguiente != nullptr)
			{
				nodoAuxiliar = nodoAuxiliar->_siguiente;
			}

			NodoLista* temp = nodoAuxiliar->_siguiente;
			nodoAuxiliar->_siguiente = nullptr;
			delete temp;
		}
		_largoLista--;
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
		NodoLista * auxiliar = _primero->_siguiente;
		_primero->_siguiente = nullptr;
		_primero=auxiliar;
		_largoLista--;
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
		if ((pPosicion > largoLista()) || (pPosicion < 0))
		{
			cout << "Error en posicion" << endl;
		}
		else
		{
			NodoLista* nodoAuxiliar = _primero;

			if (pPosicion == 1)
			{
				_primero = _primero->_siguiente;
				delete nodoAuxiliar;
			}
			else
			{
				int contador = 2;

				while (contador < pPosicion)
				{
					nodoAuxiliar = nodoAuxiliar->_siguiente;
					contador++;
				}
				NodoLista* nodoBorrar = nodoAuxiliar->_siguiente;
				nodoAuxiliar->_siguiente = nodoAuxiliar->_siguiente->_siguiente;
				delete nodoBorrar;
			}
			_largoLista--;
		}
	}
}

int ListaSimple::largoLista()
{
	NodoLista* nodoAuxiliar = _primero;
	_largoLista = 0;
	while (nodoAuxiliar)
	{
		_largoLista++;
		nodoAuxiliar = nodoAuxiliar->_siguiente;
	}
	return _largoLista;
}

bool ListaSimple::listaVacia()
{
	return _primero == nullptr;
}

int ListaSimple::getValorActual()
{
	if (_actual != nullptr)
		return _actual->_valor;
	else
		return -1;
}

void ListaSimple::setPrimero(NodoLista* parNodo)
{
	_primero = parNodo;
	primero();
}


Arco* ListaSimple::buscarConexion(int pPeso, Vertice* inicio, Vertice* fin)
{
	Arco* aux = (Arco*)_primero;
	int cont = 0;

	while (aux != nullptr)
	{
		if (aux->_peso == pPeso && aux->_incio->_valor == inicio->_valor && aux->_fin->_valor == fin->_valor)
		{
			return aux;
		}
		else{
			aux = (Arco*)aux->_siguiente;
		}
	}
	return NULL;

}

NodoLista* ListaSimple::buscarVertice(Vertice* pDato)
{
	NodoLista* aux = _primero;
	while (aux != nullptr && aux != pDato)
		aux = aux->_siguiente;
	if (aux != nullptr && aux == pDato)
		return aux;
	else
		return nullptr;
}



void ListaSimple::borrarConexion(Arco* Conexion)
{
	if (Conexion == _primero)
	{
		if (_primero->_siguiente != NULL)
		{
			Arco* NodoCambio = (Arco*)_primero;
			Arco* NodoBorrar = ((Arco*)_primero->_siguiente);

			NodoCambio->_incio = NodoBorrar->_incio;
			NodoCambio->_fin = NodoBorrar->_fin;
			NodoCambio->_peso = NodoBorrar->_peso;
			NodoCambio->_siguiente = NodoBorrar->_siguiente;

			delete NodoBorrar;
		}
		else
		{
			((Arco*)_primero)->_incio = NULL;
			((Arco*)_primero)->_fin = NULL;
			((Arco*)_primero)->_peso = NULL;

		}
	}
	else
	{
		NodoLista*  nodoAuxiliar = _primero;
		while (nodoAuxiliar != NULL)
		{
			if (Conexion == (Arco*)nodoAuxiliar->_siguiente)
			{

				NodoLista* nodoBorrar = nodoAuxiliar->_siguiente;
				nodoAuxiliar->_siguiente = nodoAuxiliar->_siguiente->_siguiente;
				delete nodoBorrar;
				break;
			}
			else
			{
				nodoAuxiliar = (Arco*)nodoAuxiliar->_siguiente;
			}
		}
	}
}
void ListaSimple::InsertarEnlistaVertices(NodoLista* pValor)
{
	((Arco*)pValor)->_siguiente = NULL;

	if (listaVacia())
	{
		_primero = pValor;
	}

	else
	{
		_actual->_siguiente = pValor;
	}
	_largoLista++;
}

void ListaSimple::NEXT()
{
	if (_actual == NULL)
	{
		_actual = _primero;
	}
	_actual = _actual->_siguiente;

}

NodoLista* ListaSimple::getPrimero()
{

	return _primero;
}