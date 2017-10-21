#pragma once

#include <string>
#include <fstream>

using std::string;
using std::fstream;

class AdministradorArchivo
{
public:

	bool error;

	void cerrar();

	bool estaAbierto();

protected:

	fstream _administrador;

};
