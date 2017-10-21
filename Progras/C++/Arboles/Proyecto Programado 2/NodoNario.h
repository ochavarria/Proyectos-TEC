#pragma once

#include  "Constantes.h"

class NodoNario
{
public:
//Constructor
	NodoNario();
	NodoNario(int pValor);
//Atributos
//private:
	int _valor;
	NodoNario* _hijos [TAMANOABECEDARIO];

friend class ArbolNario;
};

