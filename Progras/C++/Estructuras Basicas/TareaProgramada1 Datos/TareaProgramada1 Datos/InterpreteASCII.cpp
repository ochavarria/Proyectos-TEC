//Header del archivo
#ifndef DEFINTERPRETE
#define DEFINTERPRETE

//Librerias incluidas
#include <string>
#include "Constantes.cpp"
using namespace std;

class InterpreteASCII
{
public:
	// Busca si el valor ascii enviado se encuentra entre el valor de los numeros
	bool esNumero(int pValor) 
	{
		bool resultado = false;
		if (48 <= pValor && pValor <= 57)
			resultado = true;
		return resultado;
	}

	// Busca si el valor ascii enviado se encuentra entre el valor de los simbolos de los operadores usados
	bool esOperador(int pValor)
	{
		bool resultado = false;
		if (pValor == OPERADORES::RESTA || pValor == OPERADORES::DIVISION || pValor == OPERADORES::POTENCIA || (OPERADORES::PARENTECISIZQ <= pValor && pValor <= OPERADORES::SUMA))
			resultado = true;
		return resultado;
	}

	// Busca si el valor ascii enviado es un espacio o un linea final
	bool esDesechable(int pValor)
	{
		bool resultado = false;
		if (pValor == 10 || pValor ==32)
			resultado = true;
		return resultado;
	}

private:
	friend class Principal; 
};

#endif
