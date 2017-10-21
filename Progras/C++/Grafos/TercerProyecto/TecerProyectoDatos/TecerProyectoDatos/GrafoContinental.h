#pragma once

#include "LectorArchivo.h"
#include "MapaGrafico.h"
#include "Grafo.h"
#include "PaisGrafico.h"
#include "ArcoGrafico.h"

public ref class GrafoContinental
{
public:
	MapaGrafico^ mapa;
	Grafo* grafoMapa;
	Grafo* grafoPaises;
	System::Windows::Forms::Panel^ panel;
	List<PaisGrafico^>^ paises = gcnew List<PaisGrafico^>();
	List<ArcoGrafico^>^ arcos = gcnew List<ArcoGrafico^>();
	

	GrafoContinental(System::Windows::Forms::Panel^ ppanel)
	{
		grafoMapa = new Grafo();
		mapa = gcnew MapaGrafico();
		panel = ppanel;
		mapa->areaDeDibujo = ppanel->CreateGraphics();
		cargarMapa();
		cargarConexiones();
	}

	void cargarMapa()
	{
		LectorArchivo lector;
		VerticeGrafico^ verticeg;
		Vertice* vertice;
		Punto* punto;
		Point point;
		int contador = 0;

		lector.abrir("Mapa.txt");

		while (!lector.error)
		{
			Pais* pais = lector.leerPais();
			vertice = new Vertice(pais->codigo,pais->nombre);
			verticeg = gcnew VerticeGrafico();
			verticeg->nombre = gcnew System::String(pais->nombre.c_str());
			vertice->color = 0;
			grafoMapa->agregarNodo(vertice);

			while (!lector.cambioLinea)
			{
				List<Point>^ puntos = gcnew List<Point>();
				punto = lector.leerPunto();
				while (punto)
				{
					point = Point(punto->x, punto->y);
					puntos->Add(point);
					punto = lector.leerPunto();
				}
				if (puntos->Count > 0)
					verticeg->añadir(puntos->ToArray());
			}
			contador++;
			lector.cambioLinea = false;
			mapa->partes->Add(verticeg);

		}
		lector.cerrar();
	}
	void cargarConexiones()
	{
		LectorArchivo lector;
		lector.abrir("Conexiones.txt");

		while (!lector.error)
		{
			Conexion* conex=lector.leerConexion();
			if (conex)
				grafoMapa->agregarConexion(conex->inicio, conex->fin, conex->peso);
		}
		lector.cerrar();
	}

	//Segunda Parte
	void cargarSegundaParte()
	{
		cargarPaises();
		cargarPosicionesPaises();
		cargarConexionesPaises();
	}
	void cargarPaises()
	{
		LectorArchivo lector;
		Vertice* vertice;
		lector.abrir("Paises.txt");
		Pais* pais = lector.leerPais();
		while (!lector.error)
		{
			vertice = new Vertice(pais->codigo, pais->nombre);
			grafoMapa->agregarNodo(vertice);
			pais = lector.leerPais();
		}
		lector.cerrar();
	}
	void cargarPosicionesPaises()
	{
		LectorArchivo lector;
		lector.abrir("Posicion.txt");
		while (!lector.error)
		{
			Conexion* conex = lector.leerConexion();
			if (conex)
			{
				PaisGrafico^ pais = gcnew PaisGrafico(conex->inicio, conex->fin, conex->peso);
				panel->Controls->Add(pais->cuadroImagen);
				paises->Add(pais);
				
			}
		}
		lector.cerrar();
	}
	void cargarConexionesPaises()
	{
		LectorArchivo lector;
		lector.abrir("Uniones.txt");
		while (!lector.error)
		{
			Conexion* conex = lector.leerConexion();
			if (conex)
			{
				grafoMapa->agregarConexion(conex->inicio, conex->fin, conex->peso);
				ArcoGrafico^ arco = gcnew ArcoGrafico();
				Point inicio = buscarPais(conex->inicio);
				Point fin = buscarPais(conex->fin);
				if (inicio.X != -1 && fin.X != -1)
				{
					arco->crear(inicio, fin);
					mapa->areaDeDibujo->DrawPath(gcnew Pen(Color::Black), arco->forma);
				}
			}
		}
		lector.cerrar();
	}
	Point buscarPais(int codigo)
	{
		Point resultado = Point(-1,-1);
		for (int i = 0; i < paises->Count;i++)
		{
			if(paises[i]->codigo==codigo)
			{
				resultado = paises[i]->posicion;
				break;
			}
		}
		return resultado;
	}

	System::String^ colorear()
	{
		grafoMapa->colorear();
		System::String^ resultado = "";
		System::String^ nombrepais;
		array<Color>^ colores = {Color::White , Color::Blue, Color::Yellow, Color::Green, Color::Red };
		grafoMapa->_listaDeAyacencia->primero();
		Vertice* auxiliar = (Vertice*)grafoMapa->_listaDeAyacencia->getActual();
		int contador = 0;
		while (auxiliar)
		{
			nombrepais = gcnew System::String(auxiliar->_nombre.c_str());
			mapa->partes[contador]->color = colores[auxiliar->color];
			resultado = resultado + nombrepais + " = " + mapa->partes[contador]->nombre + "\n";
			contador++;
			grafoMapa->_listaDeAyacencia->siguiente();
			auxiliar = (Vertice*)grafoMapa->_listaDeAyacencia->getActual();
		}
		return resultado;
	}
	
};