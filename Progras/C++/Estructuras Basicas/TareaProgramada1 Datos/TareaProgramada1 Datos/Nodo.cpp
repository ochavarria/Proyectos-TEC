//Header del archivo
#ifndef DEFNODO
#define DEFNODO

//Librerias incluidas
#include <string>
using std::string;

class Nodo{
public:
	//Constructor de la clase Con siguiente igual a null
	Nodo(string pValor)
	{
		_valor = pValor;
		_siguiente = NULL;
	}
	//Constructor de la clase Con siguiente igual a un puntero
	Nodo(string pValor, Nodo *pNodo)
	{
		_valor = pValor;
		_siguiente = pNodo;
	}

//Atributo de la clase
protected:
	string _valor;
	Nodo *_siguiente;

	friend class ListaSimple;
	friend class Pila;
	friend class Cola;

};

#endif