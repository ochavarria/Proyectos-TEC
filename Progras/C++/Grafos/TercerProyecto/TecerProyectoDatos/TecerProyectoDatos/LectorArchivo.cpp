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
		resultado->x = (conversor->stringToInt(x))*0.07-200;
		resultado->y = (conversor->stringToInt(y))*0.07-12;
		return resultado;

	}
	else
	{

		if (buffer == _interprete.NULO)
		{
			error = true;
			cambioLinea = true;
		}
		else
		{
			if (buffer == _interprete.DOSPUNTOS)
			{
				buffer = _administrador.get();
			}
			else
			{
				if (buffer == _interprete.CAMBIOLINEA)
				{
					cambioLinea = true;
					buffer = _administrador.get();
				}
			}
		}
		return nullptr;
	}
}

Pais* LectorArchivo::leerPais()
{
	Pais* resultado = new Pais();
	int caso = 0;
	string codigo;

	if (buffer == -2)
		buffer = _administrador.get();

	while (buffer != _interprete.CAMBIOLINEA && buffer != _interprete.NULO)
	{
		if (buffer == _interprete.COMA)
			caso++;
		else
		{
			switch (caso)
			{
			case 0:
				codigo = codigo + char(buffer);
				break;
			case 1:
				resultado->nombre = resultado->nombre + char(buffer);
				break;
			}
		}
		buffer = _administrador.get();
	}
	if (buffer == _interprete.NULO)
	{
		error = true;
	}
	buffer = _administrador.get();
	resultado->codigo=conversor->stringToInt(codigo);
	return resultado;
}

Conexion* LectorArchivo::leerConexion()
{
	Conexion* resultado = new Conexion();
	int caso = 0;
	string codigo;

	if (buffer == -2)
		buffer = _administrador.get();

	while (buffer != _interprete.CAMBIOLINEA && buffer != _interprete.NULO)
	{
		if (buffer == _interprete.COMA)
		{
			switch (caso)
			{
			case 0:
				resultado->inicio = conversor->stringToInt(codigo);
				codigo = "";
				break;
			case 1:
				resultado->fin = conversor->stringToInt(codigo);
				codigo = "";
				break;
			}
			caso++;
		}
		else
		{
			codigo = codigo + char(buffer);
			
		}
		buffer = _administrador.get();
	}
	if (buffer == _interprete.NULO)
		error = true;
	buffer = _administrador.get();
	resultado->peso = conversor->stringToInt(codigo);
	return resultado;
}
