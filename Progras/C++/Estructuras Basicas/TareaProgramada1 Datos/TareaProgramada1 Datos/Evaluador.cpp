
//Librerias incluidas
#include "Conversor.cpp"
#include "Constantes.cpp"
#include <math.h>
#include <iostream>



class Evaluador
{
public:
	//Constructor de la clase Evaluador
	Evaluador()
	{
		error = false;
		divisionPorCero = false;

	}
	//Inicializacio de variables
	bool divisionPorCero;
	bool error;
	/*Metodo que evalua, tiene por entrada dos numeros y un operador, Tiene un switch que dependiendo del operador que ingrese
	hace una operacion diferente
	*/

	string evaluar(int pOperador, string pOperando1, string pOperando2)
	{
		_operador = pOperador;
		conversorInformacion(pOperando1, pOperando2);
		float resultado = 0;
		//switch
		switch (_operador)
		{
		//caso de la potencia
		case OPERADORES::POTENCIA:
			resultado = potencia(_operando1, _operando2);
			break;
		//caso de la multiplicacion
		case OPERADORES::MULTIPLICACION:
			resultado = multiplicacion(_operando1, _operando2);
			break;
		//caso de la division
		case OPERADORES::DIVISION:
			if (_operando2 != 0)
			{
				resultado = division(_operando1, _operando2);
			}
			else
			{
				error = true;
				divisionPorCero = true;
			}
			break;
			//caso de la suma
		case OPERADORES::SUMA:
			resultado = suma(_operando1, _operando2);
			break;
		//caso de la resta
		case OPERADORES::RESTA:
			resultado = resta(_operando1, _operando2);
			break;
		//En caso de que el operador sea erroneo
		default:
			error = true;
			break;
		}
		return _conversor.floatToString(resultado);
	}
	//Funcion que hace la suma con ambos numeros 
	float suma(float pOperando1, float pOperando2)
	{
		return (pOperando1 + pOperando2);
	}
	//Funcion que hace la resta de ambos numeros 
	float resta(float pOperando1, float pOperando2)
	{
		return (pOperando1 - pOperando2);
	}
	//Funcion que hace la multiplicacion con ambos numeros 
	float multiplicacion(float pOperando1, float pOperando2)
	{
		return (pOperando1*pOperando2);
	}
	//Funcion que hace la division de ambos numeros 
	float division(float pOperando1, float pOperando2)
	{
		return (pOperando1/pOperando2);
	}
	//Funcion que eleva el operando1 a la operando2
	float potencia(float pOperando1, float pOperando2)
	{
		return pow(pOperando1,pOperando2);
	}
	//Metodo que evalua la prioridad de los operandos en la pila y fuera da ella
	int PrioridadEnPila(string operador,bool dentrodelapila)
	{
		_operador= _conversor.obtenerASCII(operador);
		int valor=0;
		switch (_operador)
		{
		case OPERADORES::SUMA:
			valor = 1;
			break;
		case OPERADORES::RESTA:
			valor=1;
			break;
		case OPERADORES::MULTIPLICACION:
			valor = 2;
			break;
		case OPERADORES::DIVISION:
			valor = 2;
			break;
		case OPERADORES::POTENCIA:
			if (dentrodelapila)
				valor = 3;
			else
				valor=4;
			break;
		default:
			if (dentrodelapila)
				valor = 0;
			else
				valor = 5;
		}
		return valor;
	}
//Atributos de la clase
private:
	float _operando1;
	float _operando2;
	int _operador;
	Conversor _conversor;
// Convierte los operandos a float
	void conversorInformacion(string pOperando1, string pOperando2)
	{
		_operando1 = _conversor.stringToFloat(pOperando1);
		_operando2 = _conversor.stringToFloat(pOperando2);
		
	}
	
};

