#include "Palabra.h"

Palabra::Palabra(int pCodigo, string pPalabra):NodoAVL(pCodigo,pPalabra)
{
	definicion= nullptr;
	sinonimo= nullptr;
}