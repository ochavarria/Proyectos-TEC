#include <iostream>
#include "Principal.cpp"

using namespace std;

//EstaClase Ejecuta el Todo el Codigo para hacer la evaluacion de 5 Archivos con Expresiones

int main()
{
	bool errorLectura = false;
	string rutasArchivos[CANTIDADDEARCHIVOS] = { "Expresion1", "Expresion2", "Expresion3", "Expresion4", "Expresion5"};
	Principal principal;

	//LeerArchivos, Crear la Cola y Inserta Archivos en la Cola
	for each (string var in rutasArchivos)
	{
		bool hecho = principal.cargarExpPrefijo(new Archivo(var, "", "txt"));
		if (!hecho)
		{
			errorLectura = true;
			break;
		}
		principal.operar();
	}
	//Recorrer Cola , Crear PostFijo ,Evaluar e Imprimir

	
	cin.get();
	return 0;
}