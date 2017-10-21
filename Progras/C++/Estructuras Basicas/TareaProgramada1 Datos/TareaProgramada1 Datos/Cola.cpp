//Header del archivo
#ifndef DEFCOLA
#define DEFCOLA

//Librerias incluidas
#include "Nodo.cpp"
#include <iostream>
#include "Constantes.cpp"

typedef Nodo *pNodo;

using namespace std;

class Cola 
{
public:
	//Contructor de la clase cola
	Cola()
	{
		_frente = 0;
		_fondo = -1;
		_tamaño = CANTIDADDEARCHIVOS;
	}
	//Metodo que dice si la cola esta vacia o no
	bool colaVacia()
	{
		return _fondo < _frente;
	}   
	//Metodo que inserta un nodod a la cola 
	void insertar(string pValor)
	{
		if (_fondo < _tamaño)
		{
			_fondo++;
			pNodo _Nodo = new Nodo(pValor);
			_cola[_fondo] = _Nodo;
		}
		else
		{
			cout << "La cola esta llena";
		}
	}
	//Metodo que elimina un nodo de la cola 
	void eliminar()
	{
		if (!colaVacia())
		{

			_frente++;
		}
		else
		{
			cout << "La cola esta vacia";
		}
	}
	//Metodo que imprime la cola 
	void imprimir()
	{
		for (int i = _frente; i<_fondo + 1; i++)
		{
			cout << _cola[i] << "->";
		}
	}
	//Metodo que extrae el primero(nodo) de la cola
	pNodo Extraer()
	{
		if (!colaVacia())
		{
			return _cola[_frente];
		}
		else
		{
			return NULL;
			cout << "La cola esta vacia";
		}
	}
//Atributos de la cola
private:
	int _frente;
	int _fondo;
	pNodo _cola[CANTIDADDEARCHIVOS];
	int _tamaño;

};

#endif
	






 