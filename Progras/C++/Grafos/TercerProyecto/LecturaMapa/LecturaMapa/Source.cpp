#include <iostream>
#include "LectorArchivo.h"
#include "EscritorArchivo.h"
using namespace std;
  
int main()
{
	LectorArchivo lector;
	Punto* p;
	string a = "";
		Punto* punto;
	
		int contador = 1;

		lector.abrir("Mapa.txt");

		while (!lector.error)
		{
			cout << "Pais Nuevo"<< contador;
			while (!lector.nuevoPais)
			{
				punto = lector.leerPunto();
				while (punto)
				{
					punto = lector.leerPunto();
				}

			}
			contador++;
			lector.nuevoPais = false;
		}

	
	lector.cerrar();


}