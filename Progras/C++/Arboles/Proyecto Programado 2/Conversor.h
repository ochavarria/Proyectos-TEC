#pragma once

#include <string>
#include "sstream"

using std::string;
using std::ostringstream;
using std::stoi;
using std::stof;

class Conversor
{
//Metodos
public:
	//Metodo que convierte un string a int 
	int stringToInt(string pString);

	//Metodo que convierte un string a float 
	float stringToFloat(string pString);

	//Metodo que da el valor ascii de un string 
	int obtenerASCII(string pString);

	//Metodo que convierte un int a string 
	string intToString(int pInt);

	//Metodo que convierte un float a string 
	string floatToString(float pFloat);
	//
	string RojoNegro(bool Rojo);
};