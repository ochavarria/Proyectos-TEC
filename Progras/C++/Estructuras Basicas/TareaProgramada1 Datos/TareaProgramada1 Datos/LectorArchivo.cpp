//Header del archivo
#ifndef DEFLARCHIVO
#define DEFLARCHIVO

//Librerias incluidas
#include "ManejadorArchivo.cpp"
#include "InterpreteASCII.cpp"
#include <iostream>

class LectorArchivo:public ManejadorArchivos
{
public:
	bool errorLectura;
	bool fin;
	//Costructor de la clase
	LectorArchivo()
	{
		errorLectura = false;
		fin = false;
		_buffer = -1;
	}
	//Metodo que lee el archivo digito por digito
	string leerDigito()
	{
		string resultado = "";
		_seguirLectura = true;
		char conversor;
		while (_seguirLectura)
		{
			if (_buffer == -1)
			{
				_buffer = _administrador.get();
				if (_interprete.esOperador(_buffer))
				{
					conversor = (char)_buffer;
					resultado = conversor;
					_seguirLectura = false;
					_buffer = -1;
				}
				else
				{
					if (_interprete.esNumero(_buffer))
					{
						while (_interprete.esNumero(_buffer)|| _interprete.esDesechable(_buffer))
						{
							if (!_interprete.esDesechable(_buffer))
							{
								conversor = (char)_buffer;
								resultado = resultado + conversor;
							}
							_buffer = _administrador.get();
							
						}
						_seguirLectura = false;
					}
					else
					{
						esElFinal();
					}
				}
			}
			else
			{
				if (_interprete.esOperador(_buffer))
				{
					conversor = (char)_buffer;
					resultado = conversor;
					_seguirLectura = false;
					_buffer = -1;
				}
				else
				{
					esElFinal();
				}
			}
		}
		return resultado;
	}
	//Metodo que identifica el final del archivo 
	void esElFinal()
	{
		if (_administrador.eof())
		{
			fin = true;
			_seguirLectura = false;
		}
		else
		{
			if (_interprete.esDesechable(_buffer))
			{
				_buffer = -1;
			}
			else
			{
				errorLectura = true;
				_seguirLectura = false;
				if (_buffer==-1)
					cout << "Archivo no Encontrado o Vacio" << endl;
				else
					cout << "Caracter no reconocido" << endl;
			}
		}
	}
	//Atributos de la clase
	
private:
	int _buffer;
	InterpreteASCII _interprete;
	bool _seguirLectura;
};

#endif