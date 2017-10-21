
#include <iostream>
#include "../../TecerProyectoDatos/TecerProyectoDatos/LectorArchivo.h"
#include "../../TecerProyectoDatos/TecerProyectoDatos/Grafo.h"

//Grafo* grafo = new Grafo();
//
//class g
//{
//public:
//	void cargarMapa()
//	{
//		LectorArchivo lector;
//		Vertice* vertice;
//		Punto* punto;
//		int contador = 0;
//
//		lector.abrir("../../TecerProyectoDatos/TecerProyectoDatos/Paises.txt");
//		Pais* pais = lector.leerPais();
//		while (!lector.error)
//		{
//		
//				cout<<"Codigo:"<<pais->codigo<<" Nombre:" <<pais->nombre<<endl;
//				pais = lector.leerPais();
//
//
//		}
//		lector.cerrar();
//	}
//
//	void cargarConexiones()
//	{
//		LectorArchivo lector;
//		lector.abrir("../../TecerProyectoDatos/TecerProyectoDatos/Conexiones.txt");
//
//		while (!lector.error)
//		{
//			Conexion* conex = lector.leerConexion();
//			if (conex)
//			{
//				grafo->agregarConexion(conex->inicio, conex->fin, conex->peso);
//			}
//		}
//		lector.cerrar();
//	}
//};

int main()
{
	//g a;
	//a.cargarMapa();


	Vertice* a = new Vertice(1,"a");//a
	Vertice* b = new Vertice(2, "b");//b
	Vertice* c = new Vertice(3, "c");//c
	Vertice* d = new Vertice(4, "d");//d
	Vertice* e = new Vertice(5, "e");//e
	Vertice* f = new Vertice(6, "f");//f
	Vertice* g = new Vertice(7, "g");//g
	Vertice* h = new Vertice(8, "h");//h
	Vertice* i = new Vertice(9, "i");//i


	Grafo* grafo = new Grafo();

	grafo->agregarNodo(a);//a


	grafo->agregarNodo(b);
	grafo->agregarNodo(c);//a
	grafo->agregarNodo(d);//a
	grafo->agregarNodo(e);//a
	grafo->agregarNodo(f);//a
	grafo->agregarNodo(g);//a
	grafo->agregarNodo(h);//a
	grafo->agregarNodo(i);//a

	grafo->agregarConexion(1, 2, 2, true);
	grafo->agregarConexion(1, 4, 1, true);
	grafo->agregarConexion(1, 3, 3, true);
	grafo->agregarConexion(2, 8, 3, true);
	grafo->agregarConexion(2, 5, 2, true);
	grafo->agregarConexion(2, 6, 6, true);
	grafo->agregarConexion(4, 6, 5, true);
	grafo->agregarConexion(3, 7, 4, true);
	grafo->agregarConexion(5, 8, 1, true);
	grafo->agregarConexion(6, 9, 1, true);


	grafo->mostrarGrafo();
	grafo->algoritmoDePrim();

	
	//Grafo* grafo2 = new Grafo();
	//grafo2->agregarNodo("a");
	//grafo2->agregarNodo("b");
	//grafo2->agregarNodo("c");
	//grafo2->agregarNodo("d");
	//grafo2->agregarNodo("e");
	//grafo2->agregarNodo("f");
	//grafo2->agregarNodo("g");
	//grafo2->agregarNodo("h");
	//grafo2->agregarNodo("i");
	//grafo2->agregarNodo("j");
	//grafo2->agregarConexion("a", "b", 2, true);
	//grafo2->agregarConexion("b", "c", 1, true);
	//grafo2->agregarConexion("c", "d", 3, true);
	//grafo2->agregarConexion("e", "f", 3, true);
	//grafo2->agregarConexion("f", "g", 2, true);
	//grafo2->agregarConexion("i", "h", 6, true);
	//grafo2->agregarConexion("j", "i", 5, true);
	//grafo2->agregarConexion("a", "e", 4, true);
	//grafo2->agregarConexion("a", "h", 1, true);

	//grafo2->mostrar();
	//grafo2->recorridoAnchura();
	//grafo2->recorridoProfundidad();
	

	std::cin.get();
}