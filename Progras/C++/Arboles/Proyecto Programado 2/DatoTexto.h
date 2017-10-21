#pragma once

#include <string>
using  std::string;


class DatoTexto 
{
public:
	DatoTexto()
	{
		palabra="";
		separacionatras = "";
		repeticion = 0;
	}

	string palabra;
	string separacionatras ;
	int repeticion;
};
