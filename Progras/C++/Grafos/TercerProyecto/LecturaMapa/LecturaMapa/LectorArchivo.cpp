#include "LectorArchivo.h"
#include <iostream>


void LectorArchivo::abrir(string pRuta)
{
	buffer=-2;
	error = false;
	_administrador.open(pRuta, fstream::in);
	if(!estaAbierto())
		std::cout<<"No se encontro archivo"<< std::endl;
}

Punto* LectorArchivo::leerPunto()
{
	Punto* resultado = new Punto();
	string x = "";
	string y = "";
	int caso = 0;

	if (buffer==-2)
		buffer = _administrador.get();
	
	while (!_interprete.esNumero(buffer) && buffer != _interprete.NULO && buffer != _interprete.CAMBIOLINEA && buffer!= _interprete.DOSPUNTOS)
		buffer = _administrador.get();
		
	if (_interprete.esNumero(buffer))
	{
		while (buffer!=_interprete.ESPACIO)
		{
			if (buffer == _interprete.COMA)
			{
				caso++;
			}
			else
			{
				switch (caso)
				{
				case 0:
					x = x + char(buffer);
					break;
				case 1:
					y = y + char(buffer);
					break;
				}
			}
			buffer = _administrador.get();
		}
	}
	
	if (x != "" && y!="")
	{		
		resultado->x = (conversor->stringToInt(x))*0.065-200;
		resultado->y = (conversor->stringToInt(y))*0.065;
		return resultado;

	}
	else
	{

		if (buffer == _interprete.NULO)
		{
			nuevoPais = true;
			error = true;
		}
		else
		{
			if (buffer == _interprete.DOSPUNTOS)
			{
				nuevoPais = false;
				buffer = _administrador.get();
			}
			else
			{
				if (buffer == _interprete.CAMBIOLINEA)
				{
					nuevoPais = true;
					buffer = _administrador.get();
				}
			}
		}
		return nullptr;
	}
}
