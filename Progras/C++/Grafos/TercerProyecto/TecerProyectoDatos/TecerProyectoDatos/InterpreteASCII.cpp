#include "InterpreteASCII.h"


bool InterpreteASCII::esCaracter(char pDato)
{
	int codigoASCII = pDato;

	if (codigoASCII >= 33 && codigoASCII <= 126)
		return true;
	else
		return false;
}

bool InterpreteASCII::esNumero(char pDato)
{
	int codigoASCII = pDato;

	if (codigoASCII >= 48 && codigoASCII <= 57 || codigoASCII ==45 )
		return true;
	else
		return false;

}

bool InterpreteASCII::esSeparador(char pDato)
{
	int codigoASCII = (int)pDato;
	if (codigoASCII == 77 || codigoASCII == 76 || codigoASCII == 67 || codigoASCII == 90 || codigoASCII ==108 || codigoASCII == 109 || codigoASCII == 122 || codigoASCII == 99)
		return true;
	else
		return true;
}