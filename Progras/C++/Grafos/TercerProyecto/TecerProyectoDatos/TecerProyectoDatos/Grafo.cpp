#include "Grafo.h"
#include "Cola.h"
#include "Pila.h"

#include <string>

#include <string>

//#include <msclr\marshal_cppstd.h>

Grafo::Grafo()
{
	_listaDeAyacencia = new ListaSimple();
	_admistradradorArcos = new ListaSimple();
}
//Metodos Publicos
void Grafo::agregarConexion(int pInicio, int pFin, int pPeso,bool doble)
{
	Vertice* inicio = (Vertice*) _listaDeAyacencia->buscar(pInicio);
	Vertice* fin = (Vertice*) _listaDeAyacencia->buscar(pFin);
	if(inicio!=nullptr && fin!=nullptr)
	{
		Arco* nuevo = new Arco(pPeso,inicio,fin);
		if(inicio->_conexiones==nullptr)
			inicio->_conexiones=nuevo;
		else
		{
			_admistradradorArcos->setPrimero(inicio->_conexiones);
			_admistradradorArcos->insertarFinal(nuevo);
		}
		if(doble)
		{
			nuevo = new Arco(pPeso,fin,inicio);
			if(fin->_conexiones==nullptr)
				fin->_conexiones=nuevo;
			else
			{
				_admistradradorArcos->setPrimero(fin->_conexiones);
				_admistradradorArcos->insertarFinal(nuevo);
			}
		}
	}
	else
		cout<<"Alguno de los vertices no existe por favor agregelo"<<endl;
}

void Grafo::agregarNodo(Vertice* pDato)
{
	Vertice* nuevo = (Vertice*)_listaDeAyacencia->buscar(pDato->_valor);
	if(nuevo==nullptr)
	{
		nuevo = new Vertice(pDato->_valor,pDato->_nombre);
		_listaDeAyacencia->insertarFinal(nuevo);
	}
	else
		cout<<"El vertice ya existe"<<endl;
}

void Grafo::recorrido(int tipo)
{
	Pila pila;
	Cola cola;

	ListaSimple* conexiones = new ListaSimple();
	ListaSimple* visitados = new ListaSimple();

	_listaDeAyacencia->primero();

	Vertice* primero = (Vertice*)_listaDeAyacencia->getActual();
	Vertice* vertice = new Vertice(primero->_valor,primero->_nombre);
	vertice->_conexiones = primero->_conexiones;
	insertarSegunTipo(vertice,tipo,&cola,&pila);

	while(!cola.colaVacia()||!pila.pilaVacia())
	{
		Vertice* elemento = nullptr;
		switch (tipo)
		{
		case ANCHURA:
			elemento = cola.extraer();
			cola.eliminar();
			break;
		case PROFUNDIDA:
			elemento = pila.pop();
			break;
		}
		
		if(!visitados->buscar(elemento->_valor))
		{
			visitados->insertarInicio(elemento->_valor);
			cout<<elemento->_valor<<"-";
		
			conexiones->setPrimero(elemento->_conexiones);
			Arco* conexion = (Arco*)conexiones->getActual();
			while(conexion)
			{
				if(!visitados->buscar(conexion->_fin->_valor))
				{
					vertice = new Vertice(conexion->_fin->_valor,"");
					vertice->_conexiones = conexion->_fin->_conexiones;
					insertarSegunTipo(vertice,tipo,&cola,&pila);
				}
				conexiones->siguiente();
				conexion = (Arco*)conexiones->getActual();
			}
		}
	}
	cout<<endl;
}

void Grafo::recorridoProfundidad()
{
	recorrido(PROFUNDIDA);
}

void Grafo::recorridoAnchura()
{
	recorrido(ANCHURA);
}

