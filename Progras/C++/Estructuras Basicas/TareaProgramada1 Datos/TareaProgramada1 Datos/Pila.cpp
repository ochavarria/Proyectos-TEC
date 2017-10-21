//Header del archivo
#ifndef DEFPILA
#define DEFPILA

//Librerias incluidas
#include "Nodo.cpp"
#include <iostream>
using std::cout;
using std::endl;


typedef Nodo *pNodo;

class Pila
{
public:

	//Constructor de la clase
	Pila()
	{
		_tope = NULL;
	}

	//Metodo que ingresa un valor a la pila
	void push(string pValor)
	{
		if (pilaVacia())
			_tope = new Nodo(pValor);
		else
			_tope = new Nodo(pValor, _tope);
	}

	//Metodo que saca un valor de la pila
	void pop()
	{
		if (pilaVacia())
		{
			cout << "No hay elementos en la Lista:" << endl;
		}
		else
		{
			if (_tope->_siguiente == NULL)
			{
				pNodo nodoAuxiliar = _tope;
				_tope = NULL;
				delete nodoAuxiliar;
			}
			else
			{
				pNodo nodoAuxiliar = _tope;
				_tope = _tope->_siguiente;
				delete nodoAuxiliar;
			}
		}
	}

	// Metodo que muestra los elementos de la pila 
	void mostrar()
	{
		pNodo nodoAuxiliar = _tope;

		while (nodoAuxiliar)
		{
			cout << nodoAuxiliar->_valor << "-> ";
			nodoAuxiliar = nodoAuxiliar->_siguiente;
		}
		cout << endl;
	}
	//Metodo que dice si la pila esta o no vacia
	bool pilaVacia() { return _tope == NULL; }

	//Metodo que devuelve el tope de la pila
	string getTope()
	{
		return _tope->_valor;
	}

//Atributo de la pila
protected:
	pNodo _tope;

};



#endif