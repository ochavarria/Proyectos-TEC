#include "LectorArchivo.h"
#include <iostream>


void LectorArchivo::abrir(string pRuta)
{
	buffer=-2;
	_administrador.open(pRuta, fstream::in);
	if(!estaAbierto())
		std::cout<<"No se encontro archivo"<< std::endl;
}

DatoTexto* LectorArchivo::leerTexto()
{
	DatoTexto* resultado = new DatoTexto();
	if (buffer==-2)
		buffer = _administrador.get();
	if (buffer != _interprete.NULO)
	{
		while (buffer != _interprete.NULO && !_interprete.esReconocido(buffer))
		{
			resultado->separacionatras = resultado->separacionatras+(char)buffer;
			buffer = _administrador.get();
		}
		while (_interprete.esReconocido(buffer))
		{
			resultado->palabra = resultado->palabra + (char)buffer;
			buffer = _administrador.get();
		}	
	}
		
	if (resultado->palabra != "")
		return resultado;
	else
		return nullptr;
}

DatoCodigo* LectorArchivo::leerCodigo()
{
	DatoCodigo* resultado = new DatoCodigo();

	buffer = _administrador.get();

	string buffercompleto = "";

	while (buffer!=_interprete.CAMBIOLINEA && buffer!=_interprete.NULO)
	{
		if (_interprete.esReconocido(buffer))
		{
			buffercompleto = buffercompleto + (char)buffer;
		}
		else
		{
			if (_interprete.esSeparador(buffer))
			{
				resultado->codigo = _conversor.stringToInt(buffercompleto);
				buffercompleto = "";
			}
		}
		buffer = _administrador.get();
	}
	resultado->dato = buffercompleto;
	
	if (resultado->dato != "")
		return resultado;
	else
		return nullptr;
}

DatoPalabra* LectorArchivo::leerArchivoPalabra()
{
	DatoPalabra* resultado = new DatoPalabra();

	buffer = _administrador.get();

	string buffercompleto = "";

	while (buffer!=_interprete.CAMBIOLINEA && buffer!=_interprete.NULO)
	{
		if (_interprete.esReconocido(buffer))
		{
			buffercompleto = buffercompleto + (char)buffer;
		}
		else
		{
			if (_interprete.esSeparador(buffer))
			{
				resultado->codigoLetra = _conversor.stringToInt(buffercompleto);
				resultado->dato = leerCodigo();
				break;
			}
		}
		buffer = _administrador.get();
	}
	if(resultado->dato)
	{
		if (resultado->dato->dato != "")
			return resultado;
	}
	else
		return nullptr;

}

DatoDefSin* LectorArchivo::leerArchivoDS()
{
	DatoDefSin* resultado = new DatoDefSin();

	buffer = _administrador.get();
	int caso = 0;
	string buffercompleto = "";

	while (buffer!=_interprete.CAMBIOLINEA && buffer!=_interprete.NULO)
	{
		if (_interprete.esReconocido(buffer) || (caso==3 && _interprete.esPuntuacion(buffer)))
		{
			buffercompleto = buffercompleto + (char)buffer;
		}
		else
		{
			if (_interprete.esSeparador(buffer))
			{
				bool fin = false;
				switch (caso)
				{
				case 0:
					resultado->codigoLetra = _conversor.stringToInt(buffercompleto);
					break;
				case 1:
					resultado->codigoPalabra = _conversor.stringToInt(buffercompleto);
					break;
				case 2:
					resultado->dato = new DatoCodigo();
					resultado->dato->codigo =  _conversor.stringToInt(buffercompleto);
					break;
				}
				caso++;
				buffercompleto="";
			}
		}
		buffer = _administrador.get();
	}

	if(resultado->dato)
	{	
		resultado->dato->dato = buffercompleto;
		if (resultado->dato->dato != "")
			return resultado;
	}
	else
		return nullptr;

}