void Grafo::mostrar()
{
	int cont = 0;
	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getActual();
	ListaSimple* conexiones = new ListaSimple();
	while(aux)
	{
		cout<<cont<<"->"<<aux->_nombre<<" Color:"<<aux->color<<endl;
		cont++;
		conexiones->setPrimero(aux->_conexiones);

		Arco* conexion = (Arco*)conexiones->getActual();
		while(conexion)
		{
			//cout<<"Conexion :"<<conexion->_incio->_valor<<" - "<<conexion->_fin->_valor<<" Peso:"<<conexion->_peso<<") "<<endl;
			cout << "Pais:" << conexion->_fin->_nombre << " Color:" << conexion->_fin->color << endl;
			conexiones->siguiente();
			conexion = (Arco*)conexiones->getActual();
		}
		cout<<endl;
		_listaDeAyacencia->siguiente();
		aux = (Vertice*)_listaDeAyacencia->getActual();
	}
}
void Grafo::mostrarGrafo()
{
	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getActual();
	ListaSimple* conexiones = new ListaSimple();
	while (aux)
	{
		cout << aux->_valor << endl;

		conexiones->setPrimero(aux->_conexiones);
		conexiones->primero();

		Arco* conexion = (Arco*)conexiones->getActual();
		while (conexion)
		{
			cout << "(Conexion :" << conexion->_incio->_valor << " - " << conexion->_fin->_valor << " Peso:" << conexion->_peso << ") " << endl;
			conexiones->siguiente();
			conexion = (Arco*)conexiones->getActual();
		}
		cout << endl;
		_listaDeAyacencia->siguiente();
		aux = (Vertice*)_listaDeAyacencia->getActual();
	}
}
void Grafo::colorear()
{
	despintar();
	grado();
	gradoError();
	int indice = 0;
	ordenarPorGrado();
	while (indice!=_listaGrado.size())
	{
		if (indice == 30)
			cout << "hola" << endl;
		if (!pintar(_listaGrado[indice]))
		{
			cout << _listaGrado[indice]->_nombre << " pintado de color " << _listaGrado[indice]->color << endl;
			_listaGrado[indice]->gradoerror++;
			indice = -1;
			despintar();
			ordenamiento();
		}
		
		indice++;
	}
}

void Grafo::grado()
{
	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getActual();
	while (aux)
	{
		_admistradradorArcos->setPrimero(aux->_conexiones);
		aux->grado = _admistradradorArcos->largoLista();
		_listaDeAyacencia->siguiente();
		aux = (Vertice*)_listaDeAyacencia->getActual();
	}
}

void Grafo::gradoError()
{
	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getActual();
	ListaSimple* conexiones = new ListaSimple();
	while (aux)
	{
		aux->gradoerror = aux->grado;
		if (aux->grado >= 4)
		{
			conexiones->setPrimero(aux->_conexiones);
			Arco* conexion = (Arco*)conexiones->getActual();
			
			while (conexion)
			{
				if (conexion->_fin->grado >= aux->grado)
					aux->gradoerror++;
				conexiones->siguiente();
				conexion = (Arco*)conexiones->getActual();
			}
		}
		_listaDeAyacencia->siguiente();
		aux = (Vertice*)_listaDeAyacencia->getActual();
	}
}

bool Grafo::pintar(Vertice* pVertice)
{
	bool colores[5] = { true, false, false, false,false };

	_admistradradorArcos->setPrimero(pVertice->_conexiones);

	Arco* conexion = (Arco*)_admistradradorArcos->getActual();

	while (conexion)
	{
		if (conexion->_fin->color!=0)
			colores[conexion->_fin->color] = true;
		
		_admistradradorArcos->siguiente();
		conexion = (Arco*)_admistradradorArcos->getActual();
	}
	int indice = 0;
	for (indice=0; indice < 5;indice++)
	{
		if (!colores[indice])
		{
			pVertice->color = indice;
			break;
		}
	}
	if (indice == 5)
		return false;
	else
		return true;
}

