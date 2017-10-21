#include  "NodoRojoNegro.h"

//Constructor
NodoRojoNegro::NodoRojoNegro():NodoArbol()
{
	_rojo=true;
}

NodoRojoNegro::NodoRojoNegro(int pValor):NodoArbol(pValor)
{
	_rojo=true;
}

NodoRojoNegro::NodoRojoNegro(int pValor, string pDato):NodoArbol(pValor,pDato)
{
	_rojo=true;
}