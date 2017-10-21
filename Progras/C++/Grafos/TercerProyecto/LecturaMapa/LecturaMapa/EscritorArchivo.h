#ifndef DEFESCRITORARCHIVO
#define DEFESCRITORARCHIVO

#include "AdministradorArchivo.h"

class EscritorArchivo : public AdministradorArchivo
{
public:

	void abrir(string pRuta, bool pSobrescitura=true);

	void escribir(string pDato);

};

#endif