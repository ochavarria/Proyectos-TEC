#pragma once


#include "NodoLista.h"
#include <string>

using std::string;

class Vertice: public NodoLista
{
//Constructor
public:
	Vertice(int pDato,string pNombre);
//Atributos
//protected:
	string _nombre;
	bool _visitado;
	NodoLista* _conexiones;
	
public:
	int color;
	int grado;
	int gradoerror;

	friend class Grafo;
};