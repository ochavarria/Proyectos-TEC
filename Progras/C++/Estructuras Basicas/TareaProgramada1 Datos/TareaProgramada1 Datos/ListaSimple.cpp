//Header del archivo
#ifndef DEFLLISTASIMPLE
#define DEFLISTASIMPLE

//Librerias incluidas
#include "Nodo.cpp"
#include <iostream>

using std::cout;
using std::endl;

//Permite utilizar una etiqueta (pNodo)
typedef Nodo *pNodo;

class ListaSimple
{

public:
	//Contructor de la clase
	ListaSimple()
	{
		_primero = _actual = NULL;
		_largoLista = 0;
	}
	//destructor de la clase
	~ListaSimple()
	{
		pNodo nodoAuxiliar;

		while (_primero)
		{
			nodoAuxiliar = _primero;
			_primero = _primero->_siguiente;
			delete nodoAuxiliar;
		}

		_actual = NULL;
	}
	//Inserta un valor al principio de la lista
	void insertarInicio(string pValor)
	{
		if (listaVacia())
			_primero = new Nodo(pValor);
		else
			_primero = new Nodo(pValor, _primero);
		_largoLista++;
	}
	//Inserta un valor al final de la lista
	void insertarFinal(string pValor)
	{
		if (listaVacia())
			_primero = new Nodo(pValor);
		else
		{
			pNodo nodoAuxiliar = _primero;

			while (nodoAuxiliar->_siguiente != NULL)
				nodoAuxiliar = nodoAuxiliar->_siguiente;

			nodoAuxiliar->_siguiente = new Nodo(pValor);
		}
		_largoLista++;
	}
	//Inserta un valor en una determinada posicion de la lista
	void insertarPos(string pValor, int pPosicion)
	{
		if (listaVacia())
			_primero = new Nodo(pValor);
		else
		{
			if (pPosicion <= 1)
			{
				pNodo nuevo = new Nodo(pValor);
				nuevo->_siguiente = _primero;
				_primero = nuevo;
			}
			else
			{
				pNodo nodoAuxiliar = _primero;
				int i = 2;

				while ((i != pPosicion) && (nodoAuxiliar->_siguiente != NULL))
				{
					i++;
					nodoAuxiliar = nodoAuxiliar->_siguiente;
				}

				pNodo nuevo = new Nodo(pValor);
				nuevo->_siguiente = nodoAuxiliar->_siguiente;
				nodoAuxiliar->_siguiente = nuevo;

			}
		}
		_largoLista++;
	}
	//Muestra la lista
	void mostrar()
	{
		pNodo nodoAuxiliar = _primero;

		while (nodoAuxiliar)
		{
			cout << nodoAuxiliar->_valor << "->";
			nodoAuxiliar = nodoAuxiliar->_siguiente;
		}
		cout << endl;
	}
	//Poner al _Actual de la lista en el siguiente de la lista
	void siguiente()
	{
		if (_actual) _actual = _actual->_siguiente;
	}
	//Poner al _Actual de la lista en el primero de la lista
	void primero()
	{
		_actual = _primero;
	}
	//Poner al _Actual de la lista en el ultimo de la lista
	void ultimo()
	{
		_actual = _primero;
		if (!listaVacia())
			while (_actual->_siguiente) siguiente();
	}
	//Borra un valor al final de la lista
	void borrarFinal()
	{
		if (listaVacia())
		{
			cout << "No hay elementos en la Lista:" << endl;
		}
		else
		{
			if (_primero->_siguiente == NULL)
			{
				_primero = NULL;
			}
			else
			{
				pNodo nodoAuxiliar = _primero;

				while (nodoAuxiliar->_siguiente->_siguiente != NULL)
				{
					nodoAuxiliar = nodoAuxiliar->_siguiente;
				}

				pNodo temp = nodoAuxiliar->_siguiente;
				nodoAuxiliar->_siguiente = NULL;
				delete temp;
			}
			_largoLista--;
		}
	}
	//borra un valor al principio de la lista
	void borrarInicio()
	{
		if (listaVacia())
		{
			cout << "No hay elementos en la Lista:" << endl;
		}
		else
		{
			if (_primero->_siguiente == NULL)
			{
				pNodo nodoAuxiliar = _primero;
				_primero = NULL;
				delete nodoAuxiliar;
			}
			else
			{
				pNodo nodoAuxiliar = _primero;
				_primero = _primero->_siguiente;
				delete nodoAuxiliar;
			}
			_largoLista--;
		}
	}
	//Borra un valor en una posicion determinada de la lista
	void borrarPosicion(int pPosicion)
	{
		if (listaVacia())
		{
			cout << "Lista vacia" << endl;
		}
		else
		{
			if ((pPosicion>largoLista()) || (pPosicion<0))
			{
				cout << "Error en posicion" << endl;
			}
			else
			{
				pNodo nodoAuxiliar = _primero;

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
					pNodo nodoBorrar = nodoAuxiliar->_siguiente;
					nodoAuxiliar->_siguiente = nodoAuxiliar->_siguiente->_siguiente;
					delete nodoBorrar;
				}
				_largoLista--;
			}
		}
	}
	//Dice la cantidad de nodos o elementos que tiene la lista 
	int largoLista()
	{
		return _largoLista;
	}
	//Dice si la lista esta vacia o no 
	bool listaVacia() 
	{ 
		return _primero == NULL; 
	}
	//Devuleve el valor actual de la lista 
	string getValorActual()
	{
		if (_actual != NULL)
			return _actual->_valor;
		else
			return "";
	}
	//Poner un nodo de primero en la lista
	void setPrimero(pNodo parNodo)
	{
		_primero = parNodo;
	}
// Los atritutos de la lista
private:
	pNodo _primero;
	pNodo _actual;
	int _largoLista;

};

#endif