void Grafo::ordenarPorGrado()
{
	Vertice* menor = new Vertice(0,"");
	menor->gradoerror = -1;
	Vertice* Mayor = menor;
	int largo = _listaDeAyacencia->largoLista();
	while (_listaGrado.size()!=largo)
	{
		Mayor = menor;
		_listaDeAyacencia->primero();
		Vertice* aux = (Vertice*)_listaDeAyacencia->getActual();
		while (aux)
		{
			if(aux->gradoerror>Mayor->gradoerror && !aux->_visitado)
			{
				Mayor = aux;
			}
			_listaDeAyacencia->siguiente();
			aux = (Vertice*)_listaDeAyacencia->getActual();
		}
		Mayor->_visitado = true;
		cout << "Grado:" << Mayor->grado << " GradoEror:" << Mayor->gradoerror << " Nombre:" << Mayor->_nombre << endl;
		_listaGrado.push_back(Mayor);
	}
}

void Grafo::ordenamiento()
{
	int inicio = 0;
	int fin = _listaGrado.size();
	int mayor, actual;
	Vertice* nodoTemp;
	while (inicio < fin)
	{
		mayor = inicio;
		for (actual = inicio; actual < fin; actual++)
		{
			if (_listaGrado[actual]->gradoerror>_listaGrado[mayor]->gradoerror)
			{
				mayor = actual;
			}
		}
		nodoTemp = _listaGrado[inicio];
		_listaGrado[inicio] = _listaGrado[mayor];
		_listaGrado[mayor] = nodoTemp;
		inicio++;
	}
	for (Vertice* Mayor : _listaGrado)
	{
		cout << "Grado:" << Mayor->grado << " GradoEror:" << Mayor->gradoerror << " Nombre:" << Mayor->_nombre << endl;
	}

}

void Grafo::insertarSegunTipo(Vertice* pVertice, int pTipo, Cola* pCola, Pila* pPila)
{
	switch (pTipo)
	{
	case ANCHURA:
		pCola->insertar(pVertice);
		break;
	case PROFUNDIDA:
		pPila->push(pVertice);
		break;
	}
}

void Grafo::desvisitar()
{
	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getActual();
	while (aux)
	{
		aux->_visitado = false;
		_listaDeAyacencia->siguiente();
		aux = (Vertice*)_listaDeAyacencia->getActual();
	}
}

void Grafo::despintar()
{
	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getActual();
	while (aux)
	{
		aux->color = 0;
		_listaDeAyacencia->siguiente();
		aux = (Vertice*)_listaDeAyacencia->getActual();
	}
}

