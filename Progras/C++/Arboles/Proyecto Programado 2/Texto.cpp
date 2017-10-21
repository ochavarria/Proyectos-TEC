#include "Texto.h"

bool Texto::modificar(string pPalabra, string pRemplazo,bool inicio)
{
	if (inicio)
		ultimoModificado = (NodoTexto*)texto.buscar(pPalabra, inicio);
	else
	{
		if (ultimoModificado)
		{
			texto.setActual(ultimoModificado);
			ultimoModificado = (NodoTexto*)texto.buscar(pPalabra, false);
		}
	}
	if (ultimoModificado && pPalabra != pRemplazo)
	{
		NodoTexto * nuevo= (NodoTexto*)texto.buscar(pRemplazo,true);
		ultimoModificado->_dato = pRemplazo;
		ultimoModificado->repeticion->valor--;
		if (nuevo)
			ultimoModificado->repeticion = nuevo->repeticion;
		else
			ultimoModificado->repeticion = new Entero(1);
		return true;
	}
	else
		return false;
}

void Texto::guardar(string pRuta)
{
	if (!texto.listaVacia())
	{
		_escritor.abrir(pRuta);

		texto.primero();

		while (!texto.fin)
		{
			DatoTexto* palabra = new DatoTexto();
			NodoTexto* nodo = (NodoTexto*)texto.getActual();
			palabra->palabra = nodo->_dato;
			palabra->separacionatras = nodo->_separacionatras;
			_escritor.escribir(palabra);
			texto.siguiente();
		}
		_escritor.cerrar();
	}
}

void Texto::cargar()
{
	DatoTexto* palabraleida = _lector.leerTexto();
	while (palabraleida)
	{
		NodoTexto* palabra = new NodoTexto();
		palabra->_dato = palabraleida->palabra;
		palabra->_separacionatras = palabraleida->separacionatras;

		NodoTexto* repeticion = (NodoTexto*) texto.buscar(palabra->_dato);
		if (repeticion)
		{
			palabra->repeticion = repeticion->repeticion;
			palabra->repeticion->valor++;
		}
		else
		{
			palabra->repeticion = new Entero(1);
		}

		texto.insertaFinal(palabra);
		palabraleida = _lector.leerTexto();
	}
}

int Texto::cantidadPalabras()
{
	return texto.largo();
}

DatoTexto* Texto::getPalabraTexto(bool iniciar)
{
	if (iniciar)
		texto.primero();
	if (texto.fin)
		return nullptr;
	else
	{
		DatoTexto* resultado = new DatoTexto();
		NodoTexto* actual = (NodoTexto*)texto.getActual();
		resultado->palabra = actual->_dato;
		resultado->separacionatras = actual->_separacionatras;
		resultado->repeticion = actual->repeticion->valor;
		texto.siguiente();
		return resultado;
	}
}

int Texto::repeticionesPalabra(string pPalabra)
{
	NodoTexto* resultado = (NodoTexto*)texto.buscar(pPalabra, true);
	if (resultado)
		return resultado->repeticion->valor;
	else
		return 0;
}