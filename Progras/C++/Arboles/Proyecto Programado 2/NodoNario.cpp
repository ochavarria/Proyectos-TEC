#include  "NodoNario.h"

NodoNario::NodoNario()
{
	for (int i = 0 ;i<TAMANOABECEDARIO;i++)
	{
		_hijos[i]=nullptr;
	}
	_valor=-1;
}

NodoNario::NodoNario(int pValor)
{
	for (int i = 0 ;i<TAMANOABECEDARIO;i++)
	{
		_hijos[i]=nullptr;
	}
	_valor=pValor;
}