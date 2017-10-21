#include "Conversor.h"

//Metodos Publicos
int Conversor::stringToInt(string pString)
{
	return stoi(pString);
}

float Conversor::stringToFloat(string pString)
{
	return stof(pString);
}

int Conversor::obtenerASCII(string pString)
{
	int resultado = 0;
	char* listadechar = new char[pString.length() + 1];

	strcpy_s(listadechar, pString.length() + 1, pString.c_str());

	resultado = (int)listadechar[0];

	delete listadechar;

	return resultado;
}

string Conversor::intToString(int pInt)
{
	string resultado;
	ostringstream lineastream;
	lineastream << pInt;
	resultado = lineastream.str();
	return resultado;
}

string Conversor::RojoNegro(bool Rojo)
{
	if (Rojo){ return "Rojo";}
	else{ return "Negro"; }

}

string Conversor::floatToString(float pFloat)
{
	string resultado;
	ostringstream lineastream;
	lineastream << pFloat;
	resultado = lineastream.str();
	return resultado;
}
