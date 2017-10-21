#include "Grafo.h"
#include "Cola.h"
#include "Pila.h"


Grafo::Grafo()
{
	_listaDeAyacencia = new ListaSimple();
	_admistradradorArcos = new ListaSimple();
}
//Metodos Publicos
void Grafo::agregarConexion(string pInicio, string pFin, int pPeso,bool doble)
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
void Grafo::borrarConexion(string pInicio, string pFin, int pPeso)
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

void Grafo::agregarNodo(string pDato)
{
	Vertice* nuevo = (Vertice*)_listaDeAyacencia->buscar(pDato);
	if(nuevo==nullptr)
	{
		nuevo = new Vertice(pDato);
		_listaDeAyacencia->insertarFinal(nuevo);
	}
	//else
		//cout<<"El vertice ya existe"<<endl;
}

void Grafo::recorrido(int tipo)
{
	Pila pila;
	Cola cola;

	ListaSimple* conexiones = new ListaSimple();
	ListaSimple* visitados = new ListaSimple();

	_listaDeAyacencia->primero();

	Vertice* primero = (Vertice*)_listaDeAyacencia->getActual();
	Vertice* vertice = new Vertice(primero->_valor);
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
			conexiones->primero();
			Arco* conexion = (Arco*)conexiones->getActual();
			while(conexion)
			{
				if(!visitados->buscar(conexion->_fin->_valor))
				{
					vertice = new Vertice(conexion->_fin->_valor);
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
	_listaDeAyacencia->primero();
	Vertice* aux = (Vertice*)_listaDeAyacencia->getActual();
	ListaSimple* conexiones = new ListaSimple();
	while(aux)
	{
		cout<<aux->_valor<<endl;
		
		conexiones->setPrimero(aux->_conexiones);
		conexiones->primero();

		Arco* conexion = (Arco*)conexiones->getActual();
		while(conexion)
		{
			cout<<"(Conexion :"<<conexion->_incio->_valor<<" - "<<conexion->_fin->_valor<<" Peso:"<<conexion->_peso<<") "<<endl;
			conexiones->siguiente();
			conexion = (Arco*)conexiones->getActual();
		}
		cout<<endl;
		_listaDeAyacencia->siguiente();
		aux = (Vertice*)_listaDeAyacencia->getActual();
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
/****************************************************Funciones para prim*********************************************************************/
void Grafo::algoritmoDePrim()
{
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



			ArbolExpMin->agregarNodo(Conexionmenor->_incio->_valor);
			ArbolExpMin->agregarNodo(Conexionmenor->_fin->_valor);
			ArbolExpMin->agregarConexion(Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor, Conexionmenor->_peso, true);
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
		if (Conexionmenor!=NULL)
		{
			ArbolExpMin->agregarNodo(Conexionmenor->_incio->_valor);
			ArbolExpMin->agregarNodo(Conexionmenor->_fin->_valor);
			ArbolExpMin->agregarConexion(Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor, Conexionmenor->_peso, true);

			Costo += Conexionmenor->_peso;

			aux = (Vertice*)_listaDeAyacencia->buscarVertice(Conexionmenor->_fin);
			aux->_visitado = true;

			cout << "Ultimo Nodo Visitado --"<<aux->_valor <<endl;

			borrarConexion(Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor, Conexionmenor->_peso);
			cout << "ArbolExp" << endl;
			//ArbolExpMin->mostrar();
			ElimiarCiclo();
		}
	}
	cout << "ArbolExp" << endl;
	ArbolExpMin->mostrar();
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
	
		if (!Arconulo(conexion) )
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
	list<string> ListaVerticesConectados[11];
	bool HayConexion=false;
	int Costo = 0;
	if (aux != NULL)
	{

		//Recorre el arbol y ordena las conexiones de mayo a menor
		Conexionmenor = (Arco*)VerticeMinConexion();
		while (Conexionmenor != NULL)
		{

			Arco* NuevaConexion = new Arco(Conexionmenor->_peso, Conexionmenor->_incio, Conexionmenor->_fin);

			ListaArcos->insertarFinal(NuevaConexion);

			borrarConexion(Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor, Conexionmenor->_peso);

			Conexionmenor = (Arco*)VerticeMinConexion();
		}
		ListaArcos->primero();
		Conexionmenor = (Arco*)ListaArcos->getActual();

		//Aragarra la primer conexio, ve en la lista de nodos entrelazados, si estan los nodos si estan
		while (Conexionmenor != NULL)
		{
			HayConexion = Siconexion(ListaVerticesConectados, Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor);


			if (HayConexion)
			{

				ArbolExpMin->agregarNodo(Conexionmenor->_incio->_valor);
				ArbolExpMin->agregarNodo(Conexionmenor->_fin->_valor);
				ArbolExpMin->agregarConexion(Conexionmenor->_incio->_valor, Conexionmenor->_fin->_valor, Conexionmenor->_peso, true);
				Costo += Conexionmenor->_peso;


				aux = (Vertice*)_listaDeAyacencia->buscarVertice(Conexionmenor->_incio);
				aux->_visitado = true;

				aux = (Vertice*)_listaDeAyacencia->buscarVertice(Conexionmenor->_fin);
				aux->_visitado = true;


				ListaArcos->NEXT();

				Conexionmenor = (Arco*)ListaArcos->getActual();
				//cout << "ArbolEXp" << endl;
				//ArbolExpMin->mostrar();
			}

			else
			{
				ListaArcos->NEXT();
				Conexionmenor = (Arco*)ListaArcos->getActual();
			}
		}
		cout << "ArbolEXp" << endl;
		ArbolExpMin->mostrar();
		cout << "Costo" << endl;
		cout << Costo << endl;
	}
}

bool Grafo::Siconexion(list<string> ListaVerticesConectados[11], string inicio, string fin)
{


	bool EstaInicio=false;
	bool EstaFinal=false;

	int k = 0;
	while (k < 11)
	{
		if (Esta(ListaVerticesConectados,inicio,k))
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

void Grafo::AgregarAPosVacia(list<string> ListaVerticesConectados[11], string inicio, string fin)
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


bool Grafo::Esta(list<string> ListaVerticesConectados[11], string valor,int pos)
{
	list<string>::iterator i;
	for (i = ListaVerticesConectados[pos].begin(); i != ListaVerticesConectados[pos].end(); ++i)
	{
		cout << *i << endl;

		if ((string)*i == (string)valor)
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












































