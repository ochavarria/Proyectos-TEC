#include "Diccionario.h"
#include "Palabra.h"
#include "EscritorArchivo.h"

Diccionario::Diccionario()
{
	cargarAbecedario(RUTAABECEDARIO);
	cargarPalabras(RUTAPALABRAS);
	cargarDefSin(DEFINICIONES,RUTADEFINICIONES);
	cargarDefSin(SINONIMOS,RUTASINONIMOS);
	cargarEstudiantes(RUTAESTUDIANTES);
	Recorridos();
}

Diccionario::Diccionario(string pAbecedario,string pPalabras,string pSinonimo,string pDefinicion,string pEstudiantes)
{
	cargarAbecedario(pAbecedario);
	cargarPalabras(pPalabras);
	cargarDefSin(DEFINICIONES,pDefinicion);
	cargarDefSin(SINONIMOS,pSinonimo);
	cargarEstudiantes(pEstudiantes);
	Recorridos();
}

DatoDiccionario* Diccionario::buscar(string pPalabra)
{
	DatoDiccionario* resultado = nullptr;
	string letra = "";
	letra = letra+pPalabra[0];
	
	int codigoLetra = _codigos.buscar(letra);
	int codigoPalabra = _codigos.buscar(pPalabra);

	DatoTexto* dato=new DatoTexto();
	EscritorArchivo _escritor;

	dato->palabra = "Busqueda de la letra " + letra;
	dato->separacionatras = "\n";
	_escritor.abrir(RUTAPALABRASVISITADAS,false);
	_escritor.escribir(dato);

	Letra* nodoLetra= (Letra*)_abecedario.buscar(codigoLetra,true);
	if(nodoLetra)
	{
		_palabras.setRaiz(nodoLetra->palabras);

		dato->palabra = "Busqueda de la Palabra " + pPalabra;
		dato->separacionatras = "\n";
		_escritor.abrir(RUTAPALABRASVISITADAS, false);
		_escritor.escribir(dato);
		_escritor.cerrar();

		Palabra* nodoPalabra = (Palabra*)_palabras.buscar(codigoPalabra,true);

		dato->palabra = "Palabra buscada " + pPalabra;
		dato->separacionatras = "\n";
		_escritor.abrir(RUTAPALABRASBUSCADAS, false);
		_escritor.escribir(dato);
		_escritor.cerrar();

		
		if(nodoPalabra)
		{
			resultado = new DatoDiccionario();
			resultado->palabra = nodoPalabra->getDato();
			resultado->definicion = nodoPalabra->definicion->getDato();
			resultado->sinonimo = nodoPalabra->sinonimo->getDato();
		}
	}
	return resultado;
}

string Diccionario::buscarEstudiante(string codigoEstudiante)
{
	try
	{
		int codigo =_lector._conversor.stringToInt(codigoEstudiante);
		return _estudiantes.buscar(codigo);
	}
	catch (...)
	{
		return "";
	}
	
}
void Diccionario::setUsuario(string usuario)
{
	DatoTexto* dato = new DatoTexto();
	EscritorArchivo _escritor;
	dato->palabra = usuario+"\n";
	_escritor.abrir(RUTAPALABRASBUSCADAS, false);
	_escritor.escribir(dato);
	_usuario = usuario;
}
void Diccionario::cargarAbecedario(string pRuta)
{
	_lector.abrir(pRuta);
	DatoCodigo* letra = _lector.leerCodigo();
	while(letra)
	{
		Letra* nodoletra = new Letra(letra->codigo,letra->dato);
		_codigos.insertar(letra->codigo,letra->dato);
		_abecedario.insertar(nodoletra);
		letra = _lector.leerCodigo();
	}
	
	_lector.cerrar();
}

void Diccionario::cargarPalabras(string pRuta)
{
	_lector.abrir(pRuta);
	DatoPalabra* palabra = _lector.leerArchivoPalabra();
	while(palabra)
	{
		Letra* letra =(Letra*)_abecedario.buscar(palabra->codigoLetra,false);
		if(letra)
		{
			Palabra* nodoPalabra = new Palabra(palabra->dato->codigo,palabra->dato->dato);
			_codigos.insertar(palabra->dato->codigo,palabra->dato->dato);
			_palabras.setRaiz(letra->palabras);
			_palabras.insertar(nodoPalabra);
			if(!letra->palabras)
				letra->palabras = (Palabra*)_palabras.getRaiz();
		}
		palabra = _lector.leerArchivoPalabra();
	}

	_lector.cerrar();
}

void Diccionario::cargarDefSin(int caso,string pRuta)
{

	_lector.abrir(pRuta);

	DatoDefSin* lectura = _lector.leerArchivoDS();
	while(lectura)
	{
		Letra* letra =(Letra*)_abecedario.buscar(lectura->codigoLetra,false);
		if(letra)
		{
			_palabras.setRaiz(letra->palabras);
			Palabra* palabra = (Palabra*)_palabras.buscar(lectura->codigoPalabra,false);
			if(palabra)
			{	
				NodoRojoNegro* definicion = new NodoRojoNegro(lectura->dato->codigo,lectura->dato->dato);
				NodoAA* sinonimo = new NodoAA(lectura->dato->codigo,lectura->dato->dato);
				switch (caso)
				{
				case DEFINICIONES:
					_definiciones.insertar(definicion);
					palabra->definicion= definicion;
					break;
				case SINONIMOS:
					_sinonimos.insertar(sinonimo);
					palabra->sinonimo= sinonimo;
					break;
				}
			}
		}
		lectura = _lector.leerArchivoDS();
	}


	_lector.cerrar();
}

void Diccionario::cargarEstudiantes(string pRuta)
{
	_lector.abrir(pRuta);
	DatoCodigo* estudiante = _lector.leerCodigo();
	while(estudiante)
	{
		_estudiantes.insertar(estudiante->codigo,estudiante->dato);
		estudiante = _lector.leerCodigo();
	}
	_lector.cerrar();
}

void Diccionario::RecorrerEncabezado(NodoArbol*pRaiz)
{
	DatoTexto* dato = new DatoTexto();
	EscritorArchivo _escritor;
	RecorrerEncabezadoaux(pRaiz);
	_escritor.abrir(RUTARECORRIDOPALABRAS, true);
	dato->palabra = _recorridos;
	_escritor.escribir(dato);
	_escritor.cerrar();
}
void Diccionario::RecorrerEncabezadoaux(NodoArbol*pRaiz)
{
	if (pRaiz != nullptr)
	{

		_recorridos += _palabras.Recorridos(((Letra*)pRaiz)->palabras);
		RecorrerEncabezadoaux(pRaiz->_hijoIzquierdo);
		RecorrerEncabezadoaux(pRaiz->_hijoDerecho);
	}

}
void Diccionario::Recorridos()
{
	_abecedario.Recorridos();
	NodoArbol* abecedarioRaiz = _abecedario.getRaiz();
	RecorrerEncabezado(abecedarioRaiz);
	_definiciones.Recorridos();
	_sinonimos.Recorridos();
	_estudiantes.Recorridos();

}