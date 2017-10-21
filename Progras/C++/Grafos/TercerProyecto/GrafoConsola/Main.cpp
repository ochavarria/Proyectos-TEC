
#include <iostream>
#include "../../TecerProyectoDatos/TecerProyectoDatos/LectorArchivo.h"
#include  "../../TecerProyectoDatos/TecerProyectoDatos/Grafo.h"
Grafo* grafo = new Grafo();

class g
{
public:
	void cargarMapa()
	{
		LectorArchivo lector;
		Vertice* vertice;
		Punto* punto;
		int contador = 0;

		lector.abrir("../../TecerProyectoDatos/TecerProyectoDatos/Mapa.txt");

		while (!lector.error)
		{
			Pais* pais = lector.leerPais();
			vertice = new Vertice(pais->codigo, pais->nombre);
			vertice->color = 0;
			grafo->agregarNodo(vertice);

			while (!lector.cambioLinea)
			{

				punto = lector.leerPunto();
				while (punto)
				{
					punto = lector.leerPunto();
				}
			}
			contador++;
			lector.cambioLinea = false;
		}
		lector.cerrar();
	}

	void cargarConexiones()
	{
		LectorArchivo lector;
		lector.abrir("../../TecerProyectoDatos/TecerProyectoDatos/Conexiones.txt");

		while (!lector.error)
		{
			Conexion* conex = lector.leerConexion();
			if (conex)
			{
				grafo->agregarConexion(conex->inicio, conex->fin, conex->peso);
			}
		}
		lector.cerrar();
	}
};

int main()
{
	g a;
	a.cargarMapa();
	a.cargarConexiones();
	grafo->mostrar();
	std::cin.get();
}