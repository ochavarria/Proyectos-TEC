#include "NodoB.h"

NodoB::NodoB()
{
	_cuenta=0;
	for (int i = 0 ;i<TAMANOCLAVES+1;i++)
	{
		_ramas[i]=nullptr;
		datos[i]="";
	}
}