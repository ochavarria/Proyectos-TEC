//Header del archivo
#ifndef DEFARCHIVO
#define DEFARCHIVO

//Librerias incluidas
#include <string>

using namespace std;
// Acomoda la dirrecion dada del archivo Por nombre, directorio y extencion. 
class Archivo
{
public:
	//contrucctor de la clase 
	Archivo(string pNombre, string pDirectorio, string pExtension)
	{
		_nombre = pNombre;
		_directorio = pDirectorio;
		_extension = pExtension;
	}
	//Metodo que devuelve el nombre del archivo
	string getNombre()
	{
		return _nombre;
	}
	//Metodo que devuelve el direcctorio del archivo
	string getDirectorio()
	{
		return _directorio;
	}
	//Metodo que devuelve la extension del archivo
	string getExtension()
	{
		return _extension;
	}
	//Metodo que permite editar el atribulo _nombre de la clase
	void setNombre(string pNombre)
	{
		_nombre = pNombre;
	}
	//Metodo que permite editar el atribulo _directorio de la clase
	void setDirectorio(string pDirectorio)
	{
		_directorio = pDirectorio;
	}
	//Metodo que permite editar el atribulo _extencion de la clase
	void setExtension(string pExtension)
	{
		_extension = pExtension;
	}
	//Atributos de la clase
private:
	string _nombre;
	string _directorio;
	string _extension;
};

#endif