void Grafo::borrarConexion(int pInicio, int pFin, int pPeso)
{

	Vertice* inicio = (Vertice*)_listaDeAyacencia->buscar(pInicio);
	Vertice* fin = (Vertice*)_listaDeAyacencia->buscar(pFin);
	ListaSimple* _admistradradorArcos2 = new ListaSimple();

	if (inicio != nullptr && fin != nullptr)
	{
		_admistradradorArcos->setPrimero(inicio->_conexiones);

		Arco* Conexion = _admistradradorArcos->buscarConexion(pPeso, inicio, fin);

		if (Conexion != NULL)
		{
			_admistradradorArcos->borrarConexion(Conexion);

			_admistradradorArcos->setPrimero(fin->_conexiones);
			Conexion = _admistradradorArcos->buscarConexion(pPeso, fin, inicio);
			_admistradradorArcos->borrarConexion(Conexion);

		}

	}
	else
		cout << "Alguno de los vertices no existe por favor agregelo" << endl;
}
/****************************************************Funciones para prim*********************************************************************/
void Grafo::algoritmoDePrim()
{
	//EscritorArchivo _escritor;
	
	//System::String^  Datos="Arbol de expasion minima\n";
	//_escritor.abrir(RUTARECORRIDOPALABRAS, true);
	


	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getActual();
	ListaSimple* conexiones = new ListaSimple();
	Grafo* ArbolExpMin = new Grafo();
	Arco* Conexionmenor;
	int Costo = 0;

	if (aux != NULL)
	{
		aux->_visitado = true;

		Conexionmenor = (Arco*)BuscarValorMin();
		if (Conexionmenor != NULL)
		{

			

			ArbolExpMin->agregarNodo(Conexionmenor->_incio);
			ArbolExpMin->agregarNodo(Conexionmenor->_fin);
			ArbolExpMin->agregarConexion(Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor, Conexionmenor->_peso, true);

			//Datos += "(Conexion :" + Conexionmenor->_incio->_valor + " - " + Conexionmenor->_fin->_valor + " Peso:"+ Conexionmenor->_peso + ") " + "\n";

			Costo += Conexionmenor->_peso;
			cout << endl;


			aux = (Vertice*)_listaDeAyacencia->buscarVertice(Conexionmenor->_fin);
			aux->_visitado = true;


			borrarConexion(Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor, Conexionmenor->_peso);

		}
		else
		{
			cout << "Ël primer nodo no tiene conexion";
		}
	}
	bool seguir = true;
	while (!TodosNodosVisitados())
	{

		Conexionmenor = (Arco*)BuscarValorMin();
		if (Conexionmenor != NULL)
		{
			ArbolExpMin->agregarNodo(Conexionmenor->_incio);
			ArbolExpMin->agregarNodo(Conexionmenor->_fin);
			ArbolExpMin->agregarConexion(Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor, Conexionmenor->_peso, true);

			Costo += Conexionmenor->_peso;

			aux = (Vertice*)_listaDeAyacencia->buscarVertice(Conexionmenor->_fin);
			aux->_visitado = true;



			borrarConexion(Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor, Conexionmenor->_peso);
			cout << "ArbolExp" << endl;
			ArbolExpMin->mostrarGrafo();
			ElimiarCiclo();
		}
	}
	cout << "ArbolExp" << endl;
	ArbolExpMin->mostrarGrafo();
	
	//Datos += "\n El costo total es de: " + Costo;

	//std::string DatosDeArbolExpMin = msclr::interop::marshal_as<std::string>(Datos);

	//_escritor.escribir(DatosDeArbolExpMin);
	//_escritor.cerrar();

	cout << "Costo" << endl;
	cout << Costo << endl;
}
Arco* Grafo::ConexionMenor(Vertice* vertice)
{
	ListaSimple* conexiones = new ListaSimple();

	conexiones->setPrimero(vertice->_conexiones);
	conexiones->primero();

	Arco* conexion = (Arco*)conexiones->getPrimero();
	Arco* Conexionmenor = conexion;

	if (!Arconulo(conexion))
	{
		while (conexion)
		{

			if (Conexionmenor->_peso >= conexion->_peso)
			{
				Conexionmenor = conexion;
			}

			conexiones->siguiente();
			conexion = (Arco*)conexiones->getActual();
		}

		return Conexionmenor;
	}
	else
	{
		return NULL;
	}
}

Arco* Grafo::BuscarValorMin()
{
	int num = 0;

	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getPrimero();

	Arco* Conexionmenor = new Arco(9999, NULL, NULL);

	while (num < _listaDeAyacencia->largoLista())//num menor que el largo de la lista de adya
	{
		if (aux->_visitado == true)
		{
			if (((Arco*)aux->_conexiones)->_peso != NULL)
			{
				Arco* ConexionVertice = (Arco*)ConexionMenor(aux);
				if (ConexionVertice != NULL)
				{

					if (ConexionVertice->_peso <= Conexionmenor->_peso)
					{
						Conexionmenor = ConexionVertice;
					}
					num++;
					_listaDeAyacencia->siguiente();
					aux = (Vertice*)_listaDeAyacencia->getActual();
				}
				else
				{
										num++;
					_listaDeAyacencia->siguiente();
					aux = (Vertice*)_listaDeAyacencia->getActual();

				}
			}
			else
			{
				num++;
				_listaDeAyacencia->siguiente();
				aux = (Vertice*)_listaDeAyacencia->getActual();
			}
		}
		else
		{
			num++;
			_listaDeAyacencia->siguiente();
			aux = (Vertice*)_listaDeAyacencia->getActual();
		}
	}
	if (Conexionmenor->_incio == NULL)
	{
		return NULL;
	}
	else
	{
		return Conexionmenor;
	}
}


