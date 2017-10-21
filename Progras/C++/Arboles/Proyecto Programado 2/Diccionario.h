#pragma once

#include "ArbolNario.h"
#include "ArbolAA.h"
#include "ArbolB.h"
#include "ArbolRojoNegro.h"
#include "ArbolAVL.h"
#include "Cargador.h"
#include "DatoDiccionario.h"


class Diccionario
{
//Constructor
public:
	Diccionario();
	Diccionario(string pAbecedario,string pPalabras,string pSinonimo,string pDefinicion,string pEstudiantes);
//Atributos
private:
	enum caso {DEFINICIONES=1,SINONIMOS=2};
	//Arbol para almacenar los codigos para la busqueda
	ArbolNario _codigos;
	//Arbol para almacenar el encabezado del diccionario
	ArbolBB _abecedario;
	//Arbol que almacena la informacion de los estudiantes;
	ArbolB _estudiantes;
	//Arbol que almacena los sinonimos;
	ArbolAA _sinonimos;
	//Arbol que almacena las definiciones;
	ArbolRojoNegro _definiciones;
	//Arbol para el manejo de los datos obtenidos del abecedario;
	ArbolAVL _palabras;
	//Permite Todos los Archivos
	LectorArchivo _lector;
	//Variable para los recorridos 
	string _recorridos;
	//Variable para el usuario conectado
	string _usuario;

	
//Metodos
public:
	DatoDiccionario* buscar(string pPalabra);

	void setUsuario(string usuario);

	string buscarEstudiante(string codigoEstudiante);
private:
	//Carga el Archivo de Abecedario y crea el Arbol BB
	void cargarAbecedario(string pRuta);
	//Carga el Archivo Palabras y crea las conecciones pertinentes
	void cargarPalabras(string pRuta);
	//Carga el Archivo Definiciones y el de sinonimos
	void cargarDefSin(int caso,string pRuta);
	//Carga el Archivo estudiantes
	void cargarEstudiantes(string pRuta);
	//Recorre el encabezado
	void RecorrerEncabezado(NodoArbol*pRaiz);
	//Hace los recorridos del diccionario
	void Recorridos();

	void RecorrerEncabezadoaux(NodoArbol*pRaiz);

};

