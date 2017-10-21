//Header del archivo
#ifndef DEFMARCHIVO
#define DEFMARCHIVO

//Librerias incluidas
#include <fstream>
#include "Archivo.cpp"
using namespace std;

class ManejadorArchivos
{
public:
	//Este metodo abre el archivo
	void abrir()
	{
		_administrador.open(_archivo->getDirectorio() + _archivo->getNombre() + "." + _archivo->getExtension());
	}
	//Este metodo cierra el archivo
	void cerrar()
	{
		_administrador.close();

	}
	//Este metodo Evalua si el archivo esta abierto
	bool abierto()
	{

		return _administrador.good();
	}
	//Este metodo Cambia el archivo 
	void cambioArchivo(Archivo *pArchivo)
	{
		cerrar();
		_archivo = pArchivo;
		abrir();
	}
//Atributos de la clase 
protected:
	Archivo *_archivo;
	ifstream _administrador;
	
};

#endif