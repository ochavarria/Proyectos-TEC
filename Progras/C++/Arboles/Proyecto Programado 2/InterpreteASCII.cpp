#include "InterpreteASCII.h"

//Busca encasillar el codigoascii del char envido para saber si es numero o letra
bool InterpreteASCII::esReconocido(char pDato)
{
	int codigoASCII = (int)pDato;

	if (codigoASCII >= 97 && codigoASCII <= 122)
		return true;
	else
	{
		if (codigoASCII >= 48 && codigoASCII <= 57)
			return true;
		else
			return false;
	}
}
//Usando un switch compara el codigo ascii con los de los signos de puntacion
bool InterpreteASCII::esPuntuacion(char pDato)
{
	int codigoASCII = (int)pDato;
	switch (codigoASCII)
	{
	case COMA:
		return true;
		break;
	case DOSPUNTOS:
		return true;
		break;
	case PUNTO:
		return true;
		break;
	case ESPACIO:
		return true;
		break;
	default:
		return false;
		break;
	}

}
//Para efectos del programa el separado es el punto y coma
bool InterpreteASCII::esSeparador(char pDato)
{
	int codigoASCII = (int)pDato;
	if (codigoASCII == PUNTOYCOMA)
		return true;
	else
		return true;
}