//Librerias incluidas
#include <iostream>
#include "LectorArchivo.cpp"
#include "ListaSimple.cpp"
#include "Cola.cpp"
#include "Pila.cpp"
#include "Conversor.cpp"
#include "InterpreteASCII.cpp"
#include "Evaluador.cpp"

class Principal
{
public:

	//Metodo que dice si la cola esta vacia
	bool esElFinal()
	{
		return _colaExpresionesPrefijo.colaVacia();
	}

	// Metodo que lee el archivo y mete el primer digito leido en una cola de 5 elementos y luego crea una lista con los demas elementos
	bool cargarExpPrefijo(Archivo *archivo)
	{
		_LectorArchivo.cambioArchivo(archivo);
		inicializar();
		string segmentoleido = _LectorArchivo.leerDigito();
		if (!_LectorArchivo.errorLectura)
		{
			_colaExpresionesPrefijo.insertar(segmentoleido);
			pNodo Primero = _colaExpresionesPrefijo.Extraer();
			_listaManejoCola.setPrimero(Primero);
			while (!_LectorArchivo.errorLectura && !_LectorArchivo.fin)
			{
				segmentoleido = _LectorArchivo.leerDigito();
				if (segmentoleido != "")
				{
					_listaManejoCola.insertarFinal(segmentoleido);
				}
			}
			return true;
		}
		else
			return false;
	}

	//Metodo que llama otros metodos para crear las expresiones 
	void operar()
	{
		_listaManejoCola.setPrimero(_colaExpresionesPrefijo.Extraer());
		creacionExpPostFija();
		string resultado = evaluarPostFijo();
		//Imprimir
		cout << "Expresion Prefija" << endl;
		_listaManejoCola.mostrar();
		cout << "Expresion Postfija" << endl;
		_expresionPostFija.mostrar();
		cout << "El Resultado de la expresion es: " << resultado << endl << endl;
		//Eliminar Archivo ya Utilizado
		_colaExpresionesPrefijo.eliminar();
		_expresionPostFija.~ListaSimple();
	}



// Atributos de la clase
private:
	Cola _colaExpresionesPrefijo;
	ListaSimple _listaManejoCola;
	ListaSimple _expresionPostFija;
	LectorArchivo _LectorArchivo;

	InterpreteASCII _interprete;
	Conversor _conversor;
	Evaluador _evaluador;

	//Metodo que inicializa algunas validaciones
	void inicializar()
	{
		_LectorArchivo.errorLectura = false;
		_LectorArchivo.fin = false;
		_evaluador.divisionPorCero = false;
		_evaluador.error = false;
	}

	//Metodo que crea la Expresion post fija
	void creacionExpPostFija()
	{
		Pila pila;
		_listaManejoCola.primero();
		while (_listaManejoCola.getValorActual() != "")
		{
			int valor = _conversor.obtenerASCII(_listaManejoCola.getValorActual());
			if (_interprete.esNumero(valor))
			{
				_expresionPostFija.insertarFinal(_listaManejoCola.getValorActual());
				_listaManejoCola.siguiente();

			}
			else
			{
				if (_listaManejoCola.getValorActual() == ")")
				{
					vaciarPila(pila, false);
					_listaManejoCola.siguiente();
				}

				else
				{
					if (pila.pilaVacia())
					{
						pila.push(_listaManejoCola.getValorActual());
						_listaManejoCola.siguiente();
					}
					else
					{
						int _valorEnPila = _evaluador.PrioridadEnPila(pila.getTope(), true);
						int _valorFueraDePila = _evaluador.PrioridadEnPila(_listaManejoCola.getValorActual(), false);

						if (_valorEnPila >= _valorFueraDePila)
						{
							while (_valorEnPila >= _valorFueraDePila)
							{
								_expresionPostFija.insertarFinal(pila.getTope());
								pila.pop();
								if (!pila.pilaVacia())
									_valorEnPila = _evaluador.PrioridadEnPila(pila.getTope(), true);
								else
									break;
							}
							pila.push(_listaManejoCola.getValorActual());
							_listaManejoCola.siguiente();
						}
						else
						{
							pila.push(_listaManejoCola.getValorActual());
							_listaManejoCola.siguiente();

						}
					}
				}
			}
		}
		vaciarPila(pila, true);
	}

	//Metodo que evalua la expresion post fija
	string evaluarPostFijo()
	{
		Pila pilaEvaluacion;
		_expresionPostFija.primero();
		if (_expresionPostFija.getValorActual() != "")
		{
			while (_expresionPostFija.getValorActual() != "")
			{
				int valor = _conversor.obtenerASCII(_expresionPostFija.getValorActual());
				if (_interprete.esNumero(valor))
				{
					pilaEvaluacion.push(_expresionPostFija.getValorActual());
					_expresionPostFija.siguiente();
				}
				else
				{
					string operando2 = pilaEvaluacion.getTope();
					pilaEvaluacion.pop();
					string operando1 = pilaEvaluacion.getTope();
					pilaEvaluacion.pop();
					string resultado = _evaluador.evaluar(valor, operando1, operando2);
					if (_evaluador.error)
					{
						break;
					}
					pilaEvaluacion.push(resultado);
					_expresionPostFija.siguiente();
				}
			}
			if (_evaluador.divisionPorCero)
				return "Error Division por Cero";
			else
				return pilaEvaluacion.getTope();
		}
		else
			return "Error en ExpresionPostFija";
	}

	//Metodo que vacia la pila y la agrega a la expresion post fija
	void vaciarPila(Pila &pila, bool toda)
	{
		while (!pila.pilaVacia())
		{
			string tope = pila.getTope();
			pila.pop();

			if (tope != "(")
			{
				_expresionPostFija.insertarFinal(tope);
			}
			else
			{
				if (!toda)
					break;
			}

		}
	}
};