bool  Grafo::Arconulo(Arco* arco)
{
	if (arco != NULL)
	{

		if (arco->_incio == NULL || arco->_fin == NULL || arco->_peso == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

bool Grafo::TodosNodosVisitados()
{
	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getPrimero();
	while (aux != NULL)
	{
		if (aux->_visitado == false)
		{
			return false;
		}
		else
		{
			aux = (Vertice*)aux->_siguiente;
		}


	}
	return true;
}

void Grafo::ElimiarCiclo()
{
	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getPrimero();
	while (aux)
	{
		if (aux->_visitado == true)
		{
			VerConexiones(aux);
			aux = (Vertice*)aux->_siguiente;
		}
		else
		{
			aux = (Vertice*)aux->_siguiente;
		}
	}
}
void Grafo::VerConexiones(Vertice* vertice)
{
	ListaSimple* conexiones = new ListaSimple();
	conexiones->setPrimero(vertice->_conexiones);

	Arco* conexion = (Arco*)conexiones->getPrimero();

	while (conexiones != NULL)
	{

		if (!Arconulo(conexion))
		{
			if (conexion->_fin->_visitado == true)
			{

				borrarConexion(conexion->_incio->_valor, conexion->_fin->_valor, conexion->_peso);
				conexiones->siguiente();
				conexion = (Arco*)conexiones->getActual();

			}
			else
			{
				conexiones->siguiente();
				conexion = (Arco*)conexiones->getActual();

			}
		}
		else
		{
			break;
		}
	}
}



/*****************************************************Terminan la funciones para prim********************************************************/
/**************************************************** Funciones para Kruskal****************************************************************/

void Grafo::algoritomoDeKruskal()
{
	ListaSimple* ListaArcos = new ListaSimple();
	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getPrimero();
	ListaSimple* conexiones = new ListaSimple();
	
	Grafo* ArbolExpMin = new Grafo();
	Arco* Conexionmenor;
	
	list<int> ListaVerticesConectados[11];
	bool HayConexion = false;
	int Costo = 0;
	
	//EscritorArchivo _escritor;

	//System::String^  Datos="Conexiones menores\n";
	//_escritor.abrir(RUTARECORRIDOPALABRAS, true);

	if (aux != NULL)
	{

		//Recorre el arbol y ordena las conexiones de mayo a menor
		Conexionmenor = (Arco*)VerticeMinConexion();
		while (Conexionmenor != NULL)
		{

			Arco* NuevaConexion = new Arco(Conexionmenor->_peso, Conexionmenor->_incio, Conexionmenor->_fin);

			ListaArcos->insertarFinal(NuevaConexion);

			//Datos += "(Conexion :" + NuevaConexion->_incio->_valor + " - " + NuevaConexion->_fin->_valor + " Peso:" + NuevaConexion->_peso + ") " + "\n";

			borrarConexion(Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor, Conexionmenor->_peso);

			Conexionmenor = (Arco*)VerticeMinConexion();
		}

		//System::String^  Datos = "\n Arbol de Expasion minima";

		ListaArcos->primero();
		Conexionmenor = (Arco*)ListaArcos->getActual();

		//Aragarra la primer conexio, ve en la lista de nodos entrelazados, si estan los nodos si estan
		while (Conexionmenor != NULL)
		{
			HayConexion = Siconexion(ListaVerticesConectados, Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor);


			if (HayConexion)
			{

				ArbolExpMin->agregarNodo(Conexionmenor->_incio);
				ArbolExpMin->agregarNodo(Conexionmenor->_fin);
				ArbolExpMin->agregarConexion(Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor, Conexionmenor->_peso, true);

				//Datos += "(Conexion :" + Conexionmenor->_incio->_valor + " - " + Conexionmenor->_fin->_valor + " Peso:" + Conexionmenor->_peso + ") " + "\n";

				Costo += Conexionmenor->_peso;


				aux = (Vertice*)_listaDeAyacencia->buscarVertice(Conexionmenor->_incio);
				aux->_visitado = true;

				aux = (Vertice*)_listaDeAyacencia->buscarVertice(Conexionmenor->_fin);
				aux->_visitado = true;


				ListaArcos->NEXT();

				Conexionmenor = (Arco*)ListaArcos->getActual();
				//cout << "ArbolEXp" << endl;
				//ArbolExpMin->mostrarGrafo();
			}

			else
			{
				ListaArcos->NEXT();
				Conexionmenor = (Arco*)ListaArcos->getActual();
			}
		}
		cout << "ArbolEXp" << endl;
		ArbolExpMin->mostrarGrafo();
		cout << "Costo" << endl;
		cout << Costo << endl;

		//Datos += "\n El costo total es de: " + Costo;

		//std::string DatosDeArbolExpMin = msclr::interop::marshal_as<std::string>(Datos);

		//_escritor.escribir(DatosDeArbolExpMin);
		//_escritor.cerrar();
	}
}

bool Grafo::Siconexion(list<int> ListaVerticesConectados[11], int inicio, int fin)
{


	bool EstaInicio = false;
	bool EstaFinal = false;

	int k = 0;
	while (k < 11)
	{
		if (Esta(ListaVerticesConectados, inicio, k))
		{
			EstaInicio = true;
			break;
		}
		k++;
	}
	int m = 0;
	while (m < 11)
	{
		if (Esta(ListaVerticesConectados, fin, m))
		{
			EstaFinal = true;
			break;
		}
		m++;
	}

	if (EstaInicio && EstaFinal)
	{
		if (m == k)
		{
			return false;
		}
		else
		{
			if (m < k)
			{
				ListaVerticesConectados[m].sort();
				ListaVerticesConectados[k].sort();
				ListaVerticesConectados[m].merge(ListaVerticesConectados[k]);
				return true;
			}
			else
			{
				ListaVerticesConectados[m].sort();
				ListaVerticesConectados[k].sort();
				ListaVerticesConectados[k].merge(ListaVerticesConectados[m]);
				return true;
			}
		}
	}
	else
	{
		if (EstaInicio || EstaFinal)
		{
			if (EstaInicio)
			{
				ListaVerticesConectados[k].push_back(fin);
				return true;
			}
			else
			{
				ListaVerticesConectados[m].push_back(inicio);

				return true;
			}
		}
		else
		{
			AgregarAPosVacia(ListaVerticesConectados, inicio, fin);
			return true;
		}

	}
}

void Grafo::AgregarAPosVacia(list<int> ListaVerticesConectados[11], int inicio, int fin)
{

	int k = 0;
	while (k < 11)
	{
		if (ListaVerticesConectados[k].empty())
		{
			ListaVerticesConectados[k].push_back(inicio);
			ListaVerticesConectados[k].push_back(fin);
			break;
		}
		k++;
	}
}


bool Grafo::Esta(list<int> ListaVerticesConectados[11], int valor, int pos)
{
	list<int>::iterator i;
	for (i = ListaVerticesConectados[pos].begin(); i != ListaVerticesConectados[pos].end(); ++i)
	{
		cout << *i << endl;

		if ((int)*i == (int)valor)
		{
			return true;
		}
	}
	return false;
}


Arco* Grafo::VerticeMinConexion()
{
	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getPrimero();

	Arco* Conexionmenor = new Arco(9999, NULL, NULL);

	while (aux != NULL)//num menor que el largo de la lista de adya
	{
		Arco* ConexionVertice = (Arco*)ConexionMenor(aux);

		if (((Arco*)aux->_conexiones)->_peso != NULL)
		{

			if (ConexionVertice->_peso <= Conexionmenor->_peso)
			{
				Conexionmenor = ConexionVertice;
			}

			_listaDeAyacencia->siguiente();
			aux = (Vertice*)_listaDeAyacencia->getActual();
		}
		else
		{
			_listaDeAyacencia->siguiente();
			aux = (Vertice*)_listaDeAyacencia->getActual();
		}
	}
	if (Conexionmenor->_incio != NULL)
	{

		cout << Conexionmenor->_incio->_valor << "-";
		cout << Conexionmenor->_fin->_valor << "-";
		cout << Conexionmenor->_peso << endl;
		return Conexionmenor;
	}
	else
	{
		return NULL;
	}

}
