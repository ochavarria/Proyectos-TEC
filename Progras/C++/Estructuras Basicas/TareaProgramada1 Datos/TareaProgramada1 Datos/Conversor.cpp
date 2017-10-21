//Header del archivo
#ifndef DEFCONVERSOR
#define DEFCONVERSOR

//Librerias incluidas
#include <string>
#include "sstream"

using std::string;
using std::ostringstream;
using std::stoi;
using std::stof;

class Conversor
{
public:
	//Metodo que convierte un string a int 
	int stringToInt(string pString)
	{
		return stoi(pString);
	}
	//Metodo que convierte un string a float 
	float stringToFloat(string pString)
	{
		return stof(pString);
	}
	//Metodo que da el valor ascii de un string 
	int obtenerASCII(string pString)
	{
		int resultado = 0;
		char *listadechar = new char[pString.length() + 1];

		strcpy_s(listadechar, pString.length() + 1, pString.c_str());

		resultado = (int)listadechar[0];

		delete listadechar;

		return resultado;
	}
	//Metodo que convierte un int a string 
	string intToString(int pInt)
	{
		string resultado;
		ostringstream lineastream;
		lineastream << pInt;
		resultado= lineastream.str();
		return resultado;
	}
	//Metodo que convierte un float a string 
	string floatToString(float pFloat)
	{
		string resultado;
		ostringstream lineastream;
		lineastream << pFloat;
		resultado = lineastream.str();
		return resultado;
	}


private:

};

#endif