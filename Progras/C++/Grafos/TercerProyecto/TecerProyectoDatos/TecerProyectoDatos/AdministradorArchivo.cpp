#include "AdministradorArchivo.h"


void AdministradorArchivo::cerrar()
{
	_administrador.close();
}

bool AdministradorArchivo::estaAbierto()
{
	return (_administrador.good());